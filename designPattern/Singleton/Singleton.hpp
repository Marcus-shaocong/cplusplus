#pragma once
#include <string>

#include <iostream>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

class SingletonDatabase
{
  SingletonDatabase()
  {
    std::cout << "Initializing database" << std::endl;

    std::ifstream ifs("capitals.txt");
    std::string s, s2;
    while(getline(ifs, s))
    {
      getline(ifs,s2);
      int pop = boost::lexical_cast<int>(s2);
      capitals[s] = pop;
    }
    instance_count++;

  }
  std::map<std::string, int> capitals;
  static SingletonDatabase instance;
public:
static int instance_count;
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;

static  SingletonDatabase & get()
{
  static SingletonDatabase  db;
  return db;
}

int get_population(const std::string name)
{
  return capitals[name];
}
    /*
static  SingletonDatabase * get_instance()
{
  if(!instance)
  {
    instance = new  SingletonDatabase();
  }
  return instance;
}
*/
};

int SingletonDatabase::instance_count = 0;

struct SingletonRecordFinder
{
  int total_population(std::vector<std::string> names)
  {
    int result = 0;
    for(auto& name: names)
    {
      result +=SingletonDatabase::get().get_population(name);
    }
    return result;
  }
};

