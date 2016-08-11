//
//
//
//
//
//
//

#include <iostream>
#include <string>
using namespace std;
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim_all.hpp>

using namespace boost;
using namespace boost::algorithm;

class MyTokenizer
{
public:
  template <typename II, typename Token>
    bool operator () (II& next, II& end, Token & tok)
    {
      return true; 
    }

  void reset()
  {}

};

void token_demo()
{
  /*
//example one
string s = "To be, or not to be ?";
//by default is separate by empty space
tokenizer<>t(s);

for(string part :t)
  cout<<"<" << part << ">"<<endl;
  */

// in this case, "o" is the separator, " "means to keep the space, keep_empty_tokens means to keep the empty tokens
char_separator<char> sep("o", " ", keep_empty_tokens);
string s = "To be, or not to be ?";
tokenizer<char_separator<char>> t(s,sep);
for(string part :t)
  cout<<"<" << part << ">"<<endl;

int offsets[] = {2, 3, 4};
offset_separator os(offsets, offsets + 3);

auto start = make_token_iterator<string>(s.begin(), s.end(),os);
auto end = make_token_iterator<string>(s.end(), s.end(),os);

for(; start !=end; ++start)
{
  cout<<*start<<endl;
}

//example to use your own tokenizer
 tokenizer<MyTokenizer> tt(s,MyTokenizer());

}

void lc_demo()
{
  string s = "3.2";
  double b = lexical_cast<double>(s);

  string ss = "12345";
  int n = lexical_cast<int>(ss);

  cout<< b << " , " << n << endl;

  try{
    lexical_cast<int>("abcd"); 
  }
  catch(const bad_lexical_cast & e)
  {
    cout<< "bad cast" <<endl; 
  }
}

void algo_demo()
{
  string test = "hello  world\r\n";
  trim(test);
  cout<< "< " <<test<<">"<<endl;
  trim_all(test);

  cout<< "< " <<test<<">"<<endl;
  to_upper(test);
  cout<< "< " <<test<<">"<<endl;
}
int main(int argc, char* argv[])
{
  token_demo();
  lc_demo();
algo_demo();
  return 0;
}
