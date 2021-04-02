#include<iostream>
#include<string>
#include<vector>

using namespace std; 

// // declaring an inline function
// inline const string &rtn_shorter_string(const string &str_1, const string &str_2);
// // declaring a consexpr function
// constexpr int some_size(int); 

int main() {

    // -- default argumetns
    // see below


    // -- inline and constexpr functions
    // one potential drawback of calling a function is that
    // calling a function is apt to be slower than evaluating the 
    // equivalent expressions within the functions directly
    // on most machines, a function call does several pieces of work
    // saving registers and restoring registers after function execution
    // arguments may be copied, and the program branches to a new location

    // inline functions avoid function call overheard
    // an inline function is expanded inline at each call
    // so that the overheard of making a function call is removed
    // syntax for making an inline function is to use the keyword inline
    // before the function return type


    // -- constexpr function is a function that can be used in a constant expression
    // e.g. constexpr int some_var = some_func(); 
    // the return type and the type of each parameter must be a literal type AND 
    // the function should only contain one use of the return keyword
    // in essence, the compiler must be able to verify that the function return 
    // type is a constexpr - is what is required.
    // constexpr functions are implicitly inline functions
    // when a constexpr function is called, the compiler will replace a call 
    // to a constexpr function with its resulting value.
    // NOTE a constexpr function is not required to return a constant expression
    // see below for an example

    // -- inline and constexpr functions
    // unlike normal functions, inline and constexpr functions should be ideally
    // defined inside header files accompanying source files. Since the compiler 
    // needs the function definition in order to expand the function inline
    // also, inline and constexpr functions may be defined several times,
    // so long as the definitions are the same
    return 0; 
}

// -- default arguments example
// if a parameter has a default argument, all the parameters that follow it
// as in the below scenario must also have default arguments. that is, 
// you cannot have non default arguments proceeding default arguments
// whilst its legal to redeclare a function several times, it is illegal
// to specify/ mutate the values of parameters with default values multiple times
// BEST PRACTICE: default arguments should be specified with the function declaration 
// in the appropriate header
// default arguments can be any non local variable, and a type that can be cast to 
// the parameter type
// names used as arguments for default arguments are resolved in the scope that the function
// is called. So if a variable is mutated, the default argument will also change.
// it is therefore best to provide default arguments using rvalues
long int sum_of_first(const vector<int> &arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, const int num = 3) {

    long int result = 0;

    // looping first case
    for (vector<int>::size_type idxr = 0; idxr != arr.size() && idxr < num; ++idxr) {
        result += arr[idxr];
    }

    // // looping using iterators 
    // for (auto start = arr.begin(); start != arr.end(); ++start) {
    //     result += *start; 
    // }

    // // range for
    // for (auto vec_elem_ref : arr) {
    //     result += vec_elem_ref; 
    // }
    

    

    return result; 


}


// use the inline keyword to roll out the function when it is called 
// so that the function call overheard can be avoided
// NOTE the inline specification is only a request to the compiler
// the compiler may choose to ignore the request
// in general the inline mechanism is meant to optimize small
// straight-line functions that are called frequently
inline const string &rtn_shorter_string(const string &str_1, const string &str_2) {

    return str_1.size() < str_2.size() ? str_1 : str_2; 
}

// -- constexpr function
// this function can be used in places where a constant expression is required
// provided that the function has an execution path that returns a constant expression (depends on the input)
// functions such as this may be useful where the dimension of an array is to be specified
// e.g. for example  in the second version of the below function
// if the input is a const int, will be constexpr, however if the input is a plain int
// then the result will not be a constexpr
// typically a constexpr function is a function that returns a 
// value that can be resolved by the compiler at compile time
constexpr int some_size(const int input) { return 4 * input; }
constexpr int some_size(int input) {return 4 * input; }

// int some_arr[10] = {0};
// int (*ptr_to_arr)[10] = &some_arr;

// different ways to define functions that return pointers to arrays of 10 ints
// int (*ptr_to_array_ints(vector<int> &arr_int))[10] {

// }

// decltype(ptr_to_arr) ptr_to_array_ints(vector<int> &arr_int) {

// }

// auto ptr_to_array_ints(vector<int> &arr_int) -> int (*)[10] {

// }

