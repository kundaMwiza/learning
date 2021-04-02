#include <iostream>

int main() {

    // the preprocessor -> which cpp inherits from C is a program
    // that runs before the compiler and changes the source text of our programs
    // Our programs already rely on one preprocessor facility, #include. When the 
    // preprocessor sees a #include, it replaces the #include with the contents of
    // the specified header. 

    // C++ programs also use the preprocessor to define header guards. Header guards
    // rely on preprocessor variables. preprocessor variables have one of two 
    // possible states: defined or not defined. the #define directive takes a name
    // and defines that name as a preprocessor variable
    return 0; 
}