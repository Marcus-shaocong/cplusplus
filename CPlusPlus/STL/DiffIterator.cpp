
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
#include <iterator>
#include <deque>

using namespace std;


int main()
{
  vector<int> v(10);
  fill(begin(v), end(v), 1);
  fill_n(begin(v),6, 2);

  vector<int>v2;
  fill_n(back_inserter(v2), 6, 2);

  cout<<"v2:";
  for(auto i: v2)
  {
    cout<< i << " "; 
  } 
  generate_n(back_inserter(v2), 10, [n = 0]()mutable{return n++;});

  cout<<"v2:";
  for(auto i: v2)
  {
    cout<< i << " "; 
  }

  deque<int> q3;
  fill_n(back_inserter(q3), 6, 2);
  cout<<"q3:";
  for(auto i: q3)
  {
    cout<< i << " "; 
  } 
  generate_n(front_inserter(q3), 10, [n = 0]()mutable{return n++;});
  
  
  cout<<"q3:";
  for(auto i: q3)
  {
    cout<< i << " "; 
  } 
  cout << endl;

  vector<int> v3{3, 5, 1, 0, -2, 5};
  vector<int> v5;
  copy_if(begin(v3), end(v3), back_inserter(v5), [](int elem) {return elem %2 == 0;});
  for_each(begin(v5), end(v5), [](int elem){cout<<elem<< " ";});
  cout<<endl;
  v[3] = -2;
  vector<int> v6;
  unique_copy(begin(v3), end(v3), back_inserter(v6));

  for_each(begin(v6), end(v6), [](int elem){cout<<elem<< " ";});
  cout<<endl;
  string sentence = "hello world";
  string reverse;
  reverse_copy(begin(sentence), end(sentence), back_inserter(reverse));
  cout<<" sen: "<<reverse<<endl;
  v2.clear(); 
  /* copy(std::rbegin(v), std::rend(v), back_inserter(v2)); */
  /* for_each(begin(v2), end(v2), [](int elem){cout<<elem<< " ";}); */
  /* cout<<endl; */


  //iterator arithmetic
  //if you want to declare a interator, auto is your friend
  //can use ++, --, +=, -= 
  array<const int, 5> ca {3, 1, 5, 0, 2};

  return 0;
}
