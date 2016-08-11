//
//
// Substitution Failure is Not an Error
// 
//

typedef Foo foot_t;
make_instance<foo_t> 



//make a instance base on if the type is share ptr or not
template <typename InstType,
         class SharedEnabled = void>
struct make_instance
{
  Insttype operator() (special::value & v) const
  {
    Insttype inst;
    fill_adapted<InstType>::apply(inst, v);
    return inst;
  }
};

template<typename InstType >
struct make_instance< instType, 
  typename enable_if< is_shared_ptr<InstType> > ::type>
{
  Insttype operator() (special::value & v) const
  {
    Insttype inst( new typename InstType::element_type );
    fill_adapted<typename InstType::element_type>::apply(*inst, v);
    return inst;
  }
};
