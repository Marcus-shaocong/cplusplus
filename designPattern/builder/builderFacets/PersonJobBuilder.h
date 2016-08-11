#ifndef PERSON_JOB_BUILDER_H
#define PERSON_JOB_BUILDER_H
#include <string>
#include "PersonBuilder.h"

class PersonJobBuilder: public PersonBuilder
{
  typedef PersonJobBuilder Self;

  public:
  
  explicit PersonJobBuilder (Person & person)
    :PersonBuilder(person)
  {
  
  }

  Self& at(string com)
  {
    person.company_name = com; 
    return *this;
  }

  Self& as_a(string pos)
  {
    person.position = pos; 
    return *this;
  }

  Self& earning (int salary)
  {
    person.annual_income = salary; 
    return *this;
  }
};

#endif
