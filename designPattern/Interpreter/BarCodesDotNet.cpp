
// How bar Codes Work
// <UPC> ::= <Manufacturer ID> <Item Number> <Check Digit>
// <Manufacurer ID>::= <Digit><Digit><Digit><Digit><Digit><Digit>
// <Item Number>::=<Digit><Digit><Digit><Digit><Digit>
//<Check Digit>::=<Digit>
//<Digit>::=0|1|2|3|4|5|6|7|8|9
//

//Sandwhich demo
//BNF definition:
//<sandwhich> ::=<bread> <condimentList> <ingredientList> <condimentList> <bread>
//<condimentList> ::= {<condiment>}
//<ingredientList> ::={<ingredient>}
//<bread> ::<whiteBread> | <wheatBread>
//<condiment> ::= <mayoCondiment>|<mustardCondiment>|<ketchupCondiment>
//<ingredient> ::= <lettuceIngredient>|<tomotoIngredient>|<chickenIngredient>
//

public interface Expression
{
    void Interpret(Context context);  
} 

public class Context
{
  public string output{get; set;}
}


public class Sandwhich: Expression
{
  pirvate readonly Bread topBread;
  pirvate readonly CondimentList topCondiments;
  pirvate readonly IngredientList ingredients;
  pirvate readonly CondimentList bottomCondiments;
  pirvate readonly Bread bottomBread;

  public void Interpret(Context context)
  {
    this.topBread = topBread;
    this.topCondiments = topCondiments;
    this.ingredients = ingredients;
    this.bottomCondiments = botomCondiments;
    this.bottomBread = bottomBread;
  }

  public void Interpret(Context context)
  {
    context.Output += "|";
    topBread.Interpret(context);
    context.Output += "|";
    context.Output += "<--";
    topCondiments.Interpret(context);
    context.Output += "-";
    ingredients.Interpret(context);
    context.Output += "-";
    bottomCondiments.Interpret(context);
    context.Output += "-->";
    context.Output += "|";
    bottomBread.Interpret(context);
    context.Output += "|";
    Console.WriteLine(context.Output);
  }
}

public class IngredientList: Expression
{
    private readonly List<Ingredient> ingredients;
    public IngredientList(List<Ingredient> ingredients)
    {
      this.ingredients = ingredients; 
    }

    public void Interpret(Context context)
    {
        foreach(var ingredient in ingredients)
          ingredient.Interpret(context);
    }

}

public interface Ingredient :Expression{}
public class TomotoIngredient : Ingredient
{
  public void Interpret(Context context)
  {
    context.Output += string.Format(" {0} ", "Tomato");   
  }
}

public class LettuceIngredient: Ingredient
{
  public void Interpret(Context context)
  {
    context.Output += string.Format(" {0} ", "lettuce");   
  }
}

public class ChickenIngredient: Ingredient
{
  public void Interpret(Context context)
  {
    context.Output += string.Format(" {0} ", "Chicken");   
  }
}


//condiements 
public class CondimentList: Expression
{
    private readonly List<Condiment> condiments;
    public IngredientList(List<Condiment> condiments)
    {
      this.condiments = condiments; 
    }

    public void Interpret(Context context)
    {
        foreach(var condiment in condiments)
          condiment.Interpret(context);
    }

}

public interface condiments:Expression{}

public class mayoCondiment: Condiment
{
  public void Interpret(Context context)
  {
    context.Output += string.Format(" {0} ", "mayo");   
  }

}

public class mayoCondiment: Condiment
{
  public void Interpret(Context context)
  {
    context.Output += string.Format(" {0} ", "mayo");   
  }

}

public class ketchupCondiment: Condiment
{
  public void Interpret(Context context)
  {
    context.Output += string.Format(" {0} ", "ketchup");   
  }
}
//bread
public interface Bread:Expression{}

public class WheatBread:Bread 
{
  public void Interpret(Context context)
  {
    context.Output += string.Format(" {0} ", "mayo");   
  }

}

public class WhiteBread : Bread 
{
  public void Interpret(Context context)
  {
    context.Output += string.Format(" {0} ", "mayo");   
  }
}

class Progream
{
    static void Main(string[] args)
    {
      var sandwhic = new Sandwhich(
          new WheatBread(),
          new CondimentList(
            new List<Condiment>{new MayoCondiment(), newMustardCondiment()} 
            ),
          new IngredientList(
            new List<Ingredient>{new TomotoIngredient(), LettuceIngredient()} 
            ),
          new CondimentList(
            new List<Condiment>{new MayoCondiment(), newMustardCondiment()} 
            ),
          new WhiteBread());

      sandwhich.Interpret(new Context());
    }

}
