#include <string>
#include <iostream>

// base class
class Quote
{
public:
    std::string isbn() const;
    // net_price needs to be defined in derived classes
    // virtual indicates that derived classes need to realise the function
    // ie define the function specifically for their use case
    virtual double net_price(std::size_t n) const;
};

// a derived class must specify the classes from which it intends to inherit, using
// a class derivation list
// which may have an optional access specifier

class Bulk_quote : public Quote
{
public:
    // override keyboard -> explicitly note that the
    // derived class intends to override the member function
    // that it inherits
    double net_price(std::size_t n) const override;
};

inline double print_total(
    std::ostream &os,
    const Quote &item,
    std::size_t n)
{

    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN" << item.isbn() // calls Quote::isn() since it is inherited from the base class
       << " # sold: " << n << "total due: " << ret << std::endl;
    return ret;
}

// we can call this function by passing a Bulk_quote or Quote object
// also, since the parameter to the Quote or Bulk_quote object is a reference
// and net_price is a virtual function, the version of net_price() that is run
// will depend on the type of the object that is passed to print_total
// the decision as to which version of the net_price function to run depends on
// the type of the argument. Therefore dynamic binding is sometimes known as
// run-time binding

// in C++, dyanmic binding happens when a virutal function is called through
// a reference (or a pointer) to a base class.
// this is why previuosly we implemented function taking references to
// general std::istream objects, since derived classes can also be used
//