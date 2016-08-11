#include<string>
#include<iostream>

using namespace std;

template<typename T>
T sum(T t)
{
  return t;
}

template<typename T, typename ...Args>
auto sum(T t, Args ...u)
{
return t + sum(u...);
}

void variadic()
{
  cout <<sum(1,2,3,4)<<endl;
}

int main()
{
  variadic();
  return 0;
}
