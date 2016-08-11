//
// Boost signals2
//Observer pattern a.k.a. Events
//
//
//Component A wants to be notified when component B does something 
//know when a value has changed and updating the UI
//
//Publish & subiscribe mechanism
//
//A class can publish a particular event, e.g. "NameChanged"
//other classes can choose to receive notifications of when a name is changed
//when the name is actually changed, all subscribers get notified multicaset.
//
//
//
//  1. boost::signal<T>
//  A signal that cane be sent to anyone willing to listen
//  T is the type of the slot function
//
//  2. A slot is the function that receives the signal
//  Ordianry functin, Functor, std::function, Lambda
//
//  3. Connection
//  signal<void()> s;
//  auto c = s.connect([](){cout<<"text"<<endl;})
//
//  4. more than one slot can be connected to a signal
//
//  5. Disconnection
//  c.disconnect();
//
//  6. Slots can be blocked: Temporarily disabled but not permanently disconnected,
//  Used ot prevent infinite recursion
//  shared_connection_block(c);
// Unblocked when block is destroyed(e.g.out of scope) or explicitly via block.unblock();
//
//
//  7. Slots anc have priority
//  A single integer or at_front/at_back
//  Passed as parameter to connect()
//
//  8. Scoped connection
//  scoped_connection(c)
//  Connects signal and slot until it goes out of scope
//
//  9. Disconnect specific slot
//  c.disconnect(&foo);
//  Object must have accessible == operator
//
//  10 Lifetime tracking
//
//  keep the connection alive only while the source is alive
//  explicitly create slot_type and use track()
//
//  slot_type is derived from the signal template argument
//  signal<T>::slot_type
//  can be passed as parameter
//  singal owner can implement a connect() function
//
//  Disconnections occur due to
//  signal.disconnect()
//  connection.disconnect()
//  Tracked object destroyed
//  Signal destroyed
//
//
//  Advanced Topics
//  i) slot return values
//   A slot function may return value
//   the result of firing a signal is a pointer to the last value
//   A signal can define a custom function 'combiner' to process all those return values
//  ii) Postconstructors and predestructors
//  An object in a shared_ptr cannot setup its own tracking in a ctor
//  deconstruct()
//
//  iii) Accessing connection in the slot
//  connect_extended
//
//  iiii) Bonus: notifications on property changes a.k.a
//  INotifyPropertyChanged
//
//
//
//

#include <iostream>
#include <string>

#include<boost/signals2.hpp>
#include<boost/bind.hpp>
#include<boost/smart_ptr.hpp>

using namespace boost;
using namespace std;
using namespace boost::signals2;


class Player
{
  int numberOfGoals;
  public:
    string name;

    Player(string name):name(name){numberOfGoals=0;}
    typedef signal<void(string, int)> SignalType;
    SignalType Scores;

    void Score()
    {
      numberOfGoals++;

      //fire the signal
      Scores(name, numberOfGoals);
    
    }

};


class Coach 
{
  public:
    void PlayerScored(string name, int goal)
    {
      cout<<"well done, " <<name<<goal <<endl; 
    }
};

void third()
{
  cout<<"third" <<endl;
}
int main()
{
  /* 
   *Use shared_ptr and slot_type enable tracking to automatically close the connection when objects die
   */
  /*
  {
    auto coach = boost::make_shared<Coach>();
    p.Scores.connect(Player::SignalType::slot_type
      (&Coach::PlayerScored, coach.get(), _1, _2).track(coach)
      );
     p.Score();
  }
  p.Score(); //in this case, this line would not call because the coach is out of scope 
  */

/*
  //Example 2 begins here, by using a class member function as a slot
  Player p("John");
  Coach coach;
  p.Scores.connect(boost::bind(&Coach::PlayerScored, &coach, _1, _2)); 

  p.Score(); 
 */ 
  
  // Example 3, disconnect the connection by using connect.disconnect or
  // siganl's disconnect_all_slots;
  // by using shared_connection_block can also temporarily disconnect the slot
  Player p("John");
  auto c = p.Scores.connect(
      [](string name, int count )
      {
         cout<<"Player "<< name<<" has scored "<<count<< " goals already"<<endl;
      });

  p.Score();
  p.Score();
  p.Score();
  //c.disconnect();
  // to disconnect all the slots
  //p.Scores.disconnect_all_slots();
  //
  //
  {
    shared_connection_block b(c); 
    p.Score();
    p.Score();
  }
  p.Score();
  p.Score();
  p.Score();



  //Example 4, slot priority, at the first parameter of the connect function to
  //set up the prority. the less the value is, the high the priority
  /*signal<void()> s;
  s.connect(1,[](){cout<<"first"<<endl;});
  s.connect(0,[](){cout<<"second"<<endl;});
  s();
  */

/*  
  //Example 5, the socped connect, in this case, onlye second will print out, because the connect is out of scope
  signal<void()> s;
  //by default, if no priority is given, the third will be queue at the end of the queue
  s.connect(third);
  {
   auto c = s.connect(1,[](){cout<<"first"<<endl;});
   scoped_connection sc(c);
   s.connect(0,[](){cout<<"second"<<endl;});
   s(); // will print first and second;
  }
  cout<<"======"<<endl;
  //explicitly disconnect one slot
  s.disconnect(third);
  s();
 */ 
return 0;
}
