#include <string>
#include<iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

class String
{
  string s;
  public:
  String(const string & s)
    :s{s}
  {}

  String to_lower() const
  {
    string ss{s};
    boost::to_lower(ss);

    return {ss};
  }

  vector<string> split(const string & delimeter = " ") const {
    vector<string> result;
    boost::split(result, s, boost::is_any_of(delimeter), boost::token_compress_on);
    return result;
  }

};

int main()
{
  String s{"Hello World"};
  auto parts = s.to_lower().split();
  for(const auto & p : parts)
  {
    cout<<p<<endl; 
  }
}
