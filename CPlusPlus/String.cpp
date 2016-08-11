#include <string>
#include <iostream>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <regex>
using namespace std;


/* auto trim(string const & s ) -> string */
/* { */
/*   auto front = find_if_not(begin(s), end(s), isspace); */
/*   auto back = find_if_not(rbegin(s), rend(s), isspace); */

/*   return string {front, back.base()}; */
/* } */

int main()
{
    auto s = string {};
    s = basic_string<char> {};
    auto ws = wstring {};

    ws = basic_string<wchar_t> {};
    static_assert(sizeof(string::value_type) == 1, "1 Byte");
    //static_assert(sizeof(wstring::value_type) == 2, "2 Byte");
    cout<<" sizeof wstring" << sizeof(wstring::value_type) <<endl;
    s = string { "cluck!"};

    assert(!s.empty());
    assert(s.size() == 6);

    cout<<s.c_str()<<endl;
  
    s = string { 'C', 'l', 'u', 'c', 'k' };

    s.clear();

    assert(s.empty());
    assert(s.size() == 0);
    assert( 0 == strcmp(s.c_str(), "" ));

    s = string {"That hen clucked!"};

    s = string ( s, 4, 3);

    for( auto c : s)
    {
      cout << " c"  <<endl;
    }

    auto hen = string {"matilda"};
    auto pasture = string { "Tomatoes" };
    auto id = hen + "@" + pasture;
    cout<< "id " << id.c_str();

    auto pos = id.find('@');
    auto domain = id.substr(pos);

    assert( domain == "@Tomatoes" );

    //Regular expression example
    //
    cout<<" ============= " << endl; 

    try{
      auto str = string { "Call 877-808-2321 to reach Amelia the hen!" };
      auto r = regex { R"((\d+)-(\d+)-(\d+))"};
      auto m = smatch {};
      assert(m.empty());
      if(regex_search(str, m, r))
      {
        for(auto & sub: m )
        {
          auto str = sub.str();
          cout<<" match " << str << endl;
        }
      }
      else
      {
        cout<< "no match " << endl;
      }
    }catch( std::regex_error & e )
    {
      cout<<" catch a exception " << e.what() << endl; 
    }

}
