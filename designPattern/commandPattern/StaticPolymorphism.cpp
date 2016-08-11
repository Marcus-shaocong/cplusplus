
#include <iostream>
#include <sstream>

using namespace std;



struct HelloCoutImpl 
{
  static void outputMessage()
  {
    cout<<"Hello World\n"; 
  }
};

struct HelloTestImpl
{
  static std::ostringstream os;
  static  void outputMessage()
  {
    os << "Hello test\n"; 
  }
};

std::ostringstream HelloTestImpl::os;


//Here is a Null Object
struct HelloNullImpl
{
  static void outputMessage(){}
};

template <typename HelloInterface=HelloNullImpl>
class HelloWorld
{
  public:
    void operator()()
    {
      HelloInterface::outputMessage(); 
    }
};


int main()
{
  HelloWorld<HelloCoutImpl> doit;
  doit();

  HelloWorld<HelloTestImpl> do2;
  do2();
  cout<<HelloTestImpl::os.str();

  HelloWorld<> donothing;
  donothing();
  return 0;
}
