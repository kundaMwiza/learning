#include <iostream>
#include <string>
#include <vector>

using namespace std; 

float sum_vals(const vector<int> &int_arr);
float sum_vals(const vector<float> &float_arr); 

int main() {

    // -- overloaded functions
    // functions that have the same name but different parameter lists
    // and appear in the same scope are overloaded
    // when the functions are called, the compiler can deduce 
    // which function that is required based on the arguments that 
    // are passed to the function.
    // one note is that the main function may not be overloaded

    vector<int>first_arr{0, 1, 2, 3, 4};
    vector<float>second_arr{0.1, 1.3, 2.4, 3.4, 9.9};

    cout << "using the first int function the result is: "
         << sum_vals(first_arr)
         << endl;

    cout << "using the second float function the result is: "
         << sum_vals(second_arr)
         << endl; 

    // when overloading 
    // type aliasing is ignored
    // top level const is ignored, low level const however indicates
    // a different parameter. In cases where a function is overloaded
    // but the only difference if low level const in the parameters
    // the compiler preferes the nonconst version of the function

    // it is an error for two functions to differ only in terms of their return
    // types. if two functions have the same identifier, and the same parameters
    // but their return type differs, there will be a compilation error

    // calling an overloaded function
    // the process that a compiler uses to determine which function among a set 
    // of overloaded functions to call is called overload resolution or 
    // function matching
    // in most cases it is straightforward for a programmer to determine 
    // whether a particular call is legal due to overloaded functions
    // differening in the number or types of parameters 
    // however in the case when the number of parameters and types are related
    // e.g. low level const, or e.g. an int passed to a function
    // expecting a double (and so would be implicitly cast) is less obvious

    // -- overloading and scope
    // overloading is specific to a scope. When several functions are declared
    // within the same scope, the compiler will only perform
    // function matching/ overload resolution for those functions
    // if in another local scope, one of the functions is declared
    // the compiler will only resolve - find the definition for the 
    // function that is declared in the local scope, other functions
    // with the same name, but not declared in the same scope are ignored
    // So ideally function overloading should be done at the global 
    // scope to prevent masking overloaded functions in outer scopes
    return 0;
}

float sum_vals(const vector<int> &int_arr) {

    float output = 0;

    for (auto &elem : int_arr) {
        output += elem;
    }

    return output;
}

float sum_vals(const vector<float> &float_arr) {

    float output = 0; 

    for (auto &elem : float_arr) {
        output += elem;
    }

    return output;
}
