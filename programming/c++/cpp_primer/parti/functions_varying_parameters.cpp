#include <iostream>
#include <string>
#include <initializer_list> 

using namespace std; 

void error_msg(int, initializer_list<string>); 

int main() {


    // if varying arguments are reguired for a function, c++11
    // provides two primary ways to write a function that takes
    // a varying number of arguments:
    // if all the arguments have the same type, can pass a library type
    // named initializer_list. If the argument types vary, can write 2
    // a special kind of function, known as a variadic template
    // The last way is using elipsis, which should realy only be used
    // in programs that need to interfact to C functions.

    // --- initializer-list parameters
    // function that takes an unknown number of arguments of a single 
    // type by using an initializer_list parameter.
    // initializer_list is a template type that represents an array of 
    // values of the specified type
    // initializer_list - operations
    // creates an empty list of elements of type int
    // values in an initializer list are always of type const
    // since the type is implicitly initializer_list<const T> where T is the type
    // there is no way of changing the values in the initializer list
    initializer_list<int> lst_one;
    // lst_two has as many elements as there are initialiers
    // elements in the list are const
    initializer_list<int> lst_two{5, 4, 6};
    // lst_two(lst_one), or lst_two = lst_one 
    // copying or assigning an initializer_list does not copy the elements
    // in the list, after teh copy both lists share the elements
    // lst_one.size() -> number of elements in the list. lst_one.begin()
    // lst_one.end() returns a pointer to the start of the list and 
    // one past the end of the list respectively

    // when passing a sequence of values to an initializer_list parameter,
    // the arguments must be enclosed in curly braces e.g. 
    // error_msg(5, {"sequence", "of", "strings"})
    // also note that initializer_list is a sequence type, therefore can use 
    // a range-for with initialzer_list<t> types


    // --- ellipsis parameters
    // these are in c++ to allow programs to interfact to C code that uses
    // a C library facility named varargs.
    // an ellipsis parameter can only appear as the last element in a parameter
    // list e.g. void foo(int some_arg, ...);
    // there is no type checking for arguments passed to ellipsis
    return 0;
}


void error_msg(int some_other_arg, initializer_list<string> err_msg) {

    // print the error messages contained in err_msg
    // all elements are const, so can't change the values
    for (auto start = err_msg.begin(); start != err_msg.end(); ++start) {
        cout << *start << endl; 
    }

}