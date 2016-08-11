#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <algorithm>
using namespace std;


enum abc
{
  ENUM_1 = 1,
};

string numToString (int x )
{
  stringstream ss;
  ss<<x;
  return ss.str();
}

struct Address
{
  string addr;
  Address(string addr_):addr(addr_){}
};

struct Person
{
  string name;
  Address *pAddr;
  Person(string name_) : name(name_), pAddr(nullptr){}
  Person(const Person & r) : name(r.name){}
  Person(Person && r){
    if(this != &r)
    {
      cout<<"move assignemnt"<<endl;
      name = "Marcus";
      r.name.clear();
    }
  }

};


vector<Person> && inc( vector<Person> a )
{
  for(auto i = begin(a); i != end(a); ++i)
  {
    (*i).name  = "Jerrry";
  }
  return move(a);
}

int main()
{
  
  /* std::string interface = "nas_migration"; */
  /* std::string abc = "_xxxnas_migration_if"; */
  /* std::string xya = "_xxx_ooo_oufs"; */

  /* int b = abc.find(interface); */
  /* cout<<" b is "<<b <<endl; */

  /* int c = xya.find(interface); */
  
  /* cout<<" c is "<<c <<endl; */
  
  
  
  
  /* const int num = 30; */
  /* srand(time(NULL)); */
  /* int x = rand() %1000 +1; */
  /* cout<<" random x is : "<<x<<endl; */
  /* vector<int> intArray; */
  /* for(int i=0; i<x; i++) */
  /*   intArray.push_back(i+1); */
 
  /* int i = 0; */
  /* int cout =0; */
  /* string tempStr; */
  /* while(i<x) */
  /* { */
  /*   cout++; */
  /*   tempStr += string(" " + numToString(i)); */
  /*   if(cout % 5 == 0 ) */
  /*   { */
  /*     tempStr.clear(); */ 
  /*   } */
  /*   i++; */
  /* } */
  /* if(!tempStr.empty()) */
  /* { */
  /* } */

   Person p{"marry"};
   vector<Person> x ;
   x.emplace_back(p);
   x.emplace_back(Person{"Geogre"});
   x.emplace_back(Person{"Jane"});
   x.emplace_back(Person{"ansin"});
   x.emplace_back(Person{"luoyuan"});
   x.emplace_back(Person{"xuning"});
   x.emplace_back(Person{"cleo"});

   vector<Person> b = inc(x);
  
   for(auto i = begin(b); i != end(b); ++i)
  {
    cout<<" " << (*i).name;
  }
   cout<<endl;


return 0;  
} 
