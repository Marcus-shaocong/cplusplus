
#include <iostream>
#include <sstream>

using namespace std;


struct HelloInterface
{
  virtual void outputMessage() =0;
  virtual ~HelloInterface(){}
};

struct HelloCoutImpl : HelloInterface
{
  void outputMessage()
  {
    cout<<"Hello World\n"; 
  }
};

struct HelloTestImpl: HelloInterface
{
  std::ostringstream os;
  void outputMessage()
  {
    os << "Hello test\n"; 
  }
};

class HelloWorld
{
  HelloInterface &hello;
  public:
    HelloWorld(HelloInterface & hello_):hello(hello_){}
    void operator()()
    {
      hello.outputMessage(); 
    }
};


int main()
{
  HelloCoutImpl tocout;
  HelloWorld doit(tocout);
  doit();

  HelloTestImpl test;
  HelloWorld do2(test);
  do2();
  cout<<test.os.str(); 
  return 0;
}
