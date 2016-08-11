//
//
//Monads are design patterns in functional programming
//Much more usable in functional languages due to 
//Better treatment of functional objects
//Useful auxiliary constructs(e.g. pattern matching)
//Somewhat implementable in OOP languages
//
//
#include <string>
#include <iostream>

using namespace std;

template <typename T> struct Maybe;


template <typename T> Maybe<T> maybe(T* context)
{
  return Maybe<T>(context);
}

template <typename T> struct Maybe
{
  T* context;
  explicit Maybe(T* const context)
    :context{context}
  {
  }

  template <typename Func>
    auto With(Func evaluator)
    {
      if( context == nullptr )
      {
        return Maybe<typename remove_pointer< decltype(evaluator(context)) >::type>(nullptr);
      }
      else
      {
        return maybe(evaluator(context)); 
      }
    }
  
  /* template <typename Func> */
  /*   auto Do(Func action) */
  /*   { */
  /*     if(context != nullptr) action(context); */ 
  /*     return *this; */
  /*   } */
};

struct Address
{
  string * house_name = nullptr;
};

struct Person
{
  Address * address = nullptr;
};

void print_house_name(Person *p)
{
  maybe(p).With([](auto x) { return x->address;})
    .With([](auto x){return x->house_name;});
//      .Do([](auto x){cout<< *x <<endl;});
}

int main()
{
  Person p;
  p.address = new Address;
  p.address->house_name = new string("name");
  print_house_name(&p);
  delete p.address->house_name;
  delete p.address;
  return 0;
}
