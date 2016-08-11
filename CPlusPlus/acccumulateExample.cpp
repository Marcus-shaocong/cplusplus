#include <numeric>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
  vector<int>  testVec = {1, 2, 3, 4, 5};
  
  int total = std::accumulate(begin(testVec), end(testVec), 0);

  int total2 = std::accumulate(begin(testVec), end(testVec),0, [](int a, int b){ return a+b;});
  cout<< " total " << total << endl;
  cout<< " total " << total2 << endl;
return 0;
}
