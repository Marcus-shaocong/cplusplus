#ifndef MGMINIT_H
#define MGMINIT_H
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include "BaseModule.hpp"
using namespace std;


class MgmInit
{
  public:
    MgmInit(){};
    virtual ~MgmInit();
    static void registerModule(BaseModule *pMo);
    virtual void load();
  private :
    typedef vector<BaseModule *> MO_LIST;

    static MO_LIST m_pMoList;
};

#endif
