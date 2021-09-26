#ifndef WINDOWMGR
#define WINDOWMGR 1


#include <iostream>
#include <string>
#include <vector>

#include "additional_class_features.h"

class WindowMgr {

    public:
        // for const member functions that return a reference to the 
        // instance calling them i.e. 
        // class &some_function() const {.. return *this; }
        // the return type should be const class &some_function const {.. return *this;}
        // since the function is a const member function, the return type is 
        // a reference to a const class instance
        // note that as a consequence, since const class instances 
        // can only call const member functions, cannot use non const member 
        // functions on const instances

        // in the same way that functions can be overloaded based on 
        // references or pointers that are low level const, can also 
        // overload const member functions, so that the function 
        // that is called depends on whether the instance is const or not:
        // class &some_function() { return *this} - will be called on non-const instances
        // const class &some_function() { return *this} - will be called on const instances only
        // overload resolution will determine which of the functions to call
        // when returning *this, it is best to overload a member function depending 
        // on whether an instance is const or not - for it will affect the operations 
        // that can be performed on the instance
        
    private:
        // initializing other class type data members
        // the only permissable ways of initializing a class type
        // data member is to either use the assignment operator '='
        // or via list initialisation:
        // e.g. creating a data member that is a collection of screens:
        // initialized a vector with one Screen object
        // ordinarily would do something such as 
        // Screen some_instance(24, 80, ' '); to initialize a Screen instance
        std::vector<Screen> screen_collection{Screen(24, 80, ' ')};
        // alternatively via assignment
        // std::vector<Screen> screen_collection = { Screen(24, 80, ' ')};
};


#endif 