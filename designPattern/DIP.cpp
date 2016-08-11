
// Dependency Inversion Principle
// Summary:
//
// 1. High-level modules should not depend on low-level modules, Both should depned on abstractions.
// Example: reporting component should depend on a ConsoleLogger, but can depend on an ILogger.
// 2. Abstractions should ont depend upon details. Details should depend upon abstractions.
// In other words, depndencies on interfaces and supertypes is better that dependencies on contrete types.
//
// Inversion of Control(IoC) the actual process of creating abstractions and getting them to replace dependencies.
//
// Dependency Injection: use of software frameworks to ensure that a component's dependencies are satisfied.
//

#include <iostream>
#include <memory>


struct ILogger
{
  virtual ~ILogger()
  {}

  virtual void Log(const std::string & s) = 0;
};

struct ConsoleLogger: ILogger
{

  void Log(const std::string & s) override
  {
    std::cout<< "LOG: " << s.c_str() << std::endl;
  }
};

struct Engine
{
  float volume = 5;
  int horse_power = 400;

  friend std::ostream& operator << (std::ostream & os, const Engine & obj)
  {
    return os <<" volume: " << obj.volume <<" Horse_power" <<obj.horse_power;
  
  }

};


struct Car
{
  std::shared_ptr<Engine> engine;
  std::shared_ptr<ILogger> logger;
  explicit Car(const std::shared_ptr<Engine> & engine, const std::shared_ptr<ILogger> & i_logger)
    :engine{engine}, logger{i_logger}
  {
    logger->Log("create a car");
  }

  friend std::ostream& operator << (std::ostream & os, const Car & obj)
  {
    return os <<" Car with engine: " << *obj.engine;
  
  }
};

int main()
{
  // this is a old way to create a car, a cat need a engine. 
  auto e = std::make_shared<Engine> ();
  auto log  = std::make_shared<ConsoleLogger> ();
  auto c = std::make_shared<Car>(e, log);
  
  // new way is to using the Dependency Injection 
  // by using the boost library
  // the injector will automatic bind the ILogger to ConsoleLogger, 
  // and figure out what other conponent a car have, like a engine.
  // so user would not need to explicit specify the engine.

  using namespace boost; 
  auto injector = di::make_injector(
      di::bind<ILogger>().to<ConsoleLogger>()
      );
  auto car = injector.create<std::shared_ptr<Car>>();
  std::cout<<*car<<std::endl;


  std::cout<<*c<<std::endl;
  return 0;
}

