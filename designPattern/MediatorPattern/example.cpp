
/*
define an object that encapsulates how a set of objects interact.
Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and it lets you vary their interaction independently

Components
Colleagues:
Individual components that need to communicate with each other
implement the same base type(abstract class or interface)
Have know knowledge of the mediator component.
Mediator:
the centrailized oomponent that managed communication between the colleague components
Implement  an abstraction that is used by the Colleague components


Advantages:
Hides all coordination between colleagues
Decoupled colleagues
Mediator's one-to-many relationship with colleagues is prefered to colleagues relating in many-to-many fashion

Disadvantages:
The Mediator can become very large and very complicated as more colleagues are handled
*/

public class Program

{
  static void main(string[] args)
  {
  var yytCenter = new YytCenter();
  var flight1 = new Airbus32("Ac159", yytCenter);
  var flight1 = new Boeing737200("Ws203", yytCenter);
  var flight1 = new Ebraer190("Ac602", yytCenter);
  
  flight1.Altitude += 1000;
    
  } 

}


public interface IAirTrafficControl
{
    void ReceiveAircraftLocation(Aircraft location);
    void RegisterAircraftUnderGuidance(Aircraft aircraft);
}

//this is our Mediator class, work as a central control
public class YytCenter : IAirTrafficControl
{
  pirvate readonly IList<Aircraft> _aircraftUnderGuidance = new List<Aircraft>();
  public void ReceiveAircraftLocation(Aircraft reportingAircraft)
  {
    foreach(var  currentAircraftUnderGuidance in _aircraftunderGuidance.Where(x=>x != reportingAircraft))
    {
      if(Math.Abs(currentAircraftUnderGuidance.Altitude = reporingAircraft.Altitude))
      {
        reportingAircraft.Climb(1000);
        //Implementation of the communation, this  might need to have a lot of if statement or switch statement.
        currentAircraftUnderGuidance.WarnOfAirspaceIntrusionBy(reportingAircraft);

      }
    }    

  }

  public void RegisterAircraftUnderGuidance(Aircraft aircraft)
  {
    if(!_aircraftUnderGuidance.Contains(aircraft))
    {
      _aircraftUnderGuidance.Add(aircraft); 
    }
  }

}

public abstract class Aircraft
{

IAirTrafficControl _atc;
private int _currentAltitude;

protected Aircarafet(string callSign, IAirTrafficControl atc)
{
  _atc = atc;
  CallSign = callSign;
  _atc.RegisterAircraftUnderGuidance(this);

}

public abstract in Ceiling {get;}
public string CallSign Ceiling {get;}

public int Altitude{
  get{ return _currentAltitude;}

  set{
     _currentAltitude = value;
     //when the Colleague class's Altitude is set. air traffic control is notify which is our Mediator class
     _atc.ReceiveAircraftLocation(this);
  }
  
  public void WarnOfAirspaceIntrusionBy(Aircraft  reportingAircraft)
  {
    //do something in response to the warning. 
  }

}

public void Climb(int heightToClimb)
{}

public override bool Equals(object obj)
{}

public override int GetHaahCode()
{
  return CallSign.GetHashCode();
}

}

//Airbus321, Boeing73700 is our Colleague class, Mediator is inhereit from IAirTrafficControl 
//so we have the colleague class know about the Mediator class.
public class Airbus321: Aircraft
{
  public override int Ceiling
  {
    get {return 35000;} 
  } 
  public Airbus321(string callSign, IAirTrafficControl atc):base(callSign, atc)
  {


  } 
} 

public class Boeing737200: Aircraft
{
  public override int Ceiling
  {
    get {return 35000;} 
  } 
  public Boeing737200(string callSign, IAirTrafficControl atc):base(callSign, atc)
  {


  } 
}

public class Boeing737200: Aircraft
{
  public override int Ceiling
  {
    get {return 35000;} 
  } 
  public Boeing737200(string callSign, IAirTrafficControl atc):base(callSign, atc)
  {


  } 
} 
