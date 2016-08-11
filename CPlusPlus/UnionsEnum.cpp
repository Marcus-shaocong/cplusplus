#include <iostream>

using namespace std;


enum Color
{
  Red,
  Green,
  Orange
};



enum class State
{
  Win,
  Lose,
  Even
};

int main()
{
 Color c = Red;
 State x = State::Win;
 int i = c;
 cout<< c <<" i " <<i ;
return 0;
}
