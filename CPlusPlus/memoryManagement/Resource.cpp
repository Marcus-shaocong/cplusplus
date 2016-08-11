#include "Resource.hpp"
#include <iostream>
#include <string>

Resource::Resource(string n): name{n}
{
  cout<<" construcing " << name << endl;
}


Resource::Resource(const Resource & r): name{r.name}
{
  cout<<" copy construcing " << name << endl;
}


Resource& Resource::operator = (const Resource & r)
{
  //if class contained treu Resource,
  //check for self assignment then clean up existing
  //resources before setting new values
  //
  name = r.GetName();
  cout<<" copy assigning " << name << endl;
  return *this;
}


Resource::~Resource(void)
{
  cout<<" destructing " << name << endl;
}


