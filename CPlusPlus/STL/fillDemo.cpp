
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
#include <numeric>
#include <cmath>
#include <string>

using namespace std;


int main()
{
  vector<int> v(10);
  fill(begin(v), end(v), 1);
  cout<<"v:";
  for(auto i: v)
  {
    cout<< i << " "; 
  } 
  cout << endl;
  //fill the first six to 2;
  fill_n(begin(v), 6, 2);
  cout<<"v:";
  for(auto i: v)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  iota(begin(v), end(v), 2);
  cout<<"v:";
  for(auto i: v)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  int index = 10;
  generate(begin(v), end(v), [&index](){return --index;});
  cout<<"v:";
  for(auto i: v)
  {
    cout<< i << " "; 
  } 
  cout << endl;
  index = 1;
  generate_n(begin(v), 7, [&index](){return index *=2;});

  cout<<"v:";
  for(auto i: v)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  //replace 2 to 7 
  replace(begin(v), end(v), 2, 7);
  cout<<"v:";
  for(auto i: v)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  replace_if(begin(v), end(v), [](int elem){ return elem < 16;} , 7);
  cout<<"v:";
  for(auto i: v)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  //demoe transform
  cout<<"=================demo transform==================="<<endl;
  iota(begin(v), end(v), 1);
  for_each(begin(v), end(v), [](int elem){cout<<elem<< " ";});
  cout<<endl;
  transform(begin(v), end(v), begin(v), [](int elem1){ return elem1 *2;});
  for_each(begin(v), end(v), [](int elem){cout<<elem<< " ";});
  cout<<endl;
  auto v2 = v;
  iota(begin(v2), end(v2), 2);
  for_each(begin(v2), end(v2), [](int elem){cout<<elem<< " ";});
  cout<<endl;
  vector<int> v3(10);
  transform(begin(v), end(v)-1, begin(v)+1, begin(v3),[](int elem1, int elem2){ return elem1 - elem2;});
  for_each(begin(v3), end(v3), [](int elem){cout<<elem<< " ";});
  cout<<endl;


  //unique will remove the duplicates
  auto v4 = v3;
  //unique will only remove consecutive members, so
  //before using it, do use sort to sort the array first
  cout<<"demo unique"<<endl;
  unique(begin(v3), end(v3));
  for_each(begin(v3), end(v3), [](int elem){cout<<elem<< " ";});
  cout<<endl;
  v3.erase(unique(begin(v3),end(v3)),end(v3));
  for_each(begin(v3), end(v3), [](int elem){cout<<elem<< " ";});
  cout<<endl;
  vector<int> v7(10);
  for_each(begin(v4), end(v4), [](int elem){cout<<elem<< " ";});
  cout<<endl;
  unique_copy(begin(v4),end(v4), begin(v7));
  for_each(begin(v7), end(v7), [](int elem){cout<<elem<< " ";});
  cout<<endl;

  //reverse, iter_swap, reverse_copy
  string sen = "Hello, world!";
  reverse(begin(sen), end(sen));
  cout<<"sen:"<<sen<<endl;
  iter_swap(begin(v3), end(v3)-1);
  for_each(begin(v3), end(v3), [](int elem){cout<<elem<< " ";});
  cout<<endl;
  string orig = "                   ";
  reverse_copy(begin(sen), end(sen), begin(orig));
  cout<<"sen:"<<orig<<endl;

  return 0;
}
