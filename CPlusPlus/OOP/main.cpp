#include<iostream>
#include<typeinfo>
#include "Address.hpp"
#include "Person.hpp"
#include "Employee.hpp"


int main()
{
  /* Person p; */
  /* p.name = "Jane Doe"; */
  /* p.age = 30; */

  /* Person * pp = &p; */


  /* Person *p2 = new Person; */
  /* p2->age = 25; */
  /* p2->name = "john Doe"; */

  /* p2->greet(); */
  /* delete p2; */

  Person *p3 = new Person(44, "jacke", 24);
  auto * address = new Address(123, "paris", "string");

  p3->address = address;
  p3->greet();

  /* Person p4(*p3); */
  /* p3->address->city = "exeter"; */
  /* cout<<p4.address->city<<endl; */
  
  try{
    Employee * er2 = dynamic_cast<Employee*>(p3);
    cout<<er2->depart<<endl;
  }
  catch(const bad_cast &e)
  {
    cout << "cannot cast this"<<endl; 
  }

  return 0;
}
