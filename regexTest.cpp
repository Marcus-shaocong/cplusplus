#include <string>
#include <boost/regex.hpp>
#include <iostream>
using namespace std;
int main()
{
  const boost::regex  r("^auto_ext\\s+=\\s+(.+),thin=(.+)$");
  string testStr = "auto_ext  = no,thin=no";
  string testStr2 = "auto_ext  = hwm=90%,max_size=2048M,thin=yes";
  const boost::regex  r1("^auto_ext\\s+=\\s+(.+)thin=(.+)$");
  boost::smatch m;
  if (boost::regex_search(testStr2, m, r1))
  {
      cout<<m[0]<<" " <<endl<<m[1]<<endl; 
      cout<<m[2]<<" " <<endl;
      if( m[2] == "yes" )
      {
        cout <<"It is thin fs"<<endl; 
      }
      else if( m[2] == "no" )
      {
        cout <<"It is thick fs"<<endl; 
      
      }
  }
  return 0;
}
