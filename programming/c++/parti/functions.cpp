#include <iostream>
#include <vector>
#include <string>

using std::cin; 
using std::cout;
using std::endl; 
int main() {

    // a function is a block of code with a name. Execute teh code by calling the function./
    // The same function name can be used to define several functions (overloading) 
    // function definition consists of a return type, an identifier, a list of zero or more 
    // parameters, and a function body. The function is executed through a call operator, 
    // which is a pair of parenthesis. The call operator takes an expression that is a function or
    // or points to a function (a pointer to a function)
    // inside the parenthesis are comma separated arguments. The arguments are used to initialize 
    // the functions parameters. The type of a call expression is the return type of the function

    int out; 

    out = fact(6); 

    cout << out << endl; 

    // a function call does two things: it initializes the function;s parameters from the 
    // correspondong arguments, and transfers control to that function. Execution of the calling function
    // is suspended and execution of the called function begins.

    // execution of a function begins with the implicit definition and initialization of its parameters
    // when the function fact is called, an int variable val is defined, using the supplied argument as 
    // its initializer
    // execution of a function ends when a return statement is encountered and the return statement 
    // does two things. It returns the return value and transferes control out of the called function 
    // back to the calling function

    // the order of evaluation of a functions arguments by the call operator are indeterminate - 
    // the compiler is free to evaluate the arguments in whatever order is preferred


    // when calling a function, note that local variables in the outermost scope of the function 
    // cannot have the same name as any function parameter


    // a function return type can be void -> which means that the function returns no value
    // a function CANNOT return an array or a function type
    // you can return a pointer to an array or function however.

    // in c++, names have scope, and objects have lifetimes
    // - scope of a name is the part of the program's text in which that name is visible
    // - lifetime of an object is the time during the program's exeuction that the object exists

    // objects defined outside any function exist throughout the program's execution. Such objects
    // are created when the program starts and are not destroyed until the program ends
    // the lifetime of a local variable depends on how it is defined

    // objects that exist only while a block is executing are known as AUTOMATIC OBJECTS.
    // after execution exits a block, the values of the automatic objects created in that block
    // are undefined e.g parameters are automatic objects. Storage for the parameters 
    // is allocated when the function begins

    // LOCAL STATIC OBJECTS - variables whose lifetime continues across calls to the function
    // such objects are obtained by defining the local variable as static
    // static objects are initialised BEFORE the first time execution passes through the objects 
    // definition. local static objects are not destroyed after function execution, they 
    // persist across function calls:

    // std::size_t count_calls() 
    // {
    //     // it is important to explicitly initialise local static objects
    //     // built in local static objects are value initialized to zero
    //     static std::size_t ctr = 0; 
    //     return ++ctr; 
    // }

    cout << count_calls() << endl;

    cout << count_calls() << endl; 

    // for variables, it is best to declare them in header files, but define them in source files
    // similarly, for functions, it is best to declare them in header files, and define them in source files
    // following this convention ensures that there is a single source of truth for declarations, so that
    // if a function definition changes, only one header file needs to be changed

    // separate compilation - C++ supports compiling source files independently. This is useful where a program
    // is created from constituent parts. To compile the different source files, they need to be supplied at 
    // compilation e.g. g++ -std=c++11 -c func_main.cpp func.cpp . where func.cpp contains the definition of files
    // func_main contains the main function that is using the functions inside func.cpp. func_main.cpp therefore includes
    // the header file with function declarations e.g. func_header.h.
    // -c here indicates that we want to create object code files, with suffix .o e.g. file1.o
    // the compiler can then link object files together to form an executeable:
    // g++ file1.o file2.o
    // if the source code of one of these files changes, only need to recreate the object code of one of the files
    return 0; 
}

int fact(int val) { 
    
    // local variable to hold the result 
    int ret = 1; 
    while (val > 1) {
        ret *= val--;
    }

    return ret; 

}