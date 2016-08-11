//
//
// CRTP curiously recurring template parameter
// when a class inherits from a template class that takes the derived 
// class as template argument
//
//
//

/* template <typename Derived> */
/* class CuriousBase */
/* { */

/* }; */


/* class Curious : public CuriousBase<Curious> */
/* { */

/* }; */


//CRTP limit object count for a class(impl)
//
#include<stdexcept>
#include<atomic>

template <typename TOBELIMITED, size_t maxNumberOfInstances>
class LimitNofInstances
{
  static std::atomic<size_t> counter;
  protected:
  LimitNofInstances()
  {
    if( counter >= maxNumberOfInstances )
    {
      if(counter >= maxNumberOfInstances)
      {
        throw std::logic_error("too many instances"); 
        ++counter;
      }
    }

  }

  ~LimitNofInstances(){
    --counter; 
  }
};

template <typename TOBELIMITED, size_t maxNumberOfInstances>
std::atomic<size_t> LimitNofInstances<TOBELIMITED, maxNumberOfInstances>::counter(0);

int main()
{}
