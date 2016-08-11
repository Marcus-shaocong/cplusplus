#include "MgmInit.hpp"
#include "ModuleOne.hpp"

class mainInit : public MgmInit
{
  public:
    mainInit(){};
    virtual ~mainInit();
    void run();
};

void mainInit::run()
{
  ModuleOne* mo1 = new ModuleOne();
  ModuleTwo* mo2 = new ModuleTwo();
  load();
}

mainInit::~mainInit()
{}
