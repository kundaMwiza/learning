#ifndef ADDITIONAL
#define ADDITIONAL 1 

#include <iostream>
#include <string>
#include <vector>

// in addition to defining data and function members 
// a class can also define its own local names for types
// declarations for functions or type names are subject
// to the same access controls as any other member of a class
// and may be private or public
// type members or type aliases should be defined before they are used
// so normally appear at the top of the class

// only for class member functions, constexpr and inline functionns 
// should a function be defined in the header file, for all other 
// functions, the definition should be placed in a separate source file
class Screen {

    // friend functions or classes go here..
    
    // in some cases (not very often), can have data members that 
    // should be mutable regardless of whether an instance is const or not
    // such data members are declared using the keyword 'mutable'
    // even const member functions can mutate such data members
    // such members are also subject to access specifiers -> public or private
    // for example to track how many times a particular function is called:

    public:
        // in the standard namespace, in the namespace for string (i.e class), 
        // access the size_type type
        // pos here is a public local type for string::size_type
        // will allow users to have access to this type
        using pos = std::string::size_type;
        // can also use typedef
        // typedef std::string::size_type pos;
        // constructors go here..
        Screen() = default;

        // other constructors - created above synthesized default 
        // constructor since we are providing our own constructor

        // initialise a class instance with the width, height 
        // and contents of the screen
        // here the cursor is in-class initialised with the value zero
        Screen(pos ht, pos wd, char c)
            : height(ht), width(wd), contents(ht * wd, c) {}
        
        // defined cursor to be of size_type so that can index 
        // into contents
        // implictly inline
        char get() const { return contents[cursor]; }

        // overloading a const member function - e.g. 
        // the below will be used for const instances            
        const Screen &return_reference() const {return *this;}
        // the below will be used for non const instances
        Screen &return_reference() {return *this}
        
        // overload the get member function 
        // declared explicitly inline - see below
        char get(pos ht, pos wd) const; 

        Screen &move(pos r, pos c); // function declaration


    private:

        // users do not have direct access to the data members

        pos cursor = 0; // type is std::string::size_type
        pos height = 0, width = 0;
        std::string contents;

        mutable size_t no_access = 0; 


};


class WindowMgr {

    // friend functions or classes go here

    public:

        WindowMgr() = default;

    private:
};


// Since classes have their own local scope
// when defining class member functions,
// immediately when the scope operator is used,
// the function parameters and body have access to the class types  
// as below, pos r and pos c - 
// we do not need to resolve pos as Screen::pos 
// since they are within the scope of the Screen class
// since the return type normally appears before the scope
// we have to still use the scoping operator to refer to 
// class types
inline Screen &Screen::move(pos r, pos c) {

    pos row = r * width; // compute the row location
    cursor = row + c; // move the cursor to the column within that row
    return *this; // return this object as an lvalue
}

// define the overloaded get function
// it is better to place inline with the function defintion
// rather than its declaration
inline char Screen::get(pos r, pos c) const {
    
    // increment a mutable data member to record how many times this function is called
    // modifiable even in a const instancea
    ++no_access; 

    pos row = r * width;
    return contents[row + c];
}


#endif 

