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


#include <boost/units/unit.hpp>
#include <boost/units/make_scaled_unit.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/prefixes.hpp>
using namespace boost;
using namespace boost::units;


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

void unit_demo()
{
  typedef make_scaled_unit<si::length, scale<10, static_rational<-2>>>::type cm;
  quantity<cm> d(2.0 * si::meters);
  quantity<si::time> t(100.0 * si::seconds);
  quantity<si::velocity> x(d/t);
}

int main(int argc, char* argv[])
{ 
  unit_demo();
  return 0;
}
