#ifndef STATICMEMBERS
#define STATICMEMBERS 1 

#include <iostream>
#include <string>
#include <vector>

// for static members in a function, such members persist 
// across different calls to a function

// similarly, sometimes we need a class member 
// that has the same state irrespective of the class instance
// we may need that class member if changed, to affect all 
// class instances, rather than having to change 
// the value of that class member for each instance






// since static class objects and functions are not bound to any instance
// can refer to static objects and functions by using the scope operator 
// e.g. ExampleClass::class_no 
// to access the static object class_no defined for ExampleClass

// even though static objects and functions are not bound to any instance 
// of a class, can also access them through any object, reference or pointer 
// to the class type 
// e.g. ExampleClass one;
// ExampleClass *two = &one;
// one.class_no 
// one->class_no 
// can be used to access static objects and functions

// member functions of a class can use static objects and functions 
// but static objects and functions may not refer implicitly or explicitly via 'this' 
// to a (non static) class member or function


class ExampleClass {

    // static members can be either private or public
    // they can also be const/ non const

    // the static members of a class exist outside any object
    // objects to not contain data associated with static data members
    // so each ExampleClass object will only contain one data member 
    // that is not accessible to users outside the class (n_class_name)

    // similarly, static member functions are not bound to any object
    // they do not have a 'this' pointer, so cannot be const/ non const
    // 'member functions'. Static class functions can only access static 
    // class objects. It is an error to explicitly or implictly 
    // use 'this' e.g. this.some_var, or (non_static_var) some_var ~some operation
    // however, static class functoins can receive a reference or pointer to a 
    // class instance as input

    // since static members are not bound to any instance of a class 
    // they are not initialized when an instance of a class is created
    // to initialize a static members, it generally must be done outside of the class
    // through the scope operator. Static members can only be initialized once
    // as with ordinary static objects

    // BEST PRACTICE; 
    // since static members are defined only once, it is best to 
    // define them in the same header as the definition of the class' 
    // non inline member functions

    public:

        static int class_no;
        static std::string return_class_name() {return class_name; }

        // to define static objects or functions outside the class 
        // as with the keyword explicit, may only use the static keyword 
        // at declaration within the class, not outside the class
        static void some_external_defined_func();

        // some exceptions to having to define static members outside of the 
        // class are static members that are const integral type
        // or constexpr objects which must be initialized within the class body
        // for example 
        // static constexpr int some_var = 5; // some_var is a constant expression
        // or static const int some_var = 5; //  some_var is of integral type

        // BEST PRACTICE, except for constexpr static objects, 
        // all static objects should be initialized outside of the class

    private:

        static std::string class_name; 
        std::string n_class_name; 



};

// initializing a static member object 
// must specify the type of the object
// similar to how functions defined outside the class
// are defined
int ExampleClass::class_no = 5;



#endif