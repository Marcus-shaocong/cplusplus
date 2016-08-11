#include <iostream>


//
//Example of Liskov Substitution Principle
//
//Objects in a program should be replaceable with instances of their subtypes w/o altering the correctness of 
//the program
//
//


class Rectangle
{

  protected:
    int width, height;
  public:
    Rectangle(int width, int height)
      :width(width), height(height)
    {
    }
    virtual int getWidth()const
    {
      return width; 
    }

    virtual void setWidth(const int width)
    {
      this->width = width; 
    }

    virtual int getHeight()const
    {
      return height; 
    }

    virtual void setHeight(const int height)
    {
      this->height= height; 
    }

    int Area() const {return width*height;}
};

class Square : public Rectangle
{
public:
  Square(int size): Rectangle{size, size}
  {
  }
    //The square have chagne the super class behavior
    void setWidth(const int width)
    {
      this->width = width; 
      this->height= width; 
    }
    void setHeight(const int height)
    {
      this->height= height; 
      this->width = height; 
    }
    //possible solution we add a setSize and not to inherit the setWidth and setHeight function
    void setSize(const int size)
    {
    }
};

//We might add a factory here to solve the issue
struct RectangleFactory
{
  static Rectangle CreateRectangle(int w, int h);
  static Rectangle CreateSquare(int size);
};



void process(Rectangle & r)
{
  int w = r.getWidth();
  r.setHeight(10);
  std::cout<<"expect area = " <<(w*10) <<", got "<< r.Area()<<std::endl;
}

int main()
{
  Rectangle r{5,5};
  process(r);
  Square s{5};
  process(s);

  return 0;
}
