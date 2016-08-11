#include <stdio.h>


typedef struct
{
  short first;  //xx__
  int secode;  //xxxx
  short third; // xx__
} Layout;

typedef struct
{
  short first;
  short third;
  int secode;
} Layout2;


typedef union 
{
  int Integer;
  float RealNumber;
}OneThingOrAnother;

int main()
{

  printf("short %d\n", (int) sizeof(short));
  printf("int %d\n", (int) sizeof(int));
  printf("struct %d\n", (int) sizeof(Layout));
  printf("struct %d\n", (int) sizeof(Layout2));

  printf("float %d\n", (int) sizeof(float));
  printf("aggregate %d\n", (int) sizeof(OneThingOrAnother));

 return 0;
}
