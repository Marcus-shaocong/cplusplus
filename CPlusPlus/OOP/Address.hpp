#pragma once
#include<string>
using namespace std;

class Address
{
  public:
  string street_name;
  string city;
  int house_number;

  Address(const int & number, const string city, const string& name)
    :street_name(name), city(city), house_number(number)
  {}

};
