
//Stable sort
//
//Sort, then sort again by another property
//should "ties" on the second sort be in their original order?
//You decide
//
//
//
//Find the largetst, or Smallest
//
//max_element()
//min_element() 


#include <iostream>
#include <vector>

#include <algorithm>

#include <cmath>
#include <string>

using namespace std;


int main()
{

  vector<int> source {4, 5, 0, 1, -2, 3, 7, -6,  2, 0, 0, -9, 9};

  vector<int> v2( source.size());
  for(int i=0; i<3; i++)
  {copy(begin(source), end(source), back_inserter(v2));}
  cout<<"v2:";
  for(auto i: v2)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  auto v3 = source;

  auto pos = find(begin(source), end(source), 1);
  
  vector<int> v4(source.size());
  //copy the source to v4, from the begining of the source
  //to the position of 1, the v4 should be {4, 5, 0}
  copy(begin(source), pos, begin(v4));
  cout<<"v4:";
  for(auto i: v4)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  vector<int> v5(source.size());
  copy_if(begin(source), end(source), begin(v5),
      [](int elem ){ return elem % 2 == 0;});

  cout<<"v5:";
  for(auto i: v5)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  copy_n(begin(v5), 3, begin(v2));
  cout<<"v2:";
  for(auto i: v2)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  copy(begin(source), pos +1, pos+1);
  cout<<"source:";
  for(auto i: source)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  copy_backward(begin(v3), end(v3), end(source));



  copy_backward(begin(source), end(source)-1, end(v2));
  cout<<"===========demo remove =====\n";
  cout<<"v2:";
  for(auto i: v2)
  {
    cout<< i << " "; 
  } 
  cout << endl;
  auto newend = remove(begin(v2),end(v2),0);
  v2.erase(newend, end(v2));
  cout<<"v2:";
  for(auto i: v2)
  {
    cout<< i << " "; 
  } 
  cout << endl;


  return 0;
}
