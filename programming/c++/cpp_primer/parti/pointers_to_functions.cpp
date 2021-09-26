#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool lengthCompare(const string&, const string&);
void applyFunction(bool (*)(const string&, const string&), vector<bool>&, initializer_list<string>);

int main(int argc, const char *argv[]) {


    // The type of a function includes the return type,
    // and the parameter types

    // for the lengthCompare function declared above, there are several 
    // different ways of obtaining a function pointer to that function
    // when declaring a pointer to a function, note that the function 
    // name is not part of its type

    // pointer to a function returning a bool, and takes two const strings 
    // as arguments
    // this is the most explicit way
    bool (*func_ptr1)(const string&, const string&); 
    
    // other similar declarations
    // when a function is used as a value, it is converted to a pointer to the 
    // function, so the type of func_ptr2 will be a pointer to lengthCompare
    auto func_ptr2 = lengthCompare;
    // explicitly using the address of operator
    // auto func_ptr2 = &lengthCompare;

    // can use func_ptr2 to call the function lengthCompare without dereferencing:
    bool output_1 = func_ptr2("first value", "second value");
    // or explicitly 
    bool output_2 = (*func_ptr2)("first value", "second value");

    // when used with decltype, lengthCompare is not converted to a 
    // pointer to the function, so the type returned by decltype is just
    // a function type, so need to have a type modifier to create a pointer 
    // to a function
    decltype(lengthCompare) *func_ptr3; 

    // using type aliasing
    using func_type = bool (*)(const string&, const string&); 
    
    // declaring a function pointer using a type alias
    func_type func_ptr4; 


    // -- function pointer parameters
    // as with arrays, cannot have array parameters as they 
    // are automatically resolved to pointers to the first element in the array
    // in the same way, function parameters are resolved to 
    // pointers to the function - again remember that the type 
    // of a function does not include the function name
    vector<bool> output_vec;
    initializer_list<string> string_args{"mwiza", "lubeya", "kunda"}; 

    applyFunction(lengthCompare, output_vec, {"mwiza", "lubeya", "kunda"}); 
    
    cout << "The output values are:\n" << endl; 

    for (auto str_ref : output_vec) {
        cout << str_ref << endl; 
    } 


    return 0;
}

bool lengthCompare(const string &str_1, const string &str_2) {

    return str_1.size() < str_2.size() ? true : false; 
}


void applyFunction(
    bool (*function_ptr)(const string &, const string &)
    ,vector<bool> &output_vec
    ,initializer_list<string> args
    ) {

        // apply the function to each pair of strings in initializer_list
        // simplest way is a range for
        for (auto str1 : args) {
            for (auto str2 : args) {
                output_vec.push_back(function_ptr(str1, str2));
            }
        }

    }
