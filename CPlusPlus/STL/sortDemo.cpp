
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

  vector<int> v {4, 1, 0, 1, -2, 3, 7, -6,  2, 0, 0, -9, 9};
  auto v2 = v;
  sort(begin(v2), end(v2));
  sort(begin(v2), end(v2), 
      [](int elem1, int elem2) {return elem2 > elem2;});

  sort(begin(v2), end(v2), 
      [](int elem1, int elem2) {return abs(elem2) > abs(elem2);});


  vector<Employee> staff{
  {"kate", "Gregory", 1000},
    {"Obvious", "Atrificial", 2000},
    {"Fake", "Name", 1000},
    {"Alan", "Turing", 2000},
    {"Grace", "Hopper", 2000},
    {"Anita", "Borg", 2000}
  };

  sort(begin(staff), end(staff),
      [](Employee e1, Employee e2){ return e1.getSalary() < e2.getSalary();});

  for(auto & x: staff)
  {
      cout<<x.getSortingName() << " " << x.getSalary()<<endl; 
  }

  sort(begin(staff), end(staff),
      [](Employee e1, Employee e2){ return e1.getSortingName()<e2.getSortingName();});
  cout<<"================"<<endl;
  for(auto & x: staff)
  {
      cout<<x.getSortingName() << " " << x.getSalary()<<endl; 
  }
  cout<<"================"<<endl;
  sort(begin(staff), end(staff),
      [](Employee e1, Employee e2){ return e1.getSalary() < e2.getSalary();});
  
  for(auto & x: staff)
  {
      cout<<x.getSortingName() << " " << x.getSalary()<<endl; 
  }
 //stable sort
  stable_sort(begin(staff), end(staff),
      [](Employee e1, Employee e2){ return e1.getSalary() < e2.getSalary();});
  
  cout<<"================"<<endl;
  for(auto & x: staff)
  {
      cout<<x.getSortingName() << " " << x.getSalary()<<endl; 
  }

  // judge if it is sorted
  auto sorted = is_sorted(begin(v2), end(v2));

  int high = *(max_element(begin(v), end(v)));
  int low = *(min_element(begin(v),end(v)));
  sort(begin(v2), end(v2));
  low = *begin(v2);
  high = *(end(v2)-1);
  
  cout<<"high "<<high << "low " <<low <<endl;


  int pos = *upper_bound(begin(v2), end(v2), 0);
  cout<<"pos "<< pos<<endl;
  sort(begin(staff), end(staff),
      [](Employee e1, Employee e2){ return e1.getSortingName()<e2.getSortingName();});

  auto x1 = lower_bound(begin(staff), end(staff), "Gregory, Kate",
      [](Employee e1, string n){ return e1.getSortingName()<n;});
  cout <<x1->getSortingName()<< " " << x1->getSalary();


  //Generate random number
  random_device randomdevice;
  mt19937 generator(randomdevice());
  cout<<"shuffle demo"<<endl;
  for(auto x :v2) {
    cout << x << " "; 
  }
  cout<<endl;
  shuffle(begin(v2), end(v2),generator);
  for(auto x :v2) {
    cout << x << " "; 
  }

  cout<<endl;

  cout<<"=============partial demo================="<<endl;
  for(auto x :v2) {
    cout << x << " "; 
  }
  cout<<endl;
  //Parital_sort
  partial_sort(begin(v2),find(begin(v2), end(v2),4),end(v2));
  for(auto x :v2) {
    cout << x << " "; 
  }
  cout<<endl;
  int breakpoint = *is_sorted_until(begin(v2), end(v2));
  cout<<"sort until :" << breakpoint<<endl;

  // we copy the first 3 element to v3, the reason we do that 
  // is because we only care about the first 3 element.
  vector<int> v3(3);
  partial_sort_copy(begin(v), end(v), begin(v3),end(v3));
  cout<<"output the first sorted element:"<<endl;
  for(auto x :v3) {
    cout << x << " "; 
  }
 cout<<endl; 
  cout<<"=============Nth Elementdemo================="<<endl;

  v2 = { 1, 5, 4, 2, 9, 7, 3, 8, 2};
  int i = *(begin(v2) + 4);
  nth_element(begin(v2), begin(v2)+4, end(v2));
  i = *(begin(v2) + 4);
  cout<< "median value " << i <<endl;

  return 0;
}
