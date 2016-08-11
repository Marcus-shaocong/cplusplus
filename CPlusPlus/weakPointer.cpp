

#include <iostream>
#include <memory>
#include <cassert>
using namespace std;

int main()
{
  auto sp = make_shared<int>(124);
  auto wp = weak_ptr<int> {sp};
  wp = sp;

  assert(!wp.expired());
  assert(wp.use_count() == 1);


  //the lock funciton will get a strong ref of the share_ptr
  if( auto locked = wp.lock())
  {
    assert(wp.use_count() == 2);
    cout<<" locked " <<*locked<<endl;  
  }

  //after seting the sp to empty, the weak ptr is expired. only holds a weak ref now
  sp = nullptr;

  assert(wp.expired());
  assert(wp.use_count() == 0);

  if(auto locked = wp.lock())
  {
    cout<<" locked" <<*locked<<endl;  
  }
  else
  {
    wp.reset(); 
  }

  return 0;
};


