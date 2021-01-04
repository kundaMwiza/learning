#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout; 
using std::endl;
using std::string;
using std::vector; 

int main() {

    // array is a similar data structure that is similar to the library vector type
    // but offers a different trade-off between performance and flexibility. Like a vector
    // an array is a container of unnamed objects of a single type that can be accessed by position
    
    // arrays have a fixed size - cannot add elements to an array via append
    // the fixed size nature of arrays sometimes offer better performance run-time 
    // for specialized applications -> run-time advantage comes at the cost of a loss 
    //  in flexibility
    
    // tip -> if you don't know how many elements you need, use a vector

    // arrays are a compound type -> an array declarator has the form a[d]
    // recall that a declarator is an identifier that can also have a 
    // compound type modifier e.g. references or pointers
    // a is the identifier, and d is the dimension of the array
    // the number of elements in an array is part of the arrays type. 
    // as a result, the dimension must be known at compile time, which means
    // that the dimension must be a constant expression

    unsigned cnt = 42; // not a constant expression
    constexpr unsigned sz = 42; // constant expression

    int arr[10]; // creates an array of 10 ints
    int *parr[sz]; // creates an array of sz pointers to int
    string bad[cnt]; // error because cnt is not const
    string strs[sz]; // creates an array of 42 strings

    // by default, the elements in an array are default initialized
    // if defined inside a function, the default initialized values 
    // may be undefined

    // to explicitly intialize an array with elements -> use list initialization
    //

    int ia1[3] = {0, 1, 2}; 
    int a2[] = {0, 1, 2}; // compiler infers dimension from the number of initializers
    int a3[5] = {0, 1, 2}; // the first three elements are used to initialize the first three valued
                           // the remaining elements are value intialized
    string a4[3] = {"hi", "bye"}; // an array of strings with the last element initialized to the empty string
    // int a5[2] = {0, 1, 2}; // error because the number of initializers is ggreater than the size of hte array

    return 0; 
}