#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <vector>
#include <algorithm>

using namespace std;

std::mutex mu;

void shared_print(string msg, int id)
{
  std::lock_guard<mutex> locker(mu);
  cout<<msg<<id<<endl;
}


void function_1()
{
  for(int i=0; i>-100; i--)
    shared_print(string("From t1: "),i);
}

class Fctor
{
  void operator() (std::string& msg)
  {
    cout<<"t1 says:" <<msg<<endl; 
  }
};

int main()
{
  std::vector<std::thread> workers;
  /* std::thread t1(&function_1 ); */
  for(int i =0; i<10; i++)
  {
    workers.push_back(std::thread([i](){cout<<"Hi from thread"<<i<<endl;}));
  }
  std::cout<<"hi from main"<<endl;
  std::for_each(workers.begin(),workers.end(),[](std::thread &th){th.join();});
  /* for(int i=0; i<100; i++) */
  /*   shared_print(string("From main: "),i); */
  /* t1.join(); */

  return 0;

}
