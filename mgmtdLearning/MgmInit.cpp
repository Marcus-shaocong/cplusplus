#include "MgmInit.hpp"

MgmInit::MO_LIST MgmInit::m_pMoList;

void MgmInit::registerModule(BaseModule *pMo)
{
    if(pMo)
      m_pMoList.push_back(pMo);
    else
      cout<<" try to regiseter a Null object"<<endl;
}

void MgmInit::load()
{
  std::for_each(m_pMoList.begin(), m_pMoList.end(),std::mem_fun(&BaseModule::doRun));
}

MgmInit::~MgmInit()
{}

