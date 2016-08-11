//
//
//
//
//
//boost::any<T>
//T can be anything
//T must be copy-constructable
//
//creation is easy
//
//any w;
//any x{2.0};
//vector<any> y{42, "file"};
//
//any z = string("test");
//
//
//Queries
//empty()
//checks if we have a value
//
//type()
//returns typeid of containing instance
//
//any_cast
//global function
//can pass either pointer or reference ot an instance of any
//
//
// g++ -std=c++0x BoostAny.cpp -o test -I /home/c4dev/nextUnityBugFix/uemcli/obj/KHDATAPATH_DEBUG/rpm_install/usr/include


#include <boost/any.hpp>
#include <string>
#include <iostream>
//#include <typeinfo>

using namespace std;
using namespace boost;

int main()
{
 any w;
 any x{2.0};
 vector<any> y{42,+"file"};
 any z = string("test");

 if(!x.empty())
 {
    cout<< x.type().name() <<endl; 
 }

 int a = any_cast<int>(y[0]);
 cout<<" The value is "<<a<<endl;

 try{
 
     int b = any_cast<int>(y[1]);
 }
 catch(const bad_any_cast & e)
 {
    cout<<"wrong type" <<endl; 
 }

 for(any a :y)
 {
    int * value = any_cast<int>(&a);
    if(value != nullptr)
      cout <<*value<<endl;

    const char** text = any_cast<const char*>(&a);
    if(text != nullptr)
      cout<<*text<<endl;
 }
return 0;
}
