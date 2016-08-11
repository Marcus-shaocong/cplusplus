//
//
//
//
//

struct mypoint
{
  double x, y;
};



struct yourpoint
{
  double x, y;
};

template <typename P1, typename p2>
double distance(P1 const& a, P2 const & b)
{
double dx = a.x - b.x;
double dy = a.y - b.y;
return std::sqrt(dx*dx + dy*dy);
}

struct secret_point
{public:
  double get_x();
  double get_y();
  private :
  ....

};

namespace traits
{
  template <typename P, int D>
  struct access {};
}

namespace traits
{
    template<>
      struct access<mypoint, 0>
      {
        static double get(mypoint const&p)
        {
          return p.x; 
        }
      };
    template<>
      struct access<mypoint, 1>
      {
        static double get(mypoint const&p)
        {
          return p.x; 
        }
      };
}

namespace traits
{

    template<>
      struct access<secret_point, 0>
      {
        static double get(secret_point const& p)
        {
          return p.get_x(); 
        }
      };
    
    template<>
      struct access<secret_point, 1>
      {
        static double get(secret_point const& p)
        {
          return p.get_y(); 
        }
      };

}

template< typename P1, typename p2>
double distance(P1 const& a, P2 const & b)
{
  double dx = trait::access<P1, 0>::get(a) -
    trait::access<P2,0>::get(b);
  
  double dy = trait::access<P1, 1>::get(a) -
    trait::access<P2,1>::get(b);
  return std::sqrt(dx*dx, dy*dy);
  
}


template<int D, typename P>
inline double get(P const& p)
{
  return traits::access<P,D>::get(p);
}

template< typename P1, typename p2>
double distance(P1 const& a, P2 const & b)
{
  double dx = get<0>(a) - get<0>(b);
  
  double dy = get<1>(a) - get<1>(b);
  return std::sqrt(dx*dx, dy*dy);
  
}


//another example
//profit = 42 * output/input;
struct vendor_type{float output, input;};
vendor_type vendor::get_in_out();

class department
{
  int get_widgets() const;
  int get_managers() const;
};
ouput:widgets
input:maangers

class sw_engineer
{
  int cppnow_attend_count() const;
  int daily_cups_of_coffee() const;
  int manager_cout() const;
};
output: years attending C++ now * inverse of cups of coffer
input : manage cout

//here is the implementation
namespace tag
{
  template <typename T>
    struct profit();

  template<>
    struct profit<vendor_type>
    {
      static int ouput( vendor_type const&v) { return v.output;}
      static int input( vendor_type const&v) { return v.input;}
    };
  template<>
    struct profit<department>
    {
      static int ouput( department const&v) { return v.get_widgets();}
      static int input( department const&v) { return v.get_managers();}
    };

  template<>
    struct profit<sw_engineer>
    {
      static int ouput( sw_engineer const&v) { return v.cppnow_attend_cout()* v.daily_cups_of_coffee();}
      static int input( sw_engineer const&v) { return v.manager_cout();}
    };
}

template <typename T>
float profit(T const & v)
{
  return 42*tag::profit<T>::output(v) /tag::profit<T>::input(v);
}
