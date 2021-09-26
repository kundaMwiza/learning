#include <iostream>
#include <string>
#include <vector>

using namespace std; 

string string_function_1(const string &, const string &);

int main() {

    // a return statement terminates the function that is currently 
    // executing and returns control to the point from which the 
    // function was called

    // return; returns void 
    // return expression; 

    // a return with no value can only be used if a function has a 
    // return type of void. Functions that return void are not required
    // to have a return statement ~its implicit
    // but can use return; to exist the function at an intermediate
    // point - like break;


    // the second form of the return statement provides the function's result
    // how values are returned:
    // values are returned in the same way that variables and parameters 
    // are initialized. the return value is used to initialize a temporary
    // at the call operator site, and that temporary is the result of the function call
    // when initialising a variable or a parameter, this can be done by copying
    // or by reference. Similarly, when a value is returned from a function
    // it is bound to a temporary reference variable, or copied into a temporary variable
    // similar to the variable/ parameter initialisation setup, copying large variables
    // affects the time and space usage of a program
    // see below examples

    //-- functions that return class types and the call operator
    // the call operator also has precedence, associativity and 
    // order of evaluation
    // e.g. the call operator has the same precedence as the dot and 
    // arrow operator, so the follwoing 
    // auto string_size = some_string_op(string).size()
    // operands group from the left, the first call operator is executed
    // and the result of that is the left hand operand to the dot operator
    // which fetches the size member of the class type, and finally
    // the call operator is executed


    // -- reference returns are lvalues, all other returns are r values 
    // so its perfectly legal to write 
    // reference_return_func(arg1, arg2) = value;
    // provided the reference is not to a const type

    // -- brief detour -> lvalues are expressions that have names 
    // and their resource cannot be reused, as it has already been allocated 
    // (unless freed) e.g. myarr[0], int x = y 

    // rvalues are expressions that don't have names and their resource 
    // can be reused, since they temporary e.g. "blah", g(func())
    // func returns a temporary variable to be consumed by g
    // these temporary objects cannot be referred to by name..

    // l value reference are references to lvalue expressions
    // r value reference are references to rvalue expressions
    // an rvalue reference i.e T &&, is an lvalue expression 
    // in the context that it is being used in

    // ALL FUNCTIONS IN CPP either return a reference, or not
    // if they return a reference, the return type is an lvalue 
    // else it is an rvalue
    

    // under the new standard, functions can return a braced list of 
    // values, these values are used to initialise a temporary variable 
    // that has the type specified by the function type - this temporary
    // variable is similar to a temporary variable that is created
    // when creating a const reference to a literal

    // -- list intialising the return value
    // see below function for an example


    // -- return from main
    // one exception to the rule that all functions with a return 
    // type other than void must return a value is the main function
    // which is allowed to terminate without a return
    // if control reaches the end of main and there is no return
    // the compiler implicitly inserts a return of 0
    // typically the returned value is an int, and represents 
    // a status indicator. zero returns are for success, other returns
    // typically indicate failure


    // -- returning a pointer to an array
    // since arrays cannot be copied, and they are usually resolved to 
    // a pointer to the first element, cannot return an array
    // instead can return a pointer to the array or a reference 
    // to the array
    // see below for functions that return a pointer / reference resp 
    // to arrays of dimension k


    // -- using a trailing return type
    // under the new standard, another way to simplify the declaration of func
    // is by using a trailing return type. trailing returns can be defined 
    // for any function, but most useful for functions with complicated return types
    // e.g. pointers or references to arrays
    // a trailing return type follows the parameter list and is preceded by ->
    // to signal that the return follows the parameter list, we use auto where 
    // the return type ordinarily appears
    // see below for an example showcasing a function returning a pointer to 
    // 10 ints

    // alternatively, can also use decltype(expression) to determine the type of 
    // the function return
    // e.g. 

    int odd_arr[] = {1, 3, 5};
    int even_arr[] = {2, 4, 6};

    // defining the function with decltype(odd_arr) *func_name(params) {}
    // decltype(odd_arr) will be resolved to an array of 10 ints, therefore 
    // the function return type will be a pointer to an array of 10 ints
    return 0;
}



// since the return type is a plain string, at the point of return
// a copy of either str_1 or str_2 is used to initialize 
// the returning string object
// note also that when str_1 and str_2 are returned, the reference 
// is just an alias for a TOP level const string, which is ignored
// when initialising the temporary string variable
// if the reference where to const string arr, and the return type was 
// string arr, this would not work as the const string arr would 
// be converted to a pointer to a const string, which is low level const
string string_function_1(const string &str_1, const string &str_2) {

    return str_1.size() < str_2.size() ? str_1 : str_2; 
}


// in this case the temporary variable is just a reference to the 
// returning object (str_1 or str_2)
// In this case, the arguments and the returned strings are not 
// copied, since a reference is returned instead
const string &string_function_2(const string &str_1, const string &str_2) {

    return str_1.size() < str_2.size() ? str_1 : str_2; 
}

// references or pointers to local objects should not be returned from 
// a function call 
// for example 
// in the below function, s is clearly a local object,
// literals are temporary objects within a particular scope
// so "some_string" is also a local object
// when the function terminates, memory consumed by the function
// during execution is freed, which means that the references are referring
// to undefined memory locations. For the same reason
// pointers to local objects should not be returned. 
// references or pointers should only be returned to the outer scope
// if objects corresponding to those memory locations exists
// e.g. in the second return statement, str_1 and str_2 are referencing 
// preexisting (before the function executes) objects 
const string &string_function_3(const string &str_1, const string &str_2) {

    string s; 

    // bad return str_1.size() < str_2.size() ? s : "some string"
    // okay return str_1.size() < str_2.size() ? str_1 : str_2; 
}



// the return value is used to initialise a temporary variable 
// of type vector<string> 
vector<string> list_initialise_vector_fun() {

    string s1 = "rah", s2 = "dah";

    return {s1, s2, "some other string"};
}

// to return a reference or pointer to an array, need to know the 
// dimension of the array by providing a constant expressing 
// giving the dimension of the array 

// reference to an array of 10 ints - not that the array must exist in the 
// outer scope of the function, since undefined behaviour ensues to reference 
// local objects within functions, that are freed at the end of execution
// function definition is similar when defining a reference to an array or 
// a pointer to an array. e.g. int (*p)[10] -> pointer to an array of 10 ints
// note here that initialisation of the temporary return variable is valid 
// since top level const is ignored
int (&return_reference_to_arr(const int (&some_arr)[10]))[10] {


    return some_arr; // return a reference to an array of 10 ints
}


int (*return_pointer_to_arr(const int (&some_arr)[10])[10]) {

    return &some_arr; // return a pointer to an array of 10 ints
}


// use auto to indicate that the type of the function is to be 
// deduced from the expression after ->
auto nstndr_return_pointer_to_arr(const int (&arr_ref)[10]) -> int (*)[10] {
    return &arr_ref; 
}