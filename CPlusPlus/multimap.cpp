#include<map>

#include <cassert>
#include <iostream>
#include <unordered_map>

using namespace std;


namespace std
{
  template<typename T>
    auto begin(pair<T,T> const & range ) -> T 
    {
      return range.first; 
    }

  template <typename T>
    auto end(pair<T, T> const & range)   -> T
    {
    
      return range.second; 
    }

}

struct Hen
{
  int pasture;
  int id;

  Hen(int pasture_, int id_)
    :pasture{pasture_}, id{id_}
  {}

};

auto operator == (Hen const & left, Hen const & right) -> bool
{
  return left.pasture == right.pasture && left.id == right.id;
}
namespace std
{
  template<>
    struct hash<Hen>
    {
      auto operator() (Hen const & hen) const -> size_t 
      {
          return hash<int> {} (hen.pasture) ^ hash<int>{} (hen.id);        
      }
    
    };
}

int main()
{
    auto  c = multimap<int, double>
    {
        {1, 1.1},
        {2, 2.2},
        {2, 2.1},
        {3, 3.1}
    }; 


    assert(!c.empty());
    assert(c.size() == 4);

    auto result = c.emplace(2,2.3);

    assert(result->first == 2);
    assert(result->second == 2.3);

    for( auto & v : c)
    {
      cout<< " first: " << v.first << " second: " <<v.second<<endl; 
    }
    cout<<" ======== "<<endl;
    auto range = c.equal_range(2);
    for(auto i = range.first; i != range.second; ++i)
    {
      cout<<" first :" << i->first << " second: " << i->second<<endl;
    }

    cout<<" ======== "<<endl;
    for( auto & v : c.equal_range(2))
    {
      cout<<" first :" << v.first << " second: " << v.second<<endl;
    }
    
    cout<<" ======== "<<endl;

    auto d = unordered_map<Hen, double> 
    {
      {{4, 123}, 6.2},
      {{4, 124}, 6.2},
    };
    d[{5,12}] = 6.1;
    /* auto k = Hen { 4, 123}; */
    /* d[k] = 5.9; */


    for( auto & v : d)
    {
      cout<<"pasture "<< v.first.pasture << " id " << v.first.id << " value " << v.second<<endl; 
    }

  };
