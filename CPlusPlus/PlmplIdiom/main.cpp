#include <vector>
#include <iostream>
#include "Account1.hpp"
#include "Account.hpp"
using namespace std;
int main()
{
 Account1 a_1(0, nullptr);
 int balance = a_1.Deposit(50);
 cout<< balance<<endl;

 Account a2(0, nullptr);
 a2.Deposit(150);
 Account a3(0, nullptr);
 a3.Deposit(100);
 vector<Account> v;
 v.push_back(move(a2));
 v.push_back(move(a3));

 Account x = v[0];
 balance = x.Deposit(100);

 cout<< balance<<endl;

return 0;
}
