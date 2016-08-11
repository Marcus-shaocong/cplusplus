#ifndef PERSON_BUILDER_H
#define PERSON_BUILDER_H
#include "Person.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"
class  PersonAddressBuilder;
class  PersonJobBuilder;
class PersonBuilder
{
  Person p;
protected:
  Person & person;

  explicit PersonBuilder(Person& person)
    :person(person)
  {}
public:
  PersonBuilder():person(p){
  }
 
  operator Person()
  {
    return move(person);
  }

  PersonAddressBuilder lives();
  PersonJobBuilder works();
};
inline PersonAddressBuilder PersonBuilder::lives()
{
  return PersonAddressBuilder{ person};

}
inline PersonJobBuilder PersonBuilder::works()
{
  return PersonJobBuilder{person};
}
#endif
