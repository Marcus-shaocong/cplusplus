
#pragma once
#include "BaseModule.hpp"
class ModuleOne : public BaseModule
{
  public:
    ModuleOne():BaseModule("Module one"){}

   ~ModuleOne(){}

   void doRun();
};

class ModuleTwo: public BaseModule
{
  public:
    ModuleTwo():BaseModule("Module Two"){}

   ~ModuleTwo(){}

   void doRun();
};
