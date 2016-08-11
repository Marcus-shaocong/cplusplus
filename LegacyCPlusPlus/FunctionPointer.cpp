//
//Function Pointers
//
//Decide at runtime what function to execute: very powerful
//in C, there was one way: function pointers
//
//C++ added ploymorphism
//Account->Update() will use right subclass's Update() method
//
//C++11 added lambdas
//Put the actual code to execute as a parameter to another call
//
// Function pointers are easy to set and use
//Method CalculateSlowly;
//Method(a,b,c);
//
//
//A little tricky to declare, everyone uses a typedef
//typedef int (*CHANGE) (int i);
//CHANGE f;
//
//
//Pointers to Member Function
//typedef int (Utility::*UF)();
//
//Use the class name and address-of operator when setting:
//UF action;
//action = &Utility::triplex;
//
//Deference when using (and lots of brackets)
//Utility u;
//(u.*action)()
//
//
//void *
//Used to indicate a pointer to anything
//Any kind of pointer(char*, Employee*, int*, ...) can be cast to it
//Popular function parameter
//Cast it back what you know it is
//In modern code, use a pointer to a base class
//then polymorphism
//or dynamic_cast<>
//Void * throws away type safety
//

#include <iostream>

using namespace std;


class Utility
{
  private:
    int x;
  public:
    Utility(int a): x(a){}
    int doublex() { return 2*x;}
    int triplex() { return 3*x;}

};

typedef int (Utility::*UF)();

int ManipulateUtility(int i)
{
  Utility u(i);
  UF action;
  if( i>3 )
    action = &Utility::triplex;
  else
    action = &Utility::doublex;
  return (u.*action)();
}


int doubler(int i)
{
  return i * 2;
}


int tripler( int i)
{
  return i * 3;
}

typedef int (*CHANGER )(int i);

int Change(int i)
{
  CHANGER f;
  if( i > 5 )
    f = tripler;
  else
    f = doubler;

  return f(i);
}


struct KPoint 
{
  int x, y;
};

void UseSomething( void * something)
{
  int * s = (int*)something;
  cout<< " s " << *s << endl;
} 

int main ()
{
  int i1 = 7 ;
  long l1 = 3L;

  int i2 = Change(i1);
  cout<< " i2 " << i2 << endl;
  int l2 = Change(l1);
  cout<< " l2 " << l2 << endl;

  int i3 = 8;
  int l3 = ManipulateUtility(i3);
  cout<< " l3 " << l3 << endl;

  KPoint p;
  p.x = 2;
  p.y = 3;
  UseSomething(&i1);

  UseSomething(&(p.x));
  UseSomething(&p);
}
