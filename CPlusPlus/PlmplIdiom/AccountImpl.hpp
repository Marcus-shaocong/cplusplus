#pragma once

#include "TransactionLog.h"
#include <string>

class Customer;

class AccountImpl
{
  private:
    int balance;
    int accountnum;
    static int maxAccountNumUsed;
    TransactionLog log;
    Customer * customer;
    std::string BuildDateStringForToday();
  public:
    AccountImpl(int bal, Customer* cust);
    int Deposit(int amount);
    int Withdraw(int amount);
};




