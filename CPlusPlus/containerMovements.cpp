#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
using namespace std;


struct Hen
{
  string m_name;

  Hen():m_name {""}
  {
    cout<<" default constructor "<< m_name <<endl; 
  }

  explicit Hen(const string &name)
    :m_name{name}
  {
    cout<<" explicit constructor " << m_name << endl; 
  }

  Hen( Hen const & other) : m_name{other.m_name}
  {
    cout<<" copy constructor " << m_name << endl; 
  }

  Hen( Hen && other ): m_name {other.m_name}
  {
    cout<<" move constructor " << m_name << endl; 
  }

  ~Hen()
  {
    cout<<" destructor " << m_name << endl; 
  }

  auto operator = (Hen const & other) -> Hen &
  {
    m_name = other.m_name; 
    cout<<"copy assignment constructor" << m_name << endl; 
    return *this;
  }

  auto operator = (Hen const && other) -> Hen &
  {
    cout<<"move assignment constructor from " << m_name << " to " << other.m_name << endl; 
    m_name = other.m_name;
    return *this;
    
  }

  void swap( Hen & other )
  {
    std::swap(m_name, other.m_name); 
  }

};


void swap(Hen & left, Hen & right)
{
  left.swap(right);
}

int main()
{
  auto c = list<Hen> {};

  c.emplace_back("Herietta");
  c.emplace_back("Jane");
  c.emplace_back("Jerry");
  c.emplace_back("Ansin");
  c.emplace_back("Steven");
  c.emplace_back("Marcus");

  /* c.push_back(Hen{"Herietta"}); */
  /* c.push_back(Hen{"Jane"}); */
  /* c.push_back(Hen{"Jerry"}); */
  /* c.push_back(Hen{"Ansin"}); */
  /* c.push_back(Hen{"Steven"}); */
  /* c.push_back(Hen{"Marcus"}); */
  reverse(begin(c), end(c));
  return 0;
}
