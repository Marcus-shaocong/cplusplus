//
//Intent
//
//Without violating encapsulation, capture and externalize an object's internal state so that the object
//can be restored to this state later.
//
//The memento pattern involves two object: the originator and the caretaker. The originator represents the 
//object whose state is being tracked. The caretaker performs operations on the originator, but needs to 
//be able to undo the operations.
//
//
// *applicability
// Use the Memento Pattern when:
// You need to be able to track the state of an object or your application and restore previous states as needed.
// you want to abstract and reuse the Undo/Redo functionality
// Follow SRP and Don't Repeat Yourself(DRY)
// Learn more in the Principles of Object Oriented Development course
//
// You do not wish to break encapsulation and expose your classes' internal state globally
//
//
// *How it Gets Used
// The memento itself simply holds the state of the Originator.
// Ideally, only the originator should have access to the internal details of its state within the memento.
// The Caretaker's interface to Memento should not allow it to access the internal state of the Originator.
//
// The Originator can create mementos or restore its state given a memento
//
// *The Undo/Redo Stack
// Multiple Undo/Redo is ofter implemented using a Stack
// When a chage  is performed: Amemento containing the current state is added to the Undo stack
// When an Undo operation is performed:
// The current state is replaced with the state of the memento removed from the Undo stack.
// if Redo is implemented, the current state is stored in a Redo stack
//
// When a Redo operation is performed:
// the current state is replaced with the state of the memento removed from the Redo stack
// The current state is stored in the Undo stack
//
//
//

//This is a painting example, when we accidently paint a unnecessary step, we want to undo the operation
namespace Paint
{

  public partial class Mainwindow: window
  {
    private readonly Stack<Imemento> states = new Stack<IMemento>();
    public MainWindow()
    {
      InitializeComponent();  
      //this is the bind the ctrl+z undo command to the onExecuteCommnads function
      CommandBindings.Add(new CommandBinding(ApplicationCommands.Undo, OnExecuteCommands));
      
      InkCanvasWithUndo1.MouseUp += InkCanvasWithUndo1_MouseUp;
      
      //Initialize with empty state
      StoreState();
    }

    private void InkCanvasWithUndo1_MouseUp(object sender, MouseButtonEventArgs e)
    {
      StoreState(); 
    }

    private void OnExecuteCommnads(object sender, ExecuteRoutedEventArgs e)
    {
      var myWindow = (MainWindow)sender;
      if(e.Command == ApplicationCommands.Undo)
      {
        //if it is an undo command, route the Undo  command
        myWindow.Undo(sender, e);  
      } 
    }

    private void Undo(object sender, ExecutedRoutedEventArgs executeRoutedEventArgs)
    {
      if(priorStates.Count > 1)
      {
        //discard current state
        priorStates.Pop();
        var lastState = priorStates.Peek();
        InkCanvasWithUndo1.Setmemento(lastState);
       }
    label1.Contnt = states.Count; 
    }

    private void StoreState()
    {
      var memento = InkCanvasWithUndo1.CreateMemento();
      states.Push(memento);
      label1.Content = states.Count;
    } 

  }
 
  //The IMemento is use to store the state,here the state is the strokes 
  public interface IMemento
  {
    object State{get; set;} 
  }


  public class InkCanvasWithUndo: InkCanvas
  {
    public IMemento CreateMemento()
    {
        //The storks is your last stroke of your painting.
        Stroke[] copy = Strokes.ToAray(); 
        //Here we create a state by passing it as the Stroke array
        return new InkCanvasMemento(){State = copy};
    }


    public void SetMemento(IMemento memento)
    {
      Strokes = new StrokeCollection((Stroke[])memento.State); 
    }
    //The InkCanvasMemento is the state
    public class InkCanvasMemento: IMemento
    {
      public object State{get;set;} 
    }
  
  }


  
}
