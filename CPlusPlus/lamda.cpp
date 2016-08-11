//Generally imposed by the place you are using it
// A for_each will pass you an element of the collection
// a C++ AMP concurrency::parallel_for_each will ignore anything you return
//
//
// Lambdas can call functions
//
//
//
//


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
  int x = 0;
  int y = 0;
  std::vector<int> v;
  auto print = [&](){cout<<" x: " << x << " y: " << y << endl;};

  for(int i=0; i<5; i++) {v.push_back(i);};

  // all by value
  for_each(begin(v), end(v), [=](int element) mutable {
        x += element;
        y += element;
      });
 print();
 x=y=0;
 
  //x by value, rest by ref 
  for_each(begin(v), end(v), [&,x](int element) mutable {
        x += element;
        y += element;
      });
 
 print();
 x=y=0;
  //y by value, rest by ref 
  for_each(begin(v), end(v), [&,y](int element) mutable {
        x += element;
        y += element;
      });
 print();
 x=y=0;

  //x by ref, rest by value 
  for_each(begin(v), end(v), [=,&x](int element) mutable {
        x += element;
        y += element;
      });
  
 print();
 x=y=0;
  //all by ref
  for_each(begin(v), end(v), [&](int element) mutable {
        x += element;
        y += element;
      });


 vector<int> doubledV(5);
 int factor =2;
 int n = 5;
 /* for_each(0,n, [=](int element){ for( int i = 0 ; i<n ; i++) cout <<" I " << i*n<<endl;}); */
 std::transform(begin(v), end(v), begin(doubledV),
     [=](int element) {return element* factor;}
     );

 for(auto x : doubledV)
 {
    cout << " " <<  x ; 
 }

  return 0;
}


