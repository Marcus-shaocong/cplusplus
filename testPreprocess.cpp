#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;



#define TEST_MACRO(errorCode, TaskName , Session, task, ...)  \
{\
    errorCode = build ## TaskName ## Task(Session, task, __VA_ARGS__);\
}

int buildDeleteMigrationTask(int a, int b)
{
  cout<<"string a "<< a << "string b "<<b<<endl;
  return -1;
}

int main()
{
  int errorCode; 
  int session = 10;
  int task = 30;
  int c = 1;
  int d = 2;
TEST_MACRO(errorCode, DeleteMigration, session, task, ... );

cout <<"errorCode:" << errorCode<<endl;
return 0;
}
