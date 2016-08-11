
#include "Person.hpp"

class Employee : public Person
{
  public:
  string depart;
  Employee(const string & name)
    :depart(name)
  {}

  void greet();
};

