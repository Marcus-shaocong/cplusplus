

// Avoiding redundancy when storing data
// Flyweight pattern 
// theory:
// A space optimization technique that let us use less memory by storing externally the data associated with similar objects;
//
//
// E.g.
// A game 
// Plenty of users with identical first/last names
// No sense in storing same first/last name over and over again
// Store a list of names and pointers to them
//
// E.g. bold or italic text in the console
// Don't want each character to have an extra formatting character
// Operate on ranges(e.g. line, start/end)
//
//


#include <cstdio>
#include <iostream>
#include <string>
#include <boost/bimap.hpp>
#include <boost/flyweight.hpp>

using namespace boost;

using namespace std;


typedef int key;
struct User
{
  User(const string & first_name, const string & last_name)
    :first_name{add(first_name)}, last_name{add(last_name)}
  {
  }
  const string & get_first_name() const
  {
    return names.left.find(first_name)->second; 
  }

  const string& get_last_name() const
  {
    return names.left.find(last_name)->second; 
  }

  friend ostream & operator <<(ostream& os, const User& obj)
  {
    return os <<"first name: " <<obj.first_name<< " " << obj.get_first_name()
      <<"last name: " <<obj.last_name<< " " <<obj.get_last_name();
  }

  protected:
  static bimap<key, string>  names;
  static int seed;
  static key add(const string&s)
  {
    auto it = names.right.find(s);
    if(it == names.right.end())
    {
      key id = ++seed;
      names.insert(bimap<key,string>::value_type(seed, s));
      return id;
    }
    return it->second;
  }
  key first_name, last_name;
};

int User::seed = 0;
bimap<key,string> User::names{};


struct User2
{

    flyweight<string> first_name, last_name;
    User2(const string& first_name, const string & last_name)
      :first_name{first_name}, last_name{last_name}
    {}
  
  friend ostream & operator <<(ostream& os, const User2& obj)
  {
    return os <<"first name: " <<obj.first_name 
      <<"last name: " <<obj.last_name<<endl;;
  }

};


int main()
{
  User2 john_doe{"John", "Doe"};
  User2 jane_doe{"jane", "Doe"};

  cout<<"john " <<john_doe<<endl;
  cout<<"jane "<<jane_doe<<endl;

  cout<<boolalpha<<(&jane_doe.last_name.get() == &john_doe.last_name.get())<<endl;
  return 0;
}
