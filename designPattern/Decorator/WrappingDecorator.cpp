#include <iostream>
#include <string>
#include <sstream>

using namespace std;
struct Shape
{
   virtual string str() const = 0;
};


struct Circle : Shape
{
  float radius;

  Circle(){}
  explicit Circle(const float radius)
    :radius{radius}
  {
  }

  string str() const override
  {
    ostringstream oss;
    oss<<" A circle of radius " <<radius;
    return oss.str();
  }

  void resize (float factor)
  {
    radius = radius * factor; 
  }
};


struct Square: Shape
{
  float side;
  Square(){}
  explicit Square(const float side)
    :side{side}
  {
  }

  string str() const override
  {
    ostringstream oss;
    oss<<" A square of side" <<side;
    return oss.str();
  }
};

struct ColoredShape : Shape
{
  Shape & shape;
  string color;
  ColoredShape(Shape& shape,const string & color)
    :shape(shape), color{color}
  {}

  string str() const override
  {
    ostringstream oss;
    oss<< shape.str() << " has the color " <<color;
    return oss.str();
  }
};

struct TransparentShape: Shape
{
  Shape & shape;
  int transparency;
  TransparentShape(Shape& shape, const int transparent)
    :shape(shape), transparency{transparent}
  {}

  string str() const override
  {
    ostringstream oss;
    oss<< shape.str() << " has " 
      << static_cast<float>(transparency) / 255.f * 100.f << "% transparency ";
    return oss.str();
  }
};

template <typename T> struct ColoredShape2 : T
{
  static_assert(is_base_of<Shape,T>::value, "base class must be a shape");
  string color;
  ColoredShape2(){}


  explicit ColoredShape2(const string& color)
    :color{color}
  {
  
  }

  string str() const override
  {
    ostringstream oss;
    oss<< T::str() << " has the color "  <<color;
    return oss.str();
  }

};

template <typename T> struct TransparentShape2: T
{
  int transparency;

  template<typename... Args>
  TransparentShape2(const int transparent, Args ...args)
    :T(args...), transparency{transparent}
  {}

  string str() const override
  {
    ostringstream oss;
    oss<< T::str() << " has " 
      << static_cast<float>(transparency) / 255.f * 100.f << "% transparency ";
    return oss.str();
  }
};

int main()
{
  /* Circle circle{5}; */
  /* cout<<circle.str() <<endl; */

  /* ColoredShape red_circle(circle, "red"); */
  /* cout<<red_circle.str() <<endl; */

  /* TransparentShape half_transparennt_circle(circle, 128); */
  /* cout<<half_transparennt_circle.str() <<endl; */
  /* TransparentShape half_transparennt_red_circle(red_circle, 128); */
  /* cout<<half_transparennt_red_circle.str() <<endl; */

  /* ColoredShape2<Circle> red_circle{"red"}; */
  /* red_circle.radius = 5; */
  /* cout<<red_circle.str()<<endl; */
/* TransparentShape2<ColoredShape2<Circle>> red_half_transparnt_circle{127}; */
/* red_half_transparnt_circle.color = "red"; */
/* red_half_transparnt_circle.radius = 10; */
/* cout<<red_half_transparnt_circle.str()<<endl; */

//illustrate the base class must be a shape by adding the static assert there
/* struct NotAShape */
/* { */
/*     virtual string str() const {return string{};} */
/* }; */

/* ColoredShape2<NotAShape> legal; */

TransparentShape2<Square> hidden_square{0, 15};

cout<<hidden_square.str()<<endl;

  return 0;
}
