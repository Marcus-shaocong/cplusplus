//
//
// Decouple an abstraction from its implementation so the two can vary independently.
// Abstractions are coupled to implementations by default.
//
// Usually we implement a class by inherit a interface. that when a class is change or an interface is change, the class
// need to change as well. we need to decouple that.
//
// Abstraction->abstraction->implementation
//
//
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class IFormatter
{
  public:
  virtual string format(string key, string value)=0;
  IFormatter(){
    cout<<"IForma ctor"<<endl; 
  }
  ~IFormatter()
  {
    cout<<"IForma dtor"<<endl;
  } 
};


class BaseFormatter: public IFormatter
{
  public:
  string format(string key,string value)
  {
    return key+ ": " + value;
  }
};

class RevFormatter: public IFormatter
{
  public:
  string format(string key,string value)
  {
    //cout<<key<< ": " <<value;
    string revkey(key.size(), ' ' );
    string revvalue(value.size(), ' ');

    reverse_copy(begin(key), end(key), begin(revkey));
    reverse_copy(begin(value), end(value), begin(revvalue));
    return key+ ": " + revvalue + " ";
  }
};
class IManuscript
{
  protected:
  unique_ptr<IFormatter> iformatter;
  public:
    IManuscript(IFormatter * ptr)
    {
      iformatter.reset(ptr);
    }
    virtual void  print()=0;
};

class Book : public IManuscript
{
  string Title, Author, Text;
  public:
  Book(IFormatter * ptr, string title_, string author_, string text_)
    :IManuscript{ptr},Title{title_},Author{author_},Text{text_}
  {
    cout<<"Book constructor"<<endl; 
  }
  ~Book(){
    cout<<"Book destructor"<<endl; 
  }
  void print()
  {
    //std::cout<<"title: "<<Title<<" Author: "<<Author<< " Text : "<<Text<<endl;
    cout<<iformatter->format("Title", Title);
    cout<<iformatter->format("Author", Author);
    cout<<iformatter->format("Text", Text);
    cout<<endl;
  }
};

class TermPaper: public IManuscript
{
  string Class, Student, Text, References;
  public:
TermPaper(IFormatter* ptr, string class_, string student_, string text_, string references_)
  :IManuscript{ptr}, Class(class_), Student(student_), Text(text_), References(references_)
  {
    cout<<"TermPaper  constructor"<<endl; 
  } 

~TermPaper()
{
    cout<<"TermPaper  destructor"<<endl; 
}

void print()
{
    cout<<iformatter->format("Class", Class);
    cout<<iformatter->format("Student", Student);
    cout<<iformatter->format("Text", Text);
    cout<<iformatter->format("References", References);
    cout<<endl;
}
};


int main()
{
  IFormatter * ptr = new BaseFormatter();
  IFormatter * ptr2 = new RevFormatter();
  vector< unique_ptr<IManuscript> > vec;
  vec.emplace_back(unique_ptr<IManuscript>(new Book{ptr, "losts of Patterns", "John Sonmez", "Blah blah blah..."}));
  vec.emplace_back(unique_ptr<IManuscript> (new TermPaper{ptr2, "Design Patterns", "John N00b", "Blah blah blah...", "GOF"}));
 
  for(auto & x: vec)
  {
    x->print(); 
  }
  return 0;
}
