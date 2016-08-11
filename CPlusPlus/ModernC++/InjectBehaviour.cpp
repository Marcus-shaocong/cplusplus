//
// Curiously Recurring Template Pattern

// Injection behaviour
// here is an example to enable a class to use share_ptr

#include <iostream>
using namespace std;

template<class T>
class enable_shared_from_this
{
  public:
    shared_ptr<T> shared_from_this()
    {
      shared_ptr<T> p(weak_this_);
      return p;
    }

    shared_ptr< T const > shared_from_this()const
    {
      shared_ptr<T const> p(weak_this_);
      return p;
    }
  private:
    mutable weak_ptr<T> weak_this_;
};

struct handler: boost::enable_shared_from_this<Handler>
{

}


