#include "Singleton.hpp"
#include <iostream>

using namespace std;
int main (int ac, char* av[])
{
  auto & db = SingletonDatabase::get();

  auto & db2 = SingletonDatabase::get();

  cout<<"db1 instance cout"<<db.instance_count<<endl;
  
  cout<<"db2 nstance cout"<<db2.instance_count<<endl;
  SingletonRecordFinder rf;
  std::vector<std::string> names{"Seoul", "Mexico City"};
  int tp = rf.total_population(names);
  cout<<"tp "<<tp<<endl;
}
