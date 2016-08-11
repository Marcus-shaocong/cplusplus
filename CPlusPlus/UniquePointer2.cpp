

#include <iostream>
#include <memory>
using namespace std;

class Address
{
public:
  string name;
  Address(const string & name)
    :name{name}
  {
    cout<< name <<" created" <<endl; 
  
  }

  ~Address()
  {
    cout<< name << " destroyed" <<endl; 
  }
};

class Person
{
  public:
  shared_ptr<Address> address;

  Person(string const & city)
  {
    address = make_shared<Address>(city); 
    cout<< "Created person" <<endl; 
  }

  ~Person()
  {
  
    cout<< "destroy person" <<endl; 
  }

};

unique_ptr<Address> create_address(string const & city)
{
 return unique_ptr<Address>(new Address(city));
}


struct Hen
{
   unsigned id;
   float eggs;

   explicit Hen( unsigned id_, float eggs_)
     :id(id_), eggs(eggs_)
   {}
};

unique_ptr<Hen> create_hen(unsigned id, float eggs)
{
 return unique_ptr<Hen>(new Hen {id, eggs});
}

 unique_ptr<Hen> UpdateHen(unique_ptr<Hen> hen)
{
    hen->id = 4;
    return hen;
}

int main()
{
  //a is a unique pointer, cannot be copy construct or copy assignment.
  auto a = create_hen(2, 3.9f);

  cout<<"a "<< a->id << " eggs" << a->eggs <<endl;
unique_ptr<Hen> c(a.release());
  //a is a unique pointer, cannot be copy construct or copy assignment. but we can use the move semantic to acchieve this.
   auto b = UpdateHen(move(c)); 
   cout<<"b "<< b->id << " eggs" << b->eggs <<endl; 
};


