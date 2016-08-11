#include "AccountImpl.hpp"

int AccountImpl::maxAccountNumUsed;

AccountImpl::AccountImpl(int bal, Customer* cust)
  :balance(bal), customer(cust),accountnum(++maxAccountNumUsed),log(accountnum)
{

}

int AccountImpl::Deposit(int amount)
{
  log.AddDeposit("today", amount);
  balance += amount;
  return balance;
}

int AccountImpl::Withdraw(int amount)
{
  log.AddWithDraw("today", amount);
  balance -= amount;
  return balance;
}
