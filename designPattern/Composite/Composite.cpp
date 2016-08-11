// When to Use
// Groups or collections? Treat the same group as the same individual
// Can you add an interface?
// Trees
// Distribution
//
// composite objects into tree structures to represent part-whole hierarches.
// Composite lets clients treat individual objects and compositions of objects uniformly(GOF)
// the idea is treat the Leaf and composite the same. 
//
//
//Example: send email to people without group
//we can send it individually or we can make it as group
//
// Developers: a, b, c, d
// other : mary
//


//this example is to split the gold to individual or group. 
internal interface Party
{
 int Gold{get; set;}
 void Stats();
}
public class Person : Party
{
  public string name{get; set;}
  public int Gold{get; set;}

  public void Stats()
  {
    Console.WriteLine("{0} has {1} gold coins.", Name, Gold); 
  }
}

public class Group :Party
{
  public string Name{get; set;}
  public List<Party> Members{get; set;}

  public Group()
  {
    Members = new List<Party>(); 
  }

  public int Gold 
  {
    get{
      int totolGold = 0;
      foreach(var member in Members)
      {
        totalGold += member.Gold; 
      }
      return totolGold;
    }

  set
  { 
    var eachSplit = value/Members.Count;
    var leftOver = value%Members.Count;
    foreach(var member in Members)
    {
      member.Gold += eachSplit + leftOver;
      leftOver = 0;
    }
     
  }
  }

  public void Stats()
  {
      foreach(var member in Members)
      {
        member.Stats(); 
      }
  }
}


class Program
{
  static void main(string[] args)
  {
    int goldForKill = 1023;
    Console.WriteLine("You have killed the Giant IE6 Monster and gained {0} gold!", goldForKill);

    var joe = new Person{Name = "Joe"}; 
    var jake = new Person{Name = "Jake"}; 
    var emily = new Person{Name = "Emily"}; 
    var sophia = new Person{Name = "Sophia"}; 
    var brian = new Person{Name = "Brian"}; 
    var developers = new Group{Name = "developers", Members = {joe, jake, emily}};

    var individuals = new List<Person> {sophia, brian};
    var groups = new List<Group> {developers};

    var totalToSplitBy = individuals.Count + groups.Count;

    var amountForEach = goldForKill/totalToSplitBy;
    var leftover = goldForKill % totalToSplitBy;

    foreach(var individual in individuals )
    {
      individual.Gold += amountForEach + leftOver;
      leftOver = 0;
      individual.Stats();
    }

    foreach(var group in groups )
    {
        var amountForEachGroupMember = amountForEach/group.Members.Count;
        var leftOverForGroup = amountForEachGroupMember % group.Members.Count;
        foreach(var member in group.Members )
        {
          member.Gold += amountForEachGroupMember + leftOverForGroup;
          leftOverForGroup = 0;
          member.Stats();
        }
    }

    Console.ReadKey();
  }

}


////////////////Using the composite pattern to refactoring the code/////

class Program
{
  static void main(string[] args)
  {
    int goldForKill = 1023;
    Console.WriteLine("You have killed the Giant IE6 Monster and gained {0} gold!", goldForKill);

    var joe = new Person{Name = "Joe"}; 
    var jake = new Person{Name = "Jake"}; 
    var emily = new Person{Name = "Emily"}; 
    var sophia = new Person{Name = "Sophia"}; 
    var brian = new Person{Name = "Brian"}; 
    //with the composite pattern, we can add a new developers here
    var OldBob = new Person{Name = "old bob"}; 
    var newBob = new Person{Name = "new bob"};
    var bobs = new Group{Members = {oldBob, newBob}};
    //add the bobs to the development easily with the composite pattern 
    var developers = new Group{Name = "developers", Members = {joe, jake, emily, bobs}};
    //we make group and person in the a unifiled structure Party
    var Parties = new List<Party> {developers, sophia, brian};

    var totalToSplitBy = Parties.Count;

    var amountForEach = goldForKill/totalToSplitBy;
    var leftover = goldForKill % totalToSplitBy;

    foreach(var partyMember in Parties )
    {
      partyMember.Gold += amountForEach + leftOver;
      leftOver = 0;
      partyMember.Stats();
    }
    
    //setting the root element to achieve the same purpuse 
    var parties = new Group{Members = {developers, sophia, brian}};
    parties.Gold += goldForKill;
    parties.Stats();
    Console.ReadKey();
  }

}
