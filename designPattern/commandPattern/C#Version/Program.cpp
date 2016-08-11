

//
//related Patterns
//Factory pattern: useful to construct command objects
//Null object
//
//Composite 
//

class Program
{
  static void main(string[] args)
  {
    Prgram2.Run(args); 
  }
};

//this is not the command pattern, the traditional way.
public class Program1
{

  public static void Run(string[] args)
  {
      var availableCommands = GetAvailableCommands();

      if(args.Length == 0)
      {
        PrintUsage(availableCommands); 
        return;
      }
      processor.ExecuteCommand(args);
  }

  private static void PrintUsage()
  {
      Console.WriteLine("Usage : LoggingDemo CommandName Arguments");
      Console.WriteLine("Commands: ");
      Console.WriteLine("    UpdateQuantity number");
      Console.WriteLine("    CreateOrder");
      Console.WriteLine("    ShipOrder");
  
  }
}

//this is the command pattern
public Interface ICommand
{
    public interface ICommand
    {
      void Execute(); 
    }
}

public interfce ICommandFactory
{
  string CommandName{get;}
  string Description{get;}
  ICommand MakeCommand(string[] arguments);
}
public class UpdateQuantityCommand: ICommand, ICommandFactory
{
    public int NewQuantity{get; set;} 
    public void Execute()
    {
      const int oldQuantity = 5;
      Console.WriteLine("Database: Updated");
      Console.WriteLine("LOG: Updated order quantity from{0} to {1}");
    }
    public string CommandName{get {return "UpdateQuantity";}}
    public string Description{get {return "UpdateQuantity number";}}

    public ICommand MakeCommand(string [] arguments)
    {
      return new UpdateQuantityCommand{NewQuantity = int.Parse(arguments[1])}; 
    }
} 

public class NotFoundCommand: ICommand 
{
  public class NotFoundCommand: ICommand
  {
    public string name{get; set;}

    public void Execute()
    {
      Console.WriteLine("Could't find command:" +Name);
    }
  }
}


public class CommandParser
{
  readonly IEnumberable<ICommandFactory> availableCommands;
  public CommandParser(IEnumerable<ICommandFactory> availableCommand)
  {
    this.availabeCommands = availableCommands;
  }

  internal ICommand ParseCommand(string[] args)
  {
    var requestedCommandName = argss[0];
    var command = FindRequestedCommand(requestedCommandName);
    //null-object pattern
    if(null == command)
      return  new NotFoundCommand{ Name = requestedCommandName;};
    return command.MakeCommand(args);
  
  }

  ICommandFactory FindRequestedCommand(string commandName)
  {
    return availableCommands.FirstOrDefault(cmd=>cmd.CommandName == commandName);
  }
}


public class Program2
{
  public static void Run(string[] args)
  {
      var availableCommands = GetAvailableCommands();

      if(args.Length == 0)
      {
        PrintUsage(availableCommands); 
        return;
      }

      var parser = new CommandParser(availableCommands);
      var command = parser.ParseCommand(args);
      if(null != command)
        command.Execute();
  }

  static IEnumberable<ICommandFactory> GetAvailableCommands()
  {
    return new ICommandFactory[]{
      new CreateOrderCommand(),
      new UpdateQuantityCommand(),
      new ShipOrderCommnad(),
    }; 
  }

  pirvate static void PrintUsage(IEnumberable<ICommandFactory> available)
  {
      Console.WriteLine("Usage : LoggingDemo CommandName Arguments");
      Console.WriteLine("Commands: ");
      foreach(var command in availabeCommands)
          Console.WriteLine("{0}: ", command.Description);

  }
}
