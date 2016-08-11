

#include <iostream>
#include <string>
#include <memory>
#include <cassert>
using namespace std;

struct Person
{
  string firstname, lastname;
  /* Person() */
  /*   :firstname{}, lastname{} */
  /* {} */

  Person(string first, string second)
    :firstname{first}, lastname{second}
  {
    cout<<"construct "<< firstname << endl; 
  }

  ~Person()
  {
    cout<<"destructor"<< firstname <<endl; 
  }
};

int main()
{
  /* auto sp = shared_ptr<int> {}; */

  /* assert(!sp); */
  /* cout<<" user_cout " << sp.use_count()<<endl; */
  /* assert(sp.use_count() == 0); */
  /* assert(!sp.unique()); */
  /* cout<<" unique" << sp.unique()<<endl; */

  /* sp = make_shared<int>(124); */
  /* cout<<" user_cout " << sp.use_count()<<endl; */
  /* assert(sp.use_count() == 1); */
  /* assert(sp.unique()); */
  /* cout<<" unique " << sp.unique()<<endl; */

  /* auto sp2 = sp; */
  /* assert(sp.use_count() == 2); */
  /* cout<<" user_cout " << sp.use_count()<<endl; */
  /* cout<<" unique " << sp.unique()<<endl; */
  /* assert(!sp.unique()); */

  /* int copy = *sp; */
  /* int & ref = *sp; */
  /* int * ptr = sp.get(); */
  
  /* assert(sp.get() == sp2.get()); */
  /* cout<<" sp" << sp.get()<< " sp2 "<<sp2.get()<<endl; */
  /* assert(sp == sp2); */
  /* cout<<" sp" << sp<< " sp2 "<<sp2<<endl; */


  auto sp = make_shared<Person>(Person{"John", "jerry"});
  cout<<"first " << sp->firstname << " last " << sp->lastname <<endl; 
  cout<<"user account " << sp.use_count()<<endl;
  sp = make_shared<Person>(Person("herry", "may"));
  cout<<"first " << sp->firstname << " last " << sp->lastname <<endl; 
  cout<<"user account " << sp.use_count()<<endl;
  return 0;
};


