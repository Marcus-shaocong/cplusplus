The Pimpl idiom


The Basic Structure


//Account.h
class AccountImpl;

class Account
{
 private: 
 AccountImpl* pImpl;

 public:
 int Any(int bal, Customer* cust);
  
};


//Account.cpp

#include "Account.h"
#include "AccountImpl.h"

Account::Any(int bal, Customer* cust)
{
  return pImpl->Any(bal, cust);
} 
