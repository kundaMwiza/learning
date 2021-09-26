#include <iostream> 

int main() { 

    // a constant expression is an expression whose value cannot change
    // and that can be evaluated at compile time. a literal for example is a
    // constant expression. whether a given object is a constant expression
    // depends on the type and the initializers, e.g.

    const int max_files = 20; // max_files is a constant expression
    const int limit = max_files + 1; // limit is a constant expression
    int staff_size = 27; // staff_size is a constant expr, initialized from a ptr
    // const int sz = get_size(); // this is not a constant expr since cannot be evaluated at
    // compile time, 

    // note the difference between constant expressions and constant objects
    // constant objects are objects with values that cannot be changed, and can 
    // be initialized at RUN time or COMPILE time, whilst constant expressions
    // must be able to be evaluated at compile time

    // in c++ 11, can ask the compiler to verify that a variable is 
    // a constant expression by declaring the variable in a constexpr declaration.
    // variables declared as constexpr are implicitly const and must be initialized
    // by constant eexpressions
    // for example
    // constexpr int mf = 20; // 20 is a constant expression
    // constexpr int limit = mf + 1; // mf is a constant expression, so mf + 1 is a constant expression
    // constexpr int sz = size(); // if size is a constexpr function, then sz will also be a constant expression 
    // size must be function simple enough that the compiler can evaluate it at compile time. 
    // generally it is a good idea to use constexpr for variables that you intend to use as constant expressions

    // constexpr implicitly creates top level const objects, so using the constexpr keyword 
    // with pointers creates top level const pointers, not low level const 
    // to create a top/low level const pointer, you need to specify that the type of the object
    // referenced is const when using the constexpr keyword:
    // constexpr const int *p = nullptr; creates a constant pointer that points to a constant int

    // note that you cannot use constexpr with pointers defined inside a function to point to a lcoal
    // variable creates inside the function, since the memory location of variables defined inside a function
    // will change between function calls. It is possible to create variables inside functions that behave
    // likve global variables, and constexpr base_type *p = &obj; can be used with such objects


    return 0; 
}