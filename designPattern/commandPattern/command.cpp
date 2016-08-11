#include <functional>
#include <vector>

#include<iostream>

using namespace std;


struct think 
{
    void operator() (){
      cout<< " think" <<endl; 
    }
};


struct hide 
{
    void operator() (){
      cout<< " hide " <<endl; 
    }
};


struct walk
{
    void operator() (){
      cout<< " walk " <<endl; 
    }
};

template <typename Fun>
void doit(Fun f)
{
  f();
}

void thisIsATest()
{
  doit(think{});
  doit(walk{});
  hide()();
  function<void()> f {walk{}};
  f();
  doit(f);
  f = think {};
  f();
}

struct macroCommand:vector<function<void()> >
{
  using vector<function<void()>>::vector;
  void operator()()
  {
    for(auto &x:*this)
    {
      x(); 
    }
  }
};

void testmacroCmd()
{
  macroCommand m;
  m.push_back(think{});
  m.push_back(walk{});
  m.push_back(m);
  m();
}

int main()
{
  //thisIsATest();
testmacroCmd();
  return 0;
}


