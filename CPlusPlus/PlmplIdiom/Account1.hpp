#pragma once

#include "TransactionLog.h"

class Customer;

class Account1
{
  private:
    int balance;
    int accountnum;
    static int maxAccountNumUsed;
    TransactionLog log;
    Customer * customer;
  
  public:
    Account1(int bal, Customer* cust)
      :balance(bal), customer(cust), accountnum(++maxAccountNumUsed),log(accountnum){}
    int Deposit(int amount)
    {
      log.AddDeposit("Today", amount);
      balance += amount;
      return balance;
    
    }
    int Withdraw(int amount)
    {
    
      log.AddWithDraw("Today", amount);
      balance -= amount;
      return balance;
    }
};

int Account1::maxAccountNumUsed = 0;

