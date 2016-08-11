#!/bin/bash
#set -x 
declare WS_PATH2="/home/c4dev/wsdm02"
declare WS_PATH="/home/c4dev/dmws01"

echo "hello world";
step=1

detect_image()
{
  breakWhile=0
  while true
  do
    if ls $WS_PATH/output/image/GNOSIS_DEBUG/OS* 1> /dev/null 2>&1; then
      echo "files do exist"
      breakWhile=1
    else
      echo "files do not exist"
      sleep 600 
    fi
    if [ $breakWhile == 1 ]
    then
      break
    fi
  done
}


function localExec
{
  local CMD="$1"
  echo The command to run: $CMD
  expect  <<EOF
set timeout -1
  spawn $CMD
  expect {
  -gl "):" {
  send "3\r"
  expect eof
  }
  "*password:" {
  send "nasadmin\r"
  expect eof
  }
}
EOF
}

logStep ()
{
  echo step $step: $1

  step=$((step+1))
}

is_sp_alive()
{
#HOSTS="10.108.49.169"
HOSTS=$1
COUNT=1
for myHost in $HOSTS
do
  count=$(ping -c $COUNT $myHost | grep 'received' | awk -F',' '{ print $2 }' | awk '{ print $1 }')
  echo "count is $count"
  if [ $count -eq 0 ]; then
    # 100% failed 
    echo "Host : $myHost is down (ping failed) at $(date)"
    return 5 
  else
    echo "Host : $myHost is alive (ping success $count) at $(date)"
    return 0
  fi
done

}


usage ()
{
  echo "Usage : $0 <sim_ip>"
  exit
}

if [ "$#" -ne 1 ]
then
  usage
fi

echo "deplay $1" 
detect_image 

while true 
do
  is_sp_alive $1
  if [ $? != 0 ]; then
    echo "sp down"
  else
    echo "sp alive "
    break
  fi
done

echo "Copying the image to destination"
scp $WS_PATH/output/image/GNOSIS_DEBUG/OS* root@$1:~ 


echo "Start install the image"
ssh root@$1 "/root/OS* -- --reinit"

while true 
do
  is_sp_alive $1
  if [ $? != 0 ]; then
    echo "sp down"
  else
    echo "sp alive "
    break
  fi
done
sleep 5

retVal=""
while [ "$retVal" =  "" ] 
do
  sleep 100 
  retVal=$( ssh root@$1 "pidof ECOM" )
  if [ "$retVal" != "" ]
  then
    echo "ECOM is up, id: $retVal"
    break
  else
    echo "ECOM is still down" 
  fi
done

localExec "ssh root@$1 \"uemcli -u admin -p Password123# /sys/eula set -agree yes\""
logStep  "set up account:"
ssh root@$1 "uemcli -u admin -p Password123# /user/account -id user_admin  set -passwd Password123! -oldpasswd Password123#"
logStep  "mount c4share"
ssh root@$1 "mkdir /c4shares; mount -t nfs c4shares.sspg.lab.emc.com:/c4shares /c4shares"

logStep  "upload license:"
ssh root@$1 "uemcli -u admin -p Password123! -upload -f /c4shares/Public/license/license-any-host-falcon-cs.lic license"
#ssh root@$1 "uemcli -u admin -p Password123! -upload -f /c4shares/Public/license/Thunderbird/license-any-host-tb-458-001-288-DARE.lic license"
logStep  "create pool"
#ssh root@$1 "uemcli -u admin -p Password123! /stor/config/pool create -diskGroup dg_18 -drivesNumber 7 -name pool_1 -descr Pool_1 -alertThreshold 80"
ssh root@$1 "uemcli -u admin -p Password123! /stor/config/pool create -diskGroup dg_18 -drivesNumber 2 -storProfile profile_30 -name pool_1"
ssh root@$1 "uemcli -u admin -p Password123! /stor/config/pool create -diskGroup dg_18 -drivesNumber 2 -storProfile profile_30 -name pool_2"

ssh root@$1 "uemcli /mig/ssh create -name session1 -srcSysIp 10.108.124.116 -srcSysUsername nasadmin -srcSysPassword nasadmin"

ssh root@$1 "uemcli -u admin -p Password123!  /net/if create -type replication -port spa_iom_0_eth1 -addr 10.108.49.155 -netmask 255.255.248.0 -gateway 10.108.48.1"

logStep  "change the cp log level to DEBUG:"
ssh root@$1 "sed 's/INFO/DEBUG/' /EMC/CEM/conf/cemtracer.properties > /EMC/CEM/conf/cemtracer.properties.bak2 && mv /EMC/CEM/conf/cemtracer.properties.bak2 /EMC/CEM/conf/cemtracer.properties"
ssh root@$1 "echo \"alias recp='cf_ha_api.pl restart ECOM'\" >>  /root/.bashrc"

ssh root@$1 "echo \"alias opendb='psql uem_cp_usr -d uemcpdb'\" >> /root/.bashrc"
ssh root@$1 "echo \"alias cdlog='cd /EMC/CEM/log '\" >> /root/.bashrc"

ssh root@$1 "uemcli -u admin -p Password123! /mig/sess create -name migsess1 -srcSys migssh_1 -srcRes vdm_src -targetResPool pool_1 -targetPort spa_iom_0_eth1 -targetMbltIf if_3"

ssh root@$1 "uemcli -u admin -p Password123! /mig/sess -id migsession_1 start"
