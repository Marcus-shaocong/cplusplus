#pragma once

#include <string>

class AccountImpl;
class Account1;

class TransactionLog
{
  private:
    int accnum;
  public:
    TransactionLog(int an):accnum(an){}

    void AddDeposit(std::string date, int amount)
    {
    
    }

    void AddWithDraw(std::string date, int amount)
    {
    
    }
};
