//
// calculate the factorial of N at compile time
// Print result for factorial of 3 
//
//
//


#include<iostream>
#include<functional>
using namespace std;

template< int N>
struct factorial
{
  //enum{ value = N*factorial<N-1>::value };
  static const int value = N*(factorial<N-1>::value);
};

template<>
struct factorial<0>
{
  //enum{ value = 1};
  static const int value =1;
}; 

int main()
{
  std::function<int(int)> fact;
  fact = [&fact](int n){ 
    if(n==0)
      return 1;
    else
      return n*fact(n-1);
  };

  cout<<"factorial(4):" << fact(4) <<endl;

  cout<<"fact of 5: " <<factorial<5>::value <<"\n"<<endl;
  cout<<"fact of 3: " <<factorial<3>::value <<"\n"<<endl;
  return 0;  
}



