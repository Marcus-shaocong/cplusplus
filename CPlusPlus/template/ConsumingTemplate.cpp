#include <iostream>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> trie;

trie sum_product_avg(int a, int b, int c)
{
  trie t{a+b+c, a*b*c, (a+b+c)/3};
  return t;
}

void consuming_templates()
{

  int a =2, b =3 , c=4;
  auto result2 = sum_product_avg(a, b,c);

  cout<<" Sum = "<< get<0>(result2) << "product = "<< get<1>(result2) << 
    "avg = " << get<2>(result2) <<endl;
}


int main()
{
  
  consuming_templates();

return 0;
}
