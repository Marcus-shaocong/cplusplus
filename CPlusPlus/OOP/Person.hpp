#pragma once
#include <iostream>
#include <string>
#include "Address.hpp"

using namespace std;
class Person
{
  static int lifeExpectancy;
public:
  const static int female = 0;
  const static int male = 1;
  
  int age;
  string name;
  int sex;
  virtual  void greet();

  Address * address;
  Person( int age, string name, int sex);
  Person( ){}
  ~Person();
  Person( int age, string name, int sex, int house_number, string street_name, string city);

  Person(const Person&p);


  static int getLifeExpectancy();
};


