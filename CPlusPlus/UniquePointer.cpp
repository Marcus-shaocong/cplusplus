

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


int main()
{
  // a is a unique pointer, cannot be copy construct or copy assignment.
  //auto a = create_address("Paris");
  //below statement is wrong, becaue the unique pointer cannot be copy construct or copy assignment.
  //auto v(a);
  //
  shared_ptr<Address> a; 
  {
  Person p("paris");
  a = p.address;
  }
  cout<<a->name<<endl;
};


