#ifndef CLASSKEY 
#define CLASSKEY 1 

#include <iostream>
#include <vector>
#include <string>

// in the previous scripts, the c++ keyword struct has been used 
// to define classes. However, there are no restrictions on the data 
// members or member functions that users have access to when 
// interfacing with classes defined with strut.

// -- to encapsulate the class, and control what users have access to,
// access specifiers can be used:
// -- members defined after the public specifier are accessible to all parts 
// of the program. The public members defien the interface to the class
// -- members defined after private are accessible to the member functions 
// of the class, but are not accessible to code that uses the class.
// the private section of a class hides the technical implementation
// and controls what users cannot access.


// if all members are going to be public, create a struct,
// other use the class keyword
// without access specifiers, members declared inside a 'class'
// are private
// inside a struct, they are public

class salesData {

    // only class members can access private data members or functions
    // in order to allow other functions or classes to access 
    // non public members, those classes or functions must be made 
    // friends of the class yb declaring them in the function and using 
    // the friend keyword e.g.

    // the function read now can access the private members of 
    // salesData objects
    friend std::istream &read(std::istream&, salesData &); 
    // main has access to non public members..
    friend int main(); 

    // friends can appear anywhere in the class definitoin only 
    // however friends are not class members!
    // friends must be declared inside a class defintion
    // a friend declaratoin only specifies access, however, 
    // it does not declare that the function is available for 
    // use by members of the function
    // in order for the function to be visible to the class 
    // it must be declared ideally in the same header as the class definition
    // SEPARATE FROM THE FRIEND DECLARATION
    // that is, the header containing the declaration for a function 
    // must be included within the class header, if that function 
    // is to be used by class member functions

    public: // access specifier, users can access
        // public member functions 

        // default constructor, new standard feature
        salesData() = default;
        
        // / construct all data members
        salesData(const std::string &s, unsigned n, double p) 
            : bookNo(s), units_sold(n), revenue(p * n) {}
        
        std::string isbn() const {return bookNo;}

        // functions to be defined outside of the class

        // declare construction via input stream 
        salesData(std::istream&); 

        salesData &combine(const salesData &); 

    private: // access specifier, users cannot access 
        std::string bookNo;
        unsigned units_sold = 0; 
        double revenue = 0.0; 
        
        // const member function
        double avg_price() const {return units_sold != 0 ? revenue / units_sold : 0; }

};

#endif 