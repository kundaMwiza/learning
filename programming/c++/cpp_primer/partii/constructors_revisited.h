#ifndef CONSTRUCTORSREVISITED
#define CONSTRUCTORSREVISITED 1

#include <iostream>
#include <string>
#include <vector>

// when variables are defined, we typically initialize them 
// immediately rather than defining them and then assigning
// declare and define through initialisation
std::string foo = "Hello World!";

// default initialise bar to the empty string
std::string bar;
// assign a new string to bar 
bar = "Hello World!";

// if we do not explicitly initialize a member 
// in the constructor initializer list, then the data member 
// is default initialized before the constructor body 
// starts executing

class someClass {

    // friends go here - note that they are only access specifiers 
    // not declarations, any functions or variables, if they are to be 
    // used within the class, should be declared, preferably through a 
    // header file
    
    // access specifiers
    public: 
        // overloaded constructors
        someClass() = default;
        
        // define constructor outside of class
        someClass(std::string, int, double);

        // NOTE: we must use the constructor initialier list to provide 
        // values for members that are const, reference, or of class type 
        // that do not have a default constructor
        // ADVICE: routiely use the constructor initializer list.


        // Best Practices:
        // it is best to write constructor initializers in the same order 
        // as the members are declared. Also avoid using members to
        // initialie other members, as the order of initialization matters

        // just like normal functions,can give constructor functions 
        // default arguments - below bookNo initialized from a default 
        // argument if the user does not pass one
        someClass(int us, double rev, std::string bkno = " ")
            : units_sold(us), revenue(rev), bookNo(bkno) {}


        // delegating constructors, take an initializer list that consists of a single 
        // entry, the class name, which corresponds to another constructor within 
        // the same class, to use that constructor to initialize data members
        // e.g. 
        // the below delegating constructor delegates the work to the above constructor 
        // this is the same definition as the default constructor
        // this is provided by the new standard 
        // and is a preferable way of writing default constructors..
        // note that when a constructor delegates
        // the function body of the constructor is also run...
        someClass()
            : someClass(0, 0.0, "") {}
 

    private:
        std::string bookNo; 
        int units_sold;
        double revenue; 
};


// since the parameters and function body are in the scope 
// of the class, do not have to prefix data members with the 
// class name
someClass::someClass(std::string s, int us, double rev)
// no class initializer list - all data members are default initialized 
// since there are no in-class initializers
{   
    bookNo = s; // bookNo reassigned from empty string to the new string s 
    // similarly for the two below
    units_sold = us;
    revenue = rev; 

    // if any data member were const or a reference, 
    // there would be a compile time error here
    // similarly, any class type data member that does not define 
    // a default constructor would also need to be initialized


}


class ConstRef {

    public:
        // ConstRef() = default;
        // 
        ConstRef(int ii); 
    private:
        int i;
        const int ci;
        int &ri;
}

// ConstRef::ConstRef(int ii) 
// { 
//     // initialization is complete by the time the function body begins executing
//     i = ii; // fine since plain int, and can be default initialized to zero
//     ci = ii; // error since ci has been default initialized, and this is assignment
//     ri = ii; // compile time error -> ri not initialized
// }


#endif 