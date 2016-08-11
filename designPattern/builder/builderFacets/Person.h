#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;

class PersonBuilder;
class PersonAddressBuilder;
class PersonJobBuilder;

class Person
{
  //address
  string street_address, post_code, city;
  //employment
  string company_name, position;
  int annual_income = 0;
  //Set the  
   Person(){}

  public:
   static PersonBuilder create();

   friend class PersonBuilder;
   friend class PersonAddressBuilder;
   friend class PersonJobBuilder;


   Person & operator=(Person && other)
   {
     if(this == &other)
     {
        return *this; 
     }
     street_address = std::move(other.street_address);
     post_code = std::move(other.post_code);
     city = std::move(other.city);
     company_name = std::move(other.company_name);
     position = std::move(other.position);
     annual_income = other.annual_income;
     return *this;
   }

   Person(Person && other)
     :street_address(std::move(other.street_address)),
     post_code(std::move(other.post_code)),
     city ( std::move(other.city)),
     company_name (std::move(other.company_name)),
     position (std::move(other.position)),
     annual_income (other.annual_income)
   {}

   friend std::ostream& operator<<(std::ostream & os, const Person & obj)
   {
      return os 
        <<"street address:" <<obj.street_address
        <<"Post code " << obj.post_code
        <<"city :" << obj.city
        <<"company_name" <<obj.company_name
        <<"position "<<obj.position
        <<"annual_income:" <<obj.annual_income;
   }
};

#endif
