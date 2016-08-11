//
//
// please reference TagDispacting.cpp for more infromation
//
//
// to calculate the x = sqrt(q1.x,q2.x) + sqrt(q1.y, q1.y)+sqrt(q1.z+q1.z)
template <typename P1, typename P2, int D>
struct pythagoras
{
  static double apply(P1 const & a, P2 const & b)
  {
    double d = get<D-1>(a) -get<D-1>(b);
    return d*d + pythagoras<P1, P2, D-1>::apply(a,b);
  }
};

template <typename P1, typename P2>
struct pythagoras<P1, P2, 0>
{
  static double apply(P1 const &, P2 const &)
  {
    return 0; 
  }
};

template <typename P1, typename P2>
double distance(P1 const&a, P2 const & b)
{
  BOOST_STATIC_ASSERT((dimension<P1>::value == dimension<P2>::value));

  return sqrt(pythagoras<P1,P2,dimension<P1>::value>::apply(a,b));
}

namespace traits
{
  template<typename P>
    struct dimension{};
}


namespace traits
{
  template <>
    struct dimension<mypoint> : boost::mpl::int_<2>{};
}

template <typename P>
struct dimension: traits::diemnsion<P>
{};

namespace traits
{
  template<typename P>
    struct coordinate_type{};

  template<>
    sturct coordinate_type<mypoint>
    {
      typedef double type;
    };
}

template<typename P>
struct coordinate_type: traits::coordinate_type<P>
{
};


//change the return type
//

template <typename P1, typename P2, int D>
struct pythagoras
{
  typepdef typename select_most_precise
    <
    typename coordinate_type<P1>::type,
    typename coordinate_type<P2>::type
    >::type computation_t;

  static computation_t apply(P1 const & a, P2 const & b)
  {
    computation_t d = get<D-1>(a) -get<D-1>(b);
    return d*d + pythagoras<P1, P2, D-1>::apply(a,b);
  }
};


