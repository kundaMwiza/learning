#include <iostream>

// built in types initialized outside of a 
// function are initialized with the value zero bar a few special cases
// variables of built-in type defined inside a function are uninitialized
int some_int;

int main() {
    unsigned u = 10, u2 = 42;
    int i = 10, i2 = 42;

    std::cout << i - u << std::endl; 
    std::cout << u - i << std::endl; 

    // multiline string literal
    std::cout << "a really, really long string literal" 
                "that spans two lines" << std::endl;

    int month = 9;
    std::cout << month;
    // int month = 09; does not work since invalid octal representation
    // std::cout << month; 

    // escape sequences - non printable
    std::cout << "the following gives a new line \n" << std::endl;
    std::cout << "the following gives a horizontal tab \t" << std::endl;

    // escape sequences using hexadecimal - form is \x followed by
    // one or more hexadecimal digits
    std::cout << "the following character \x4d" << std::endl; 

    // escape sequence using octal - form is \ followed by one, two 
    // or three octal digits, if more than three, only the first three
    // are associated with the backslash
    std::cout << "the following character \111, but then consider \1114" << std::endl;

    signed char b  = -2; 
    signed char c = -3; 
    std::cout << "the following sum is: " <<  b + c << std::endl; 

    double x = 3.5;
    std::cout << "the size of x currently is" << sizeof(x) << std::endl; 
    x += 9.2f;
    std::cout<< " the size of x is now" << sizeof(x) << std::endl;
    
    // string type defined in std library 
    std::string str = "blah blah"; 

    std::cout << "the string is: " << str << std::endl; 

    std::cout << "the initial value of some_int is: " << some_int  << std::endl; 
    
    // reference a global variable some_int using the :: scope operator
    // when name before the operator is empty, it refers to the global scope 
    std::cout << ::some_int << std::endl; 
    return 0;
}
