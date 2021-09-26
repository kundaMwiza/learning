#ifndef CPPCLASS 
#define CPPCLASS 1

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

// fundamental ideas behind classes are data abstraction
// and encapsulation. Data abstraction relies on the separation
// of interface and implementation
// encapsulation enforces the separation of a class' interfact 
// and implementation
//  

// in a class, member functions have to be declared
// though the function definitions can be outside of the class
// member functions are implicitly in inline. So as with inline 
// functions and constexpr functions, member functions 
// can be defined inside the header file.
// Since for inline functions, (constexpr functions are implicitly inline)
// the compiler has to be able to resolve the definition of the function
// and so its fine if the function is defined inside a header file
struct salesData {
    string bookNo;                                             
    unsigned units_sold = 0;
    double revenue = 0.0;
    // here there is no reference to the specific instance of 
    // salesData to return the bookNo object
    // each instance of salesData has its own scope
    // so bookNo is obtained from the instance that calls 
    // the function isbn e.g. salesData total; total.isbn() -> total.bookNo
    // member functions access the object on which they are called through an extra
    // implicit parameter named 'this' ~similar to self in Python
    // when a member function is called e.g. total.isbn()
    // it is implictly resolved to salesData::isbn(&total) <- specific instance calling the function
    // in C++, don't have to use self to refer to the specific instance's data members or functions

    // it is therefore ILLEGAL to define a member variable named this
    // similar to defining self in Python
    // could define the below function as (explicitly), though unneccesary..
    // since the compiler resolves this for us
    // string &isbn() const {return this->bookNo}; 

    // by default, this is a const pointer to a NON const class instance
    // e.g. salesData * const this
    // in other words, ordinary member functions have the ability to 
    // modify the class instance 
    // however, in some cases, some member functions do not modify 
    // a class instance, and in this case, it is the same as 
    // accessing a const class instance e.g. const salesData * const this
    // moreover, for const salesData objects, since 'this' is usually 
    // defined as salesData * const this, it means that 
    // non const member functions CANNOT be used.
    // in order to allow member functions that DO NOT modify the class instance
    // must have 'this' think its pointing to a const salesData
    // and this is done by placing const after the parameter list
    // since 'this' is implicit, it has no place in the parameter list

    // const member function, can be used on a const/ non const salesData instance
    // (remember, can initialise a reference/pointer to const from a const or non const object,
    // however, cannot initialise a reference/pointer to non const from a const object)
    // essentially, functions that modify an instance should be non const member functions
    // those that do not, should be const member functions
    string &isbn() const {return bookNo};

    // non const member function, can only be used on non const salesData instances
    // as a definition, we can have salesData &combine
    salesData &combine(const salesData &book); 
    salesData add(const salesData &book);
    double avg_price() const;
    std::istream &read(std::istream&, const salesData &book);
    std::ostream &print(std::ostream&, const salesData &book);

    // when the compiler parses a class, the declarations are done first
    // and then the member function bodies are parsed
    // this means that member functions can refer
    // to member variables defined anywhere in the class, unlike Python 
    // which is interpreted and thus relies on order

    // member functions defined inside a class are implictitly inline
    // however to define a member function outside the class 
    // must prefix the function name with the scope operator 
    // to resolve which class the member function belongs to 
    // i.e. double salesData::avg_price() {...}
    // which declares that avg_price is a salesData member function
    // if avg_price is a const member function, it should also 
    // have const after the parameter list
}; 

// since book here is a reference to a const salesData instance
// may only use const member functions on book
// returning a reference to 'this'
// since 'this' is ordinarily a salesData * const this
// to return a reference to an instance of salesData, 
// just dereference 'this' i.e return *this
// note that references are just aliases
// when the combine function is called
// this is bound to the calling instance of salesData 
salesData &salesData::combine(const salesData &book)
    // below implictly doing this->revenue += book.revenue 
    revenue += book.revenue;
    units_sold += book.units_sold;

    // also note that since book is a reference to a const 
    // salesData instance, may not use non const member functions for 
    // book

    // return a reference to the calling instance
    // this is salesData * const, so need to dereference
    // note that this function returns an lvalue, since it returns a reference
    return *this;


#endif

