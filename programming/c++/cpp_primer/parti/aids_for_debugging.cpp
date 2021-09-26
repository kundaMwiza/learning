#include<iostream>
#include<vector>
#include<string>

using namespace std;

void debugging_ex_func(const vector<int>&);

int main(int argc, const char *argv[]) {

    // in c++, a technique similar to header guards
    // can be used to conditionally execute debugging code
    // PREPROCESSOR variable NDEBUG can be used to conditionally 
    // run code at run time 
    // if the variable NDEBUG is defined, debugging "mode" is turned off
    // otherwise, code is debugged.
    // to use NDEBUG, use #ifndef and #endif 
    // The preprocessor defines four names that are useful in debugging:
    // _ _FILE_ _ which gives the name of the file in which the code is exeucting
    // _ _LINE_ _ for the line number
    // _ _TIME_ _ the time at which the code was compiled 
    // _ _DATE_ _ the date when the code was compiled 
    // the compiler also defines the name _ _func_ _ which gives 
    // the name of the function that is executing
    // see below for an example
    
    debugging_ex_func(arr);

    return 0; 
}


void debugging_ex_func(const vector<int> &some_arr) {

    // below code will only execute if NDEBUG is not defined
    #ifndef NDEBUG
    if (some_arr.size() < 1) {
        cerr << "Debugging file name: "
            << __FILE__
            << "\nfunction executing is: " 
            << __func__ 
            << "\nLine number is: "
            << __LINE__ 
            << "\ninput vector<int> array has size: "
            << some_arr.size() 
            << "\nbut should be greater than 1"
            << endl;      
    }
    #endif 

}