//
// Fundamentals
//
// 1. options_description:
// root container, all allowed options declared here
// Writting to a stream 
// cout<< desc <<endl;
// print documentation
//
// 2. od.add_options()
// ("help", "print help message")
//
//  Fluent interface for defining
//  options.Can customize
//
//  Default values
//  Required/optional
//  Prefix (default --) allows
//  delimitinga
//  foo.exe --src
//
// 3. variables_map
//  Stores parsed variables
//  vm.count("foo") counts # of "foo" arguments(args may repeat)
//  vm["foo"] gets the value of the argument.
//
// Default value
//  po::value<string>()->default_value("file.txt")
// Binding to variable
// int n;
// po:value<int>(&n)
// Multiple aliases
// ("filename,F",po::value<string>(),...)
// let you pass argument with --filename or -F
// Multiple option arguments
// ("files",po:value<vector<string>>())
// foo.exe --files a.txt b.txt
//
// Positional argument
// po::positional_options_description
// p.add("filename", -1);
//
//
// compile the program
//g++  -std=c++0x ProgramOptions.cpp -o test -I /home/c4dev/nextUnityBugFix/uemcli/obj/KHDATAPATH_DEBUG/rpm_install/usr/include /home/c4dev/nextUnityBugFix/./safe/obj/KHDATAPATH_DEBUG_64/rpm_install/usr/lib64/libboost_program_options.so.1.54.0
//
//
#include <iostream>
#include <string>
using namespace std;

#include <boost/program_options.hpp>
namespace po = boost::program_options;


int customization(int argc, char* argv[])
{
  int value;
  po::options_description desc("my file processor");
  desc.add_options()
    ("value,V", po::value<int>(&value)->default_value(43),"input value")
    ("files", po::value<vector<string>>()->multitoken(),"input files");


  po::positional_options_description pos;
  pos.add("files",-1);

  po::variables_map vm;
  po::command_line_parser parser(argc,argv);
  auto parsed_options = parser.options(desc).positional(pos).run();
  po::store(parsed_options,vm);
  po::notify(vm);
  cout<<"the value is "<<value<<endl;

  if(vm.count("files"))
  {
    int i =0;
    auto files = vm["files"].as<vector<string>>();
    for(auto s:files)
    {
      cout<<(++i)<<":"<<s<<endl; 
    }
  } 

};


int main(int argc, char* argv[])
{
  customization(argc,argv);
  /* po::options_description desc("Program options"); */

  /* desc.add_options()("help", "print info") */
  /*   ("filename", po::value<string>()->default_value("file.txt"),"file to process"); */

  /* po::variables_map vm; */

  /* auto parsed = po::parse_command_line(argc, argv, desc); */
  /* po::store(parsed, vm); */
  /* po::notify(vm); */
    
  /* if(vm.count("help")) */
  /* { */
  /*   cout<<desc <<endl; */
  /*   return 1; */
  /* } */
  /* string filename="default.txt"; */
  /* if(vm.count("filename")) */
  /* { */
  /*   filename = vm["filename"].as<string>(); */ 

  /*   cout<<"processing file" <<filename<<endl; */
  /* } */

  return 0;
}
