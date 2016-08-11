#include <time.h>
#include <iostream>
#include <unistd.h>
using namespace std;
typedef unsigned long uint64_t;
typedef unsigned int uint32_t;

uint64_t nowInMs()
{
  timespec currTime;
  clock_gettime(CLOCK_MONOTONIC, &currTime);
  uint32_t NANOSEC_IN_MSEC = 1000000UL;
  uint32_t MSEC_IN_SEC = 1000UL;

  uint64_t nanoseconds = currTime.tv_nsec;
  uint64_t seconds = currTime.tv_sec;
  uint64_t ms = seconds * MSEC_IN_SEC + nanoseconds / NANOSEC_IN_MSEC;
  return(ms);
}

int main()
{
  uint64_t now = nowInMs();

  cout<<" now " << now << endl;
  sleep(5);
uint64_t now2 = nowInMs();
  
  cout<<" now " << now2-now << endl;
  
  return 0;
}
