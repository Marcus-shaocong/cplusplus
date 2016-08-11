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

#include <boost/bimap.hpp>
using namespace boost;
using namespace boost::algorithm;


enum class Color
{
  Red,
  Green,
  Blue
};

typedef bimap<Color, string> ColorMapType;

ColorMapType colorTypes;

void bimap_demo()
{
  colorTypes.insert(ColorMapType::value_type(Color::Red, "red"));

  Color c = colorTypes.right.at("red");
  string s = colorTypes.left.at(Color::Red);
  cout<<" s is "<<s <<endl; 
}

int main(int argc, char* argv[])
{ 
  bimap_demo();
  return 0;
}
