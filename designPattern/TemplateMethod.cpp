//
//***********************************
//   Template Method                *
//***********************************
//
//Define he skeleton of an algorithm in an operation,
//deferring some steps to subclasses. Template Method
//lets superclass redefine certain steps of an algorithm
//without changing the algorithm's structure.
//
//

template <typename Super>
class Base: Super
{
  public:
    void algorithm()
    {
      Super::step1();
      Super::step2();
    }
};

class TMImpl
{
  protected:
    void step1(){}
    void step2(){}
};

Base<TMImpl> object;
object.algorithm();

Base<AnotherImpl> object2;
object2.algorithm();

