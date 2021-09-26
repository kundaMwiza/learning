#include <iostream>
#include <string>

class Quote
{

public:
    // create a default constructor in the case a user doesn't
    // provide arguments to initialise the class
    Quote() = default;
    Quote(const std::string &book, double sales_price)
        : bookNo(book), price(sales_price){};

    std::string isbn() const
    {
        return bookNo;
    }

    // derived classes needs to override the
    // defintion it inherits from the base class, by
    // providing its own definition.
    // in c++ a base class must distinguish the functions it expects
    // its derived classes to override from those that it
    // expects its derived classes to inherit without change
    // the base calss defines as virtual those functions it expects
    // its derived classes to override.
    // when we call a virtual function through a pointer or reference
    // the call will be dynamically bound. Depending on the type of the
    // object to which the reference or pointer is bound, the
    // version in the base class or in one of the derived clases
    // will be executed.
    // a base class specifies that a member function should be dynamically bound
    // by preceding its declaration with the keyword virtual
    // any nonstatic member function, other than a class constructor may be virtual
    // the virtual keyword must only appear in the declaration of a member function and
    // may not appear outside the class body
    // a class that declares a function as virtual inside the base class is implicitly
    // virtual in the derived classes as well.
    virtual double net_price(std::size_t n) const
    {
        return n * price;
    }

    // default destructor needed even if they do no work
    virtual ~Quote() = default;

private:
    std::string bookNo;

    // a derived class inherits the members defined in its base class
    // however the member function in a derived class may not
    // necessarily access the members that are inherited from the base class
    // derived classes can access the public members of its base class but may
    // not access the private members. However, sometimes a base class
    // may want to let its derived classes use while still prohibiting
    // access to those same users by other programmers.
    // To declare such members, we use the protected access specifier:
    // public: accessible by all and everyone
    // private: accessible only by friends and the class code, not accessible
    // to users
    // protected: accessible to derived classes but not accessible to users of the
    // derived class
protected:
    double price = 0.0; // normal undiscounted price
};

// derived class Bulk_quote
// public Quote indicates that we can bind an object of a publicly derived
// type to a pointer or reference to the base type
// we may use a Bulk_quote object where a pointer or reference to Quote is expected
// although a derived object contains members that it inherits from its base,
// it cannot directly initialize those members. A derived class must use a
// base-class constructor to initialize its base class part.
// NOTE: each class controls how its members are initialized
class Bulk_quote : public Quote
{

public:
    // define the default constructor
    Bulk_quote() = default;

    // here we call the constructor for the base class to construct
    // the base class subobject part of the derived class
    // this is similar to calling Super.__init__(self, args)
    // in python to initiliase the base class subobject of the derived class
    // as with a class data member, unless indicated
    // the base class subobject is default constructed
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc)
        : Quote(book, price), min_qty(qty), discount(disc){};

    // overrides the function defined in the base class
    // if a derived class does not override a virtual form its base
    // class, then like any other member, the derived class inherits the version
    // defined in its base class
    // the override keyword is used to signal to the compiler
    // that the derived class intends to overide this member function
    // from the base class
    double net_price(std::size_t cnt) const
    {
        if (cnt >= min_qty)
        {
            return cnt * (1 - discount) * price;
        }
        else
        {
            return cnt * price;
        }
    }

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

// structure of a derived class
// a derived object contains multiple parts:
// a subobject containing the nonstatic members defined in the
// derived class itself
// a subobject for each base class from which the derived class inherits

// because a derived object contains subparts corresponding to its base classes,
// we can use an object of a derived type as if it were an object of its base type(s).
// in particular, we can bind a base-class reference or pointer to the base-class part of
// a derived object

// for example:
// Quote item;
// Bulk_quote bulk;
// Quote *p = &item;
// p = &bulk; // bind p to the Quote part of bulk
// Quote &r = bulk // r bound to the Quote part of bulk

// this conversion is often referred to as the derived-to-base conversion
// this conversion is applied implicitly.
// the ability to bind a pointer/ reference to a Quote object using
// a derived class works because the Quote object is a subobject
// of the derived classes.

// the fact that a derived class contains subobjects of its base classes is
// the key to how inheritance works