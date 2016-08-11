#include <memory>



try{
  auto x = new X(Stuff);
  //risky stuff
  //if there is a exception X would not be released, that is why we need RAII
  delete x;
}
// we need to use reference, because if we don't we will lost the type info e.
catch(exception & e)
{
//react
}


try{
  //RAII concept, make the X as local variable,
  //so that when there is exception, it will unwinding the stack 
  //so X can be released
  auto x = make_shared<X>(Stuff);
}
catch(exception & e)
{
  //react

}

