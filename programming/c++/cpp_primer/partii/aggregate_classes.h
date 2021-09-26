#ifndef AGGREGATECLASS 
#define AGGREGATECLASS 1 

// #include goes here 
#include <string>
#include <iostream>
#include <vector>

// an aggregate class gives users direct access to its members and has 
// special initialization syntax. A class is an aggregate if:
//  - all of its data members are public 
//  - it has no in class initializers
//  - it has no base classes or vitual functions

// aggregate classes are more difficult to maintain 
// for example if the order of declaration of class data members 
// changes, then all user source code using the class will have to be updated
// it is better to use classes in this setting since class constructors 
// can be modified without affecting user code

// for example all data members and functions of structs by default 
// are public, so structs are an example of aggregate classes

struct SomeData {

    int member_one;
    std::string some_string;

}; 

// to initialise the above aggregate class:
// the initialization must contain no more initializers than the number of 
// data members, and the initializers must be in the same order 
// that the data members are declared. E.g. placing the string initializer 
// first, and then the integer would result in error?
SomeData instance_one = {5, "the quick brown fox jumps over the lazy dog"};


class AggregateClass {
    
    // friends go here
    
    public:

    private:

}; 


#endif 