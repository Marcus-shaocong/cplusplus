//
// Applicability
// Legacy Systems
// Add functionality to controls, Sealed classes
//
//
// pizza -> largePizza, SmallPizza, MediumPizzza
// now we want to 


public abstract class Pizza
{
  public string description{get; set;}
  public abstract string GetDescription();
  public abstract double CalculateCost();
} 


public class SmallPizza: Pizza
{
  public SmallPizza()
  {
    Description = "Small Pizza";
  }

  public overide string GetDescription()
  {
      return Description;  
  }

  public override double CalculateCost()
  {
    return 3.00; 
  }
}

public class MediumPizza: Pizza
{
  public MediumPizza()
  {
    Description = "Medium Pizza";
  }

  public override string GetDescription()
  {
      return Description;  
  }

  public override double CalculateCost()
  {
    return 6.00; 
  }
}

public class LargePizza: Pizza
{
  public LargePizza()
  {
    Description = "Large Pizza";
  }

  public override string GetDescription()
  {
      return Description;  
  }

  public override double CalculateCost()
  {
    return 9.00; 
  }
}

public class PizzaDecorator: Pizza
{
  protected  Pizza _pizza;
  PizzaDecorator(Pizza pizza)
  {
    _pizza = pizza; 
  }
  public override string GetDescription()
  {
      return _piaaz.Description;  
  }

  public override double CalculateCost()
  {
    return _pizza.CalculateCost(); 
  }

}

public class Cheese : PizzaDecorator
{
  public Cheese(Pizza pizza):base(pizza)
  {
  
  }

  public override string GetDescription()
  {
      return _piaaz.Description + "Cheese";  
  }

  public override double CalculateCost()
  {
      return _pizza.CalculateCost() + 1.25; 
  }
}

public class Ham: PizzaDecorator
{
  public Ham(Pizza pizza):base(pizza)
  {
  
  }

  public override string GetDescription()
  {
      return _piaaz.Description() + "Ham";  
  }

  public override double CalculateCost()
  {
      return _pizza.CalculateCost() + 1.0; 
  }
}

public class Peppers: PizzaDecorator
{
  public Peppers(Pizza pizza):base(pizza)
  {
  
  }

  public override string GetDescription()
  {
      return _piaaz.Description() + "Pepper";  
  }

  public override double CalculateCost()
  {
      return _pizza.CalculateCost() + 2.0; 
  }
}

public class Pepper 
static void Main(string[] args)
{
  largePizza largePizza = new LargePizza();
  largePizza = new Cheese(largePizza);
  Console.WriteLine(largePizza.Description());
  Console.WriteLine("{0:C2}",largePizza.CalculateCost());

}
