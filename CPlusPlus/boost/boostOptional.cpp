//
// construction:
//  optional<T> fool;
//  optional<T> bar = instanceOfT;
//  optional<T> baz(anotherOptional);
//
//  Calling operator = 
//  with a value type: assigns the value
//  With a reference:(re)binds the wrapped reference
//  Works with another optional<> too
//
//  Getting the value
//  foo.get()   or *foo
//  Getting a pointer to the value
//  foo.get_ptr()
//  foo->member
//
//  ifa a value is missing all of the above generate an assertion failure
//  Is the value there?
//  foo.is_initialized()
//
//
//



#include <string>
#include <iostream>
#include <boost/optional.hpp>

using namespace std;
using namespace boost;
class Address
{
  public:
  string streetName;

  Address(const string & name)
    :streetName(name)
  {}
};

class Person
{
   public:
     Person(string firstName, string lastName)
       :firstName(firstName), lastName(lastName)
     {}
     string firstName, lastName;
     optional<string> middleName;
     optional<Address> address;

};

int main()
{
  Person p{"john", "watson"};
  
  p.middleName = "Hamish";
  p.middleName = "newName";
  if(p.middleName)
  {
    cout<<*p.middleName <<endl; 
  }

  p.address = Address{"istreet"};

  if(p.address)
  {
    cout<<p.address->streetName<<endl; 
  }
  return 0;

}



