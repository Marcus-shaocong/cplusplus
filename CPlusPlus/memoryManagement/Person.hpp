


#ifndef _PERSON_H
#define _PERSON_H



#include <memory>
#include <string>
#include "Resource.hpp"
using namespace std;
class Person
{
  private:
    string firstname;
    string lastname;
    int number;
    //first version, we set the resource as a solid member
    //Resource pResource;
    //second version, to use the unique_ptr
    /* unique_ptr<Resource> pResource; */
    
    //version three to use the shared_ptr
    shared_ptr<Resource> pResource; 

  public:
    Person(string first, string last, int number);
    //version three, if we are uning the shared_ptr,
    //we don't need to implement the copy assignment and copy constructor
    //there are needed only we use the unique_ptr

  /*  Person& operator = (Person & r);
    Person(Person & r); */
    string GetName() const;
    int GetNumber() const { return  number;}
    void SetNumber( int number ) { number = number;}
    void SetFirstName( string first ) { firstname = first;}

    void SetResource(string resourcename);
    string GetResourceName() const { 
   
     //first version, resouce is a solid member 
     // return pResource.GetName();

      //second version resouce is unique_ptr
      return pResource->GetName();
    
    }
};

#endif
