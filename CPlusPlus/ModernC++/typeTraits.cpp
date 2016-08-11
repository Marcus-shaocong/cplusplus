//
//
// Query characteristics about types
// Template specialization is pattern matching
//
//
//

#include <iostream>
#include <memory> 
using namespace std;
//Check if we have an int

template<typename T>
struct is_int
{
  static const bool value = false;
};

template<>
struct is_int<int>
{
  static const bool value = true;
};

//Two types the same?
template<class T, class U>
struct is_same
{
  static const bool value = false;
};

template<class T>
struct is_same< T, T >
{
  static const bool value = true;
};

struct bar
{

};

// write a type trait that will be true if the type is a boost::shared_ptr
/*
template<class T>
struct is_shared_ptr 
{
  static const bool value = false;
};

template<class T>
struct is_shared_ptr< std::shared_ptr<T>  >
{
  static const bool value = true;
};
*/

int main()
{
  cout<< "float : " << is_int<float>::value << endl;
  cout<< "int: " << is_int<int>::value << endl;
  cout<< "bar: " << is_int<bar>::value << endl;
  cout<<"same: " << is_same<int, bar>::value << endl;
  cout<<"same: " << is_same<bar, bar>::value << endl;
}

