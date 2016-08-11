#include <iostream>
#include "Person.hpp"
#include "Employee.hpp"

using namespace std;
void Employee::greet()
{
    Person::greet();

    cout<<"by the way, i work in " <<depart<<endl;
};

