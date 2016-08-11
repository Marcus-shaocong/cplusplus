#include "Account.hpp"
#include "AccountImpl.hpp"

class AccountImpl;

Account::Account(int bal, Customer* cust)
  :pImpl(new AccountImpl(bal, cust))
{

}

Account::~Account()
{

}

Account::Account(Account && other)
  :pImpl(std::move(other.pImpl))
{

}


Account& Account::operator=( Account && other)
{
  pImpl = std::move(other.pImpl);
  return *this;
}

int Account::Deposit(int amount)
{
  return pImpl->Deposit(amount);
}

int Account::Withdraw(int amount)
{
  return pImpl->Withdraw(amount);
}


