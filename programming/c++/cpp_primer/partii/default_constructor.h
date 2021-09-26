#ifndef DEFAULTCONSTRUCTOR 
#define DEFAULTCONSTRUCTOR 1 

#include <iostream>
#include <string>
#include <vector>

// the default constructor is used automatically
// whenever an object is default or value initialized

// default initialization happens 
// -- define nonstatic variables or arrays at global scope without initializers
// -- when a constructor is used without an initializer list
// -- when a class has a class member that uses the synthesized default constructor

// value initialisation happens 
// -- explicitly when use T var_name() where T is the type name
// -- when a static object is defined without an initializer
// -- when an array is given an initializer list that is smaller than 
// the dimension of the array
class ConstructorRole {

    public:

    private:

};


// from below, the learning is that whenever a class 
// has a constructor that is not the default constructor
// THE BEST PRACTICE IS TO ALWAYS EXPLICITLY DEFINE A DEFAULT CONSTRUCTOR
// for in the case when a class type is declared and not initialized
// when it comes to intializing it using the default constructor,
// it will fail, since the default constructor is not defined.
// for example the class NoDefault does not define a default constructor
// as a result, creating members of type A fail, since the default constructor 
// in A, will try to use the default constructor for class NoDefault
// but that is not defined
// In B, a constructor is defined with no initializer list
// as a result, b_member will be default initialized, however 
// class NoDefault does not define a default constructor
class NoDefault {

    public:
        // NoDefault() = default;
        NoDefault(const std::string&);

    private:


};

struct A {
    NoDefault my_mem;
};

// won't be able to default initialize a, since my_mem cannot be default initialized
// due to their being no default constructor in NoDefault
A a;

struct B {
    // B() {} // initializer list is empty, so b_member should be default_initialized
    // but there is no default constructor for class NoDefault
    NoDefault b_member;
};


class StandardCase {

    public:
        // explictly define a default constructor
        StandardCase() = default;
    private:

}; 

// since StandardCase has a default constructor, 
// the below is fine, provided that the default constructor 
// initializes the data members of StandardCase in a meaningful way
// i.e in-class initialized.
StandardCase obj_1;


// some exercises
class NoDefaultTwo {

    public:
        // no default constructor
        NoDefaultTwo(int); 

    private:
};

class C {

    public:
        // need to make sure some_member is initialized with an int 
        // in the constructor for this class - otherwise error
        C() : some_member(0) {}

    private:
        NoDefaultTwo some_member; 
        // illegal since cannot use value initialization within a class via a constructor in
        // this way
        // std::vector<NoDefaultTwo> vec(10, 0);
        // list initialization works though 
        std::vector<NoDefaultTwo> vec{NoDefaultTwo(0)};
};

std::vector<NoDefaultTwo> vec(10);


#endif 