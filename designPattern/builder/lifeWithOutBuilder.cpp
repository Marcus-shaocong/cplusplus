#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>


using namespace std;

int main()
{
auto text = "hello";

string output;
output += "<p>";
output += text;
output += "</p>";

printf("<p>%s</p>",text);

//<ul><li>hello</li><li>world</li></ul>
//

string words[] = {"hello", "world" };

ostringstream oss;
oss << "<ul>";
for (auto w :words)
  oss << " <li> " << w << "</li>";

oss<<"</ul>";
printf(oss.str().c_str());

return 0;


}

