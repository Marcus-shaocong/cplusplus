#include <iostream>
typedef unsigned long long cmd_error_t;

#define CMD_ERR(x,y,z) (((((( cmd_error_t ) z) << 16) | (y)) << 16) | (x))

using namespace std;

int main()
{

int x = 8;

unsigned long long a = 8;
unsigned long long c = a << 16;
unsigned long long d = c | 0;
unsigned long long e = d << 16;
cout<<"c is "<<c<<" d is :"<<d<<" E is "<<e<<endl;
unsigned long long b = CMD_ERR(x,0,0);
cout<<"CMD_error " <<CMD_ERR(x,0,0)<<endl;
std::cout<<"sizeof b" <<sizeof(unsigned long long)<<" b is :"<<b;

return 0;
}
