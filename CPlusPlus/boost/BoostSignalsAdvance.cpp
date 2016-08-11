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
// compile
// g++ -std=c++0x BoostSignals.cpp -o test -I /home/c4dev/nextUnityBugFix/uemcli/obj/KHDATAPATH_DEBUG/rpm_install/usr/include

#include <iostream>
#include <string>

#include<boost/signals2.hpp>
#include<boost/bind.hpp>
#include<boost/smart_ptr.hpp>

using namespace boost;
using namespace std;
using namespace boost::signals2;

template <typename T> class INotifyPropertyChanged
{
  public:
    signal<void(const T*, string)> PropertyChanged;
};

class Player : public INotifyPropertyChanged<Player>
{
  int numberOfGoals;
  int age;
  public:
    string name;

    int GetAge() const {return age;}
    void PutAge(int value)
    {
     if( value == age ) return;
     age = value;
     PropertyChanged(this, "Age");
    }

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

template<typename T> struct average
{
  typedef T result_type;
  template <typename II> T operator()(II first, II last) const
  {
      if(first == last) return T();
      float sum = 0.0;
      int count = 0;
      while(first != last)
      {
        sum += *first++;
        count++;
      }
      return sum / count;
  }
};

int main()
{
  Player p("John");

  p.PropertyChanged.connect([](const Player* p, string value){
        cout<<p->name<<"'s " << value <<" has changed to " << p->GetAge()<<endl;

      });

  p.PutAge(30);

  /*
  signal<float(float, float)> s;

  s.connect([](float a, float b) {return a+b;});
  s.connect([](float a, float b) {return a*b;});
  
  //this will print 12, because the last value of the slot is 3*4 =12
  cout<<*s(3,4)<<endl;

  */

  /*
  signal<float(float, float), average<float>> s;
  s.connect([](float a, float b) {return a+b;});
  s.connect([](float a, float b) {return a*b;});
  //this will reutn the result of average
  cout<<s(3,4)<<endl;
  */

  /*
   * by using connect_extened, we can decide when we would disconnect
   * the connnect. Here we generate 100 number but we break the connection
   * at the number 6;
   */
  /*
  signal<void(int)> values;
  values.connect_extended([](const connection & conn, int value){
        static int count = 0;
        if(++count > 6)
            conn.disconnect();
        else
            cout <<"got a value of "<< value<<endl;
      });


  srand((unsigned)time(nullptr));
  for(size_t i=0; i<100; i++)
  {
    values(rand()); 
  }
  */

   return 0;
}
