#include <iostream>
#include <string>
#include "x86intrin.h"

using namespace std;

string get_cpu_name()
{
  unsigned int data[4] = { 0 };
  _asm
  {
    cpuid;
    mov data[0], ebx;
    mov data[4], edx;
    mov data[8], ecx;
  }

  return string((const char*) data);
}

void assember()
{
  cout <<"CUP id" << get_cpu_name() <<endl;
}

int main()
{
  assember();
  return 0;
}






