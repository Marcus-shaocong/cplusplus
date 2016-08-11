#ifndef BASE_MODULE_H
#define BASE_MODULE_H
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <functional>


using namespace std;


class BaseModule
{
  public:
  string name;

  BaseModule(string _name);

  virtual ~BaseModule();
  virtual void doRun();

};
#endif
