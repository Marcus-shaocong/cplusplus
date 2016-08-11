#pragma once
#include <memory>
#include <string>

class Customer;

class AccountImpl;


class Account
{
  private:
    std::unique_ptr<AccountImpl> pImpl;

  public:
    Account(int bal, Customer* cust);

    ~Account();

    Account(Account && other);
    Account & operator = (Account && other);

    int Deposit(int amount);
    int Withdraw(int amount);
};


