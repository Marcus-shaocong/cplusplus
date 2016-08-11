

#include "Resource.hpp"
#include "Person.hpp"
#include <string>



//first version the pResource is a solid member, it can initialize as ""
/* Person::Person(string first, string last, int number) */
/*   :firstname{first}, lastname{last}, number{number},pResource("") */
/* { */

/* } */


//second version when the pResource is a unique_ptr, don't initialize it in 
//the constructor
Person::Person(string first, string last, int number)
  :firstname{first}, lastname{last}, number{number}
{

}

string Person::GetName() const
{
  return firstname + " " + lastname;
}

void Person::SetResource( string resourcename)
{
  //first version by copy construct the resource
 /*Resource temp = Resource(resourcename);
 pResource = temp;*/

  //second version by using the unique_pty 
  //pResource.reset(new Resource(resourcename));
  //three version by using the unique_pty 
  pResource = make_shared<Resource>(resourcename);
}



//version three, if we are uning the shared_ptr,
//we don't need to implement the copy assignment and copy constructor
//there are needed only we use the unique_ptr
/*
Person::Person(Person & r)
  :firstname{r.GetName()}, lastname{r.GetName()}, number{r.GetNumber()}
{
  pResource.reset(new Resource(r.GetResourceName()));

}

Person & Person::operator =(Person & r)
{
  firstname = r.firstname;
  lastname = r.lastname;
  number = r.number;
  pResource.reset(new Resource(r.GetResourceName()));
  return * this;
}*/
