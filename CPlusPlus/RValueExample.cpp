#include <iostream>
#include <string>

using namespace std;

class Address
{
  public:
  string city;

  Address(){}
  Address(const string & city)
    :city{city}
  {}

};



void inc(int & x) {x++;}

int meaningOfLife(){return 42;}
void move_rvalue()
{
  int a = 0;
  inc(a);

  //Y is a rvalue
  int && y = meaningOfLife();

  cout<<y<<endl;
  //below code will cause the Adress allocate twice, not efficient.
  Address book[100];
  book[55] = move( Address("Paris"));

  auto swap = [](int & a, int & b)
  {
    //we are copying here, this is not efficient.
    int tmp{a};
    a = b;
    b = tmp;
  
  };

  auto betterswap = [](int & a, int & b)
  {
    //move passing a r value
    int tmp(move(a));
    a = move(b);
    b = move(tmp);
  
  };

  int x = 2, z = 5;
  swap(x,z);
  cout<<" x " << x << " z is " <<z<<endl;
}

int main()
{move_rvalue();
return 0;
}
