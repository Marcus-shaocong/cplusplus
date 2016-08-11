//
// Curiously Recurring Template Pattern
// struct derived : base<derived>
// {
//
// };
// Static Polymorphism
// Injecting Behaviour
//
//
/*
template <class Derived>
struct base
{
  void interface()
  {
    //base class to call its derived class's method
    static_cast<Derived*> (this)->implementation(); 
  
  }

};

struct derived : base<derived>
{
  void implementation();
};
*/

#include <iostream>
using namespace std;
template <typename Derived>
struct cloneable
{
  Derived* clone() const
  {
    return new Derived(static_cast<Derived const &> (*this)); 
  }

};

struct bar :cloneable<bar>
{
  int value;
};

template<typename Derived>
struct base
{
  float profit()
  {
     Derived *p = new Derived(static_cast<Derived const &> (*this)); 
     return (42*p->output)/(p->input);
  }
};

template<typename Derived>
struct enable_profit 
{
  float profit()
  {
     Derived const & derived  = static_cast<Derived const &> (*this); 
     return (42*derived.output)/(derived.input);
  }
};
struct derivedClass : enable_profit<derivedClass>
{
  float output;
  float input;
};

int main()
{
  bar my_bar;
  my_bar.value = 42;
  bar * my_clone = my_bar.clone();
  std::cout<<"my_clone: " << my_clone->value << endl;

  derivedClass d;
  d.output = 11;
  d.input = 10;
  cout<<"profit : " << d.profit()<<endl;
}
