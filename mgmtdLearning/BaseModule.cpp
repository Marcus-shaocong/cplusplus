#include "BaseModule.hpp"
#include "MgmInit.hpp"

BaseModule::BaseModule(string _name)
  :name{_name}
{
  MgmInit::registerModule(this);
}

BaseModule::~BaseModule()
{
}

void BaseModule::doRun()
{}

