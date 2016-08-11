#include "Resource.hpp"
#include "Person.hpp"
#include <iostream>
#include <string>

using namespace std;


int main()
{
  Person p("Jane", "jerry", 42);
  p.SetResource(" resource one");

  p.SetResource(" resource two");

  Person p2 = p; 
  p = p2;
  cout<< "resource name " << p.GetResourceName()<<endl;
  return 0;
}
