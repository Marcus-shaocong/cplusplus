#include <iostream>

#include "Person.hpp"

using namespace std;
void Person::greet()
{
  cout<<"My name is " <<this->name << " and I am " << this->age << " years old." << endl;
  if(address)
  {
    cout<<" I live at "<< address->street_name<<endl; 
  
  }
}

int Person::getLifeExpectancy()
{
  return lifeExpectancy;
}

Person::Person( int age, string name, int sex)
  :age(age), name(name),sex(sex)
{
  address = nullptr;
}

Person::Person( int age, string name, int sex, 
    int house_number, string street_name, string city)
  :Person(age,name,sex)
{

  if(address != nullptr)
  {
    delete address; 
  }

  address = new Address(house_number, street_name, city);
}

Person::Person(Person const &p)
  :age(p.age), name(p.name), sex(p.sex)
{
  auto * a = p.address;
  address = new Address(a->house_number, a->street_name, a->city);

}
Person::~Person()
{
    if(address != nullptr )
    {
      delete address;
      address = nullptr;
    }
}
int Person::lifeExpectancy = 80;

