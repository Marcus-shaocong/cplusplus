//
//
// A policy class is a template parameter that specializes
// behavior and is selected at compile time
//
//
//std::basic_string< charT, traits, Alloc >
//namespace std
//{
// typedef basic_string<char> string;
//}
//
//
//
#include <iostream>
using namespace std;

struct NoChecking
{
  template< typename T >
    static bool check_pointer( T*) {return true;}

};

struct NullChecking
{
  template< typename T >
    static bool check_pointer( T*p) {return (p!=0); }
};

struct BadPointerDoNothing
{
  template< typename T >
    static T* handle_bad_pointer( T*p )
    {
      std::cout<<"pointer is moldy" << std::endl;
      return p;
    }
};

template< typename T,
          typename CheckingPolicy = NoChecking,
          typename BadPointerPolicy=BadPointerDoNothing>
class pointer_wrapper
{
  public:
    pointer_wrapper(): value_(0) {}
    explicit pointer_wrapper(T* p) : value_(p){}

    operator T*()
    {
      if( !CheckingPolicy::check_pointer(value_) )
      {
        return BadPointerPolicy::handle_bad_pointer(value_); 
      }
      else
      {
        return value_; 
      }
    }

  private:
    T* value_;
};


int main()
{
  /* pointer_wrapper<int> number( new int); */
  /* *number = 43; */
  /* std::cout<<" number : " << *number << endl; */

  /* pointer_wrapper<int> mynumber; */
  /* *mynumber = 42; */

  /* std::cout<<"my  number : " << *mynumber << endl; */


  pointer_wrapper<int, NullChecking> number2( new int);
  *number2 = 43;
  std::cout<<" number2 : " << *number2 << endl;

  pointer_wrapper<int, NullChecking> mynumber2;
  *mynumber2 = 42;

  std::cout<<"my  number2 : " << *mynumber2 << endl;

  return 0;
}




