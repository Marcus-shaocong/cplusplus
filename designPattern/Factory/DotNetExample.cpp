
//
//
// separate object creation from the decision of which object to create
// add new classes and functionality without breaking OCP
// Factory-produced objects
// Factories themselves
//
// Store which object to create outside of the program
//
//
//


//Simple Factory
//Encapsulate object creation
//Allows for late-bound decisions regrarding instantiation
class Program
{
  static void Main(string[] args)
  {
    string carName = args[0];
    IAuto car = GetCar(carName);
    car.TurnOn();
    car.TurnOff();
  }

  static IAuto GetCar(string carName)
  {
    //if we 
    switch(carName)
    {
      case "bmw":
        return new BMW335Xi();
      case "mini:
        return new miniCooper();
      default:
        return new NullCar();
    } 
  }
}


namespace Factory2
{

  static void Main(string[] args)
  {
    string carName = args[0];
    AutoFactory car = factory.CreateInstance(carName);
    IAuto car = factory.CreateInstance(carName);
    car.TurnOn();
    car.TurnOff();
  }

  public class AutoFactory
  {
   
    Dictionary<string, Type> autos;
    public AutoFactory()
    {
      LoadTypesICanReturn();  
    }

    public IAuto CreateInstance(string carName)
    {
      Type t = GetTypeToCreate(carName);

      if(t == null)
      {
        return NullAuto();  
      }
      return Activator.CreateInstance(t) as IAuto;
    }

    Type GetTypeToCreate(string carName)
    {
      foreach(var auto in autos)
      {
        if(auto.Key.Contains(carName))
        {
          return autos[auto.Key]; 
        }
      }
      return null;
    }

    void LoadTypesICanReturn()
    {
      autos = new Dictionary<string, Type>();
      Type[] typesInThisAssembly = Assembly.GetExecutingAssembly().GetTypes();
      foreach(Type type in typesInThisAssembly)
      {
        if(type.GetInterface(typeof(IAuto).ToString()) != null)
        {
          autos.Add(typen.name.toLower(),type); 
        }
      } 
    }
  } 
}

//Factory Method
//Define an interface for creating an object, but let the subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasseses.
//Adds an interface to the factory itself from Simple Factory
//Defers object creation to multiple factories that share an interface
//Derived classes implement or override the factory method of the base

  public interface IAutoFactory
  {
    IAuto CreateAutomobile();
  }

  class MiniCooperFactory: IAutoFactory
  {
    public IAuto CreateAutomobile()
    {
      var mini = new MiniCooper();
      mini.SetName("Mini Cooper S");
      return mini;
    }

  }

public interface IAuto
{
  public interface IAuto
  {
    string Name{get;}
    void SetName(string name);
    void TurnOn();
    void Turnoff();
  }
}

public class BMW: IAuto
{
  public BMW(sring name)
  {}

  public string Name(get; private set;}

  public void SetName(string name)
  {
  if(name == null) throw new ArgumentNullException("name");
  Name = name;
  }

  public void TurnOn()
  {
    Console.WriteLine("The " + Name + "is up nd ruing with a mighty whiiiir");
  } 

  public void TurnOff()
  {
    Console.WriteLine("The " + Name + "is shutting down");
  } 
}

namespace Factory2
{


  static void Main(string[] args)
  {
    IAutoFactory autoFactory = LoadFactory();
    IAuto car = autoFactory.CreateAutomobile();
    car.TurnOn();
    car.TurnOff();
  }

  static IAutoFactory  LoadFactory()
  {
    Load a setting from a configure file
    string factoryName = Properties.Settings.Default.AutoFactory;

    return Assembly.GetExcutingAssembly().CreateInstance(factoryName) as IAutoFactory;
  }


}

//Abstract Factory
//Provide an interface for creating families of related or dependent objects without specifying their concrete classes
//Factories create different types of concrete objects(products)
//A Factory now represents a "family" of objects that it can create
//Factories may have more than one factory method. 
//
//


public interface IAutoFactory
{
  IAutomobile CreateSportsCar();
  IAutomobile CreateLuxuryCar();
  IAutomobile CreateEconomyCar();
}

public class BMWFactory: IAutoFactory
{
  IAutomobile CreateSportsCar();
  {
    return new BMWM3();
  }
  IAutomobile CreateLuxuryCar();
  {
    return new BMW740();
  }

  IAutomobile CreateEconomyCar();
  {
    return new BMW328();
  }
}

namespace Factory3
{
  static void Main(string[] args)
  {
    IAutoFactory factory = LoadFactory();
    
    var car = factory.CreateSportsCar();
    car.TurnOn();
    car.TurnOf();
    
    car = factory.CreateLuxuryCar();
    car.TurnOn();
    car.Turnoff();

    car = factory.CreateEconomyCar();
    car.TurnOn();
    car.Turnoff();

  }

  static IAutoFactory  LoadFactory()
  {
    Load a setting from a configure file
    string factoryName = Properties.Settings.Default.AutoFactory;

    return Assembly.GetExcutingAssembly().CreateInstance(factoryName) as IAutoFactory;
  }


}
