#include <iostream> 

// by default, when a const object is initialized from a compile-time constant,
// the compiler will replace that variable whenever it is used with its value
// to be able to do this, the compiler must have access to the initializer of
// of the const variable. So by default a const object is local to a file in 
// order for this to happen. redefining the same variable in several files
// is treated as creating distinct variables. 

// if there is a const variable that we would like to share across several files
// but the initializer is not a constant expression e.g. a function, we may 
// not want the compiler to generate a separate variable in each file. Instead
// create a single instance of a const variable, and share it across files. 
// to do this, at the point of defining a const variable, we use the keyword extern
// when it is defined, as well as when it is declared in other files:

// defined in this file
// extern const int some_imp_var = some_fn();
// in another file it is declared, signalling that some_imp_var
// is a constant, but is defined in another file
// extern const int some_imp_var; 

int main() { 
    //  defining a variable whose value we know cannot be changed
    // we can make a variable unchangeable by defining the variable's 
    // type as const

    // creates a variable of type int initialized to 512 that cannot be changed
    // any attempt to change the value of buff_size is an error
    // because we cannot change the value of a const variable after we create it
    // it must be initialized at the point of definition, which can be at compile time
    // or run time, but the key is that it must be initialized
    const int buff_size = 512; 

    //  a const type can only use the non-mutable operations of an object
    // eg can use a const int in arithmetic operations in the same way as 
    // a plain old int.

    // int ex1 = 5;

    // std::cout << "using var++, the value returned is the value of var before incrementing: " << ex1++ << std::endl; 
    // std::cout << "now check the value of var to see that it has been  incremented " << ex1 << std::endl; 
    // std::cout << "using ++var, the value returned is the value of var after it has been incremented: " << ++ex1 << std::endl;
    // std::cout << "now check the value of var to see that is the same as the previous output " << ex1 << std::endl;   

    //  since constants are objects, you can define a reference to such objects
    // eg a reference to buff_size can be defined in the following way:
    const int &ref = buff_size;


    // top level const refer to objects which are themselves constant
    // low level const refer to referenced objects that are const e.g. by references and pointers
    // example top level consts

    int int_1 = 0; 
    int *const p1 = &int_i; // constant ptr p1
    const int ci = 42; // constant integer ci
    const int * p2 = &ci; // low level const 
    const int *const p3 = p2; // p3 is both a low/top level const
    const int &r = ci; // references can only be low level const, r is reference


    // when assigning a variables value, top level const is ignored since it matters not that the
    // object is copied, so long as it is not modified
    // however for low level const matters since the type of the object that is referenced matters
    // both objects must have the same low-level const qualification of there must be a conversion
    // between the two objects, in general you can convert between non const to const, but not a const 
    // to non const - since the copied will then be modifiable, which defeats the point of making
    // the RHS object a const
    // some examples
    // int *p = p3; this is an error since p3 is a low level const, cannot convert const to non const
    p2 = p3; // this is fine since both p2 and p3 are low level const
    p2 = &i; // i is a non const int, but can be converted to a const int
    // int &r = ci; error since ci is const but r is being defined to be a non const - would allow changing 
    // the value of ci, which is const..
    const int &r2 = i; // i is not const, but can be converted to a const int 

    // int temp0  = 5; 
    // constexpr int *temp1 = &temp0;
    // temp1 = &int_1; 
    
    return 0; 


}
