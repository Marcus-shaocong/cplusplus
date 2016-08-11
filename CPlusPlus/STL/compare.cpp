
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


class Employee
{
  public:
    Employee(string first, string last, int sal)
      :firstname(first), lastname(last), salary(sal)
    {}

    int getSalary(){return salary;}
    string getSortingName(){ return lastname + ", " + firstname;}

  private:
    string firstname;
    string lastname;
    int salary;
};

int main()
{
  vector<int> a {1, 2,3, 4, 5};
  vector<int> b{1, 2, 0, 4, 5};

  bool same = equal(begin(a), end(a), begin(b));

  cout<<" same " <<same <<endl;
  auto firstchange = mismatch(begin(a), end(a), begin(b));

  int avalue =  *(firstchange.first);
  int bvalue =  *(firstchange.second);

  cout<<" avalue " << avalue << "bvalue " <<bvalue <<endl;
  auto distance = firstchange.first -begin(a);

  int total = accumulate(begin(a), end(a), 0);
  cout<<"total "<< total<<endl;
  total = accumulate(begin(a), end(a), 0,
      [](int total, int i){ if(i%2 == 0) return total +i; return total;});
  cout<<"even total " << total<<endl;

  total = accumulate(begin(a), end(a), 1,
      [](int total, int i){return total* i;});
  
  cout<<"multiple " << total<<endl;

  vector<string> words{ "one", "two", "tree"};

  auto allwords = accumulate(begin(words),end(words), string{"words:"}, [](const string & total, string i){ return total + " " + i;});
  cout<< allwords <<endl;

  allwords = accumulate(begin(a),end(a), string{"words:"}, [](const string & total, int i){ return total + " " +to_string( i);});

  cout<< allwords <<endl;

  b = a;
  for_each(begin(b), end(b), [](int & elem){elem = 2;});

  for(auto i: b) {
    cout<< i << " "  ;
  }
  cout <<endl;

  b = a;
  auto firstthree = find(begin(b), end(b), 3);
  for_each(firstthree, end(b), [](int& elem){elem=0;});
  for(auto i: b) {
    cout<< i << " " ; 
  }
  cout <<endl;
  return 0;
}
