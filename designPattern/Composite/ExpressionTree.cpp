#include <iostream>

using namespace std;


class Component_Node
{
  public:
    virtual ~Component_Node() = 0;
    virtual int item() const;
    virtual Component_Node * left() const;
    virtual Component_Node * right() const;
};


class Leaf_Node : public Component_Node
{
  private :
    int x;
  public:
  Leaf_Node(int x_ ) :x(x_){}
  int item(){return x;}

};
class Composite_Unary_Node: public Component_Node
{
  private:
    int left;
public:
Composite_Unary_Node(int x): left(x){}
};

class Composite_Binary_Node: public Composite_Unary_Node
{
  private:
    int right;
  public:
    Composite_Binary_Node(int x, int y):Composite_Unary_Node(x), right(y){}
};

class Composite_Negate_Node: public Composite_Unary_Node
{
  public:
Composite_Negate_Node(int x):Composite_Unary_Node(x){}
};

class Composite_Add_Node: public Composite_Binary_Node
{
  public:
Composite_Add_Node(int x, int y):Composite_Binary_Node(x,y){}

};


class Composite_Multiply_Node: public Composite_Binary_Node
{

};
class Composite_Subtract_Node: public Composite_Binary_Node
{

};

class Composite_Divide_Node: public Composite_Binary_Node
{

};
int main()
{
  return 0;
}
