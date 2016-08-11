//
//
//
//Intent of the State pattern
//Change behavior of the object with each state
//Encapsulate the logic of each state into a single object
//Allow fow dynamic state discovery
//Make unit testing easier
//
//
//TCP Connection Protocols
//Mouse Pointer objects during Drag 
//
//
// 


//this is navie example, need to write a lot of switch statement.see a more detail example in the final part 
//no extensibility, hard to add a new state. Mixed concern
class Program
{
  private static IUnitOfWork unitOfWork;
  public static void Main(string[] args)
  {
    unitOfWork = new XmlUnitOfWork(@"./data.xml");

    WorkItem.Init(unitOfWork);
    
    string cmd, title = null, desc = null, state = null;
    int id;
    try
    {
      cmd = args[0].ToLower();
      id = int.Parse(args[1]);
      if (args.Count() > 2)
      {
        title = args[2];
        desc = args[3];
        state = args[4];
      } 
    
    }
    catch(Exception)
    {
      printUsage();
      return;
    }

    var wi = WorkItem.FindById(id);

    try 
    {
      switch(cmd)
      {
        case "create":
          wi = WorkItem.Create();
          wi.Edit(title,desc);
          wi.Print();
          break;
        case "delete":
          wi.Delete();
          break;
        case "edit":
          wi.Edit(title, desc);
          break;
        case "open":
          wi.Open();
          break;
        case "resolve"
          wi.Resolve();
          break;
        case "verify":
          wi.Verify();
          break;
        case "Print":
          wi.Print();
          break;
        default:
          PrintUsage();
          break;
      }
    }
  }

}


public class WorkItem:IEntity
{
  private static IUnitOfWork unitOfWork;

  public int Id {get; set;}
  public string State{get; set;}
  public string Title{get; set;}
  public string Description{get; set;}

  public void Print(){}

  public void open()
  {
    switch(this.State)
    {
        case "Proposed":
          this.State = "Active";
          break;
        case "Active":
          Console.WriteLine("Work item is already active");
          break;
        case "Resolved":
          Console.WriteLine("Work item is already Resolve");
          break;
        case "Closed":
          Console.WriteLine("Work item is closed and cannot be modified");
          break;
    }
  } 

  public void Delete()
  {
    switch(this.State)
    {
        case "Proposed":
          unitOfWork.Entities.Remove(this);
          break;
        case "Active":
          Console.WriteLine("Work item is in an active state, cannot delete");
          break;
        case "Resolved":
          Console.WriteLine("Work item is already resolved, cannot delete");
          break;
        case "Closed":
          unitOfWork.Entities.Remove(this);
          break;
    }
  }
 
  public void Resolve()
  {
    switch(this.State)
    {
        case "Proposed":
          Console.WriteLine("Work item is in an proposed state, cannot resolved");
          break;
        case "Active":
          this.State = "Resolved";
          break;
        case "Resolved":
          Console.WriteLine("Work item is already resolved ");
          break;
        case "Closed":
          Console.WriteLine("Work item is closed and cannot be modified");
          break;
    }
  }

}






////////////////////////////////////////////////////////////
//Implementation of state pattern/////////////////////
//the bug system.
//state change from: "Proposed->Active->Reoloved->close"
//base on different state, different operation will be performed.
///////////////////////////////////////////////////////

interface ICommands
{
  void Delete();
  void Edit(string title, string desc);
  void Print();
  void SetState(string state);
}

class BaseState
{
    pubic void Print(WorkItem wi)
    {
      console.WriteLine("   Id: {0}", wi.Id);
      console.WriteLine("   State: {0}", wi.State);
      console.WriteLine("   Title: {0}", wi.Title);
      console.WriteLine("   Desc: {0}", wi.Description);
    } 
}

class Active: BaseState, ICommands
{
  private WorkItem owner;
  
  public Active(WorkItem owner)
  {
    this.owner = owner;
  } 

  public bool Delete()
  {
    Console.WriteLine("work Item is already active");
    return false;
  }

  public void Edit(string title, string desc)
  {
    owner.Title = title;
    owner.Description = desc;
  }

  public void Print()
  {
    //call the baseState's print
    Print(owner); 
  }

  public void SetState(string state)
  {
    switch(state)
    {
      case "Active":
        Console.WriteLine("work Item is already active.");
        break;
      case "Proposed":
      case "Resolved":
        owner.State = state;
        break;
      default:
        Console.WriteLine("Work item is in an active state");
        break;
    }
  }
}

public class WorkItem:IEntity, ICommands
{
  private static IUnitOfWork unitOfWork;
  private ICommands stateCommands;
  private string state;

  internal static void Init(IUnitOfWork work)
  {
    unitOfWork = work; 
  }

  internal static WorkItem Create()
  {
    var wi = new WorkItem();
    vi.Id = -1;
    wi.State = "Proposed";
    unitOfWork.Entities.Add(wi);
    return wi;
  }

  internal static WorkItem FindById(int id)
  {
    return (WorkItem)unitOfWork.Entities.FindById(id);
  
  }

  public string State
  {
    get{return state;}
    set
    {
    state = value;
    if(state = "Proposed")
      stateCommands = new Proposed(this); 
    if(state = "Active")
      stateCommands = new Active(this); 
    if(state = "Resolved")
      stateCommands = new Resolved(this); 
    if(state = "Closed")
      stateCommands = new Closed(this); 
    }
  }

  public int Id {get; set;}
  public string Title{get; set;}
  public string Description{get; set;}
  public bool Delete()
  {
    bool canDelete = stateCommands.Delete();
    if(canDelete)
      unitOfWork.Entities.Remove(this);
    return canDelete;
  
  }

  public void Edit(string title, string desc)
  {
    stateCommands.Edit(title, desc); 
  }
  public void Print()
  {
    stateCommands.Print();
  
  }

  pubic void SetState(string newState)
  {
    stateCommands.SetState(newstate);  
  } 



}
class Program
{
  private static IUnitOfWork unitOfWork;
  public static void Main(string[] args)
  {
    unitOfWork = new XmlUnitOfWork(@"./data.xml");

    WorkItem.Init(unitOfWork);
    
    string cmd, title = null, desc = null, state = null;
    int id;
    try
    {
      cmd = args[0].ToLower();
      id = int.Parse(args[1]);
      if (args.Count() > 2)
      {
        title = args[2];
        desc = args[3];
        state = args[4];
      } 
    
    }
    catch(Exception)
    {
      printUsage();
      return;
    }

    var wi = WorkItem.FindById(id);

    try 
    {
      switch(cmd)
      {
        case "create":
          wi = WorkItem.Create();
          wi.Edit(title,desc);
          wi.Print();
          break;
        case "delete":
          wi.Delete();
          break;
        case "edit":
          wi.Edit(title, desc);
          break;
        case "print":
          wi.Print();
          break;
        case "setState"
          wi.SetState(state);
          break;
        default:
          PrintUsage();
      }
    }
  }

}
