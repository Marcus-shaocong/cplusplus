//
//
//
//  Typical tasks
//  Determine if file or directory exists
//  Measure file size 
// 
//  Different types of file in addition to 'regular'
//  E.g. symlink
//
//  file_status represents info about a file
//  Acquired by status()
//  A file_type value returned by type()
//  A set of permissions(perms) returned by the permissions() function
//
//
// how to build the file:
// export LIBRARY_PATH=/home/c4dev/newWsDm/serviceability/obj/KHDATAPATH_DEBUG/rpm_install/usr/lib64
// g++  -std=c++0x  BoostFileSystem.cpp  -o test -I /home/c4dev/newWsDm/observability/obj/KHDATAPATH_DEBUG_64/rpm_install/usr/include/ -lboost_filesystem -lboost_system
//
//
// Summary
// #include <boost/filesystem.hpp> or #include <filesystem>
// using namespace std::tr2;
//
// Create a path object to wrap around a path.
// Use is_regular_file()/is_directory to determine type
// use file_size() to determine size
// use stats() to get type and permissions
// to navigate directory structure
//
// To navigate directory structure
// use parent_path() or root_path()
// use a directory_navigator to get contents of a directory
//

#include<string>
#include <iostream>

using namespace std;
#include <boost/filesystem.hpp>
using namespace boost;
using namespace boost::filesystem;


void check_path(const char* p)
{
  path myPath(p);
  if(exists(p))
  {
    if(is_regular_file(myPath))
    {
      cout<<"file name " << myPath.filename()<<endl;
      cout<<"path " << myPath.filename().replace_extension("abc")<< " is a regular file of size" << file_size(myPath) <<endl; 
    } 
  }else if(is_directory(myPath))
  {
    cout<<"Path " <<myPath.filename() << "is a directory" <<endl; 
  }
  else
  {
    cout<<"path "<<myPath<<" does not exist"<<endl; 
  }
}

void check_file(path &p)
{
  auto s = status(p);
  auto t = s.type();
  cout<<"the type is " << t << endl;
  auto ps = s.permissions();
  if((ps & owner_write) != owner_write)
  {
    cout<<"no permission to write"<<endl; 
  }
}

void dir_nav(path& dir)
{
  directory_iterator end;
  for(directory_iterator i(dir); i!=end; ++i)
  {
    path p = i->path();
    if(is_regular_file(p))
      cout<<p.filename()<<endl;
    else if(is_directory(p))
    {
      cout<<"directory " <<p.filename()<<endl;
      cout<<"========================"<<endl;
      dir_nav(p);
    }
  }
}

int main(int argc, char* argv[])
{
  check_path("foo");
  check_path(argv[0]);
  auto dir = path(argv[0]).parent_path();
  cout<<"parent path"<<endl;
  check_path(dir.string().c_str());

  //decomposition
  for(auto & child: dir)
  {
    cout << child <<endl; 
  }

 try{
  path p("junk");
  cout<<file_size(p)<<endl;
 }catch( const filesystem_error & e)
 {
    cout<<e.what()<<endl; 
 }

  path p(argv[0]);
  check_file(p);

  auto parent = path(argv[0]).parent_path().parent_path();

  dir_nav(parent);
  //find all the content of a particular directory

  return 0;
}



