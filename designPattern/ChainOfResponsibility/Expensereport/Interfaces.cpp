namespace ApprovalCommon
{
    public interface IExpenseReport
    {
      Decimal Total{get;} 
    }

    public interface IExpenseApprover
    {
      ApprovalResponse ApproveExpense(IExpenseReport expenseReport);

    } 

    public enum ApprovalResponse
    {
      Denied,
      Approved,
      BeyondApprovalLimit,
    }

}

i

public class ExpenseReport : IExpenseReport
{
  public ExpenseReport(Decimal total)
  {
    Total = total; 
  }

  public decimal Total
  {
    get;
    private set;
  }
}


public class Employee :IExpenseApprover
{
  public Employee(string name, Decimal approvalLimit)
  {
    Name = name;
    _approvalLimit = approvalLimit;
  } 

  public string Name{get; private set;}

  public ApprovalResponse ApproveExpense(IExpenseReport expenseReport)
  {
    return expenseReport.Total > _approvalLimit ? ApprovalResponse.BeyondApprovalLimit: ApprovalResponse.Approved; 
  }
  private readonly Decimal _approvalLimit;
}


interface IExpenseHandler
{
    ApprovalResponse Approve(IExpenseReport expenseReport);
    void RegisterNext(IExpenseHandler next);
}

class ExpenseHandler: IExpenseHandler
{
   public ExpenseHandler(IExpenseApprover expenseApprover)
   {
      _approver = expenseApprover; 
      _next =EndOfChainExpenseHandler._instance; 
   }

   public ApprovalResponse Approve(IExpenseReport expenseReport)
   {
      ApprovalResponse response = _approver.ApproveExpense(expenseReport);
      if(response == ApprovalResponse.BeyondApprovalLimit)
      {
        return _next.Approve(expenseReport); 
      }
      return response;
   }
  
   
   public void RegisterNext(IExpenseHandler next)
   {
      _next = next; 
   }
   private readonly IExpenseApprover _approver;
   private IExpenseHandler _next;
}

class EndOfChainExpenseHandler: IExpenseHandler
{
  private EndofChainExpenseHandler(){}

  public static EndofChainExpenseHandler Instance
  {
    get {return _instance;} 
  }

  public ApprovalResponse Approve(IExpenseReport expenseReport)
 {
   return ApprovalResponse.Denied;
 }
  public void RegisterNext(IExpenseHandler next)
  {
    throw new InvalidOperationException("End of chain handler must be the end of chain!"); 
  }

  private static readonly EndofChainExpenseHandler _instance = new EndofChainExpenseHandler();
}


static void main()
{
  ExpenseHandler william = new ExpenseHandler(new Employee("William Worker", Decimal.Zero));
  ExpenseHandler mary = new ExpenseHandler(new Employee("Mary Manager ",new  Decimal(1000)));
  ExpenseHandler victor = new ExpenseHandler(new Employee("Victor Vicepres",new  Decimal(5000)));
  ExpenseHandler paula = new ExpenseHandler(new Employee("Paula President ",new  Decimal(20000)));
  
  william.RegisterNext(mary);
  mary.Registernext(victor);
  victor.RegisterNext(paula);

  Decimal expenseReportAmount;
  while(consoleInput.TryReadDecimal("Expense report amount:", out expenseReportAmount))
  {
    IExpenseReport expense = new ExpenseReport(expenseReportAmount);
    ApprovalResponse response = william.Approve(expense);
    Console.WriteLine("The request was {0}.", response);

  }


  //this is not a chain of responsibility solution
  List<Employee> managers= new List<Employee>
  {
    new Employee("William Worker", Decimal.Zero),
    new Employee("Mary manager", new Decimal(1000)),
    new Employee("Victor Vicepres", new Decimal(5000)),
    new Employee("Paula President", new Decimal(20000)),
  };

  Decimal expenseReportAmount;
  while(consoleInput.TryReadDecimal("Expense report amount:", out expenseReportAmount))
  {
    IExpenseReport expense = new ExpenseReport(expenseReportAmount);

    bool expenseProcessed = false;
    foreach( Employee approver in managers)
    {
        ApprovalResponse response = approver.ApproveExpense(expense);

        if(response != ApprovalResponse.BeyondApprovalLimit)
        {
          Console.WriteLine("The request was {0}.", response);
          expenseProcessed = true;
          break;
        }
    }

    if(!expenseProcessed)
    {
      Console.WriteLine("No one was able to approve your expense."); 
    }
  }


  //this one is a chi
}
