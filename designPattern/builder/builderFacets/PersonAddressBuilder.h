#ifndef PERSON_ADRESS_BUILDER_H
#define PERSON_ADRESS_BUILDER_H
#include <string>
#include "PersonBuilder.h"

class PersonAddressBuilder: public PersonBuilder
{
  typedef PersonAddressBuilder Self;

  public:
  
  explicit PersonAddressBuilder(Person & person)
    :PersonBuilder(person)
  {
  
  }

  Self& at(string street_address)
  {
    person.street_address = street_address; 
    return *this;
  }

  Self& with_postcode(string street_address)
  {
    person.post_code = street_address; 
    return *this;
  }

  Self& in(string city )
  {
    person.city = city; 
    return *this;
  }
};
#endif
