#include <string>
#include <iostream>

#include <sstream>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
using namespace std;


struct Person
{

  string name;
  string street;
  int age;
  bool isSingle;
  Person(){} 
  Person(string name_, string street_, int age_):name(name_),street(street_),age(age_)
  {
    isSingle = false;
  }
  
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    ar & name;
    ar & street;
    ar & age;
    ar & isSingle;
  }

  friend class boost::serialization::access;
};

int main()
{
  vector<Person> v;
  vector<Person> v2;
  v.emplace_back(Person {"marcus1", "jerry1", 43});
  v.emplace_back(Person {"marcus2", "jerry2", 44});
  v.emplace_back(Person {"marcus3", "jerry3", 45});
  v.emplace_back(Person {"marcus4", "jerry4", 46});
  v.emplace_back(Person {"marcus5", "jerry5", 47});
  v.emplace_back(Person {"marcus6", "jerry6", 48});
  //cout<<"P: " << p.name << " P street:"<<p.street<< " P age: " << p.age << " P isSingle : " << p.isSingle <<endl;

  ostringstream sstr;
  boost::archive::text_oarchive ar(sstr);
  ar << v;
  string ostr = sstr.str();

  //Person p2;
  std::istringstream istr(ostr);
  boost::archive::text_iarchive iar(istr);
  iar >> v2;

  for( auto p2 :v2)
  {
      cout<<"P2: " << p2.name << " P2 street:"<<p2.street<< " P2 age: " << p2.age << " P2 isSingle : " << p2.isSingle <<endl;
  }
  return 0;

}
