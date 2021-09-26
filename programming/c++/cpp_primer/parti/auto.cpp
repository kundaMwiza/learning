#include <iostream> 

int main() {
    
    int i = 0, &r = i;
    auto a = r; 

    const int ci = i, &cr = ci;
    auto b = ci; // b is an int (top level const in ci is dropped)
    auto c = cr; // c is an int (cr is an alias for ci whose const is top level)
    auto d = &i; // d is an int*(& of an int object is int*)
    auto e = &ci; // e is a const int * (& of a const object is low level const)    
    auto &g = ci; // g is a reference to const int

    std::cout << "value of a before is " << a << std::endl; 
    a = 42; 
    std::cout << "value of a after is " <<  a << std::endl;


    std::cout << "value of a before is " << b << std::endl; 
    b = 42; 
    std::cout << "value of a after is " <<  b << std::endl;


    std::cout << "value of a before is " << c << std::endl; 
    c = 42; 
    std::cout << "value of a after is " <<  c << std::endl;


    // std::cout << "value of a before is " << d << std::endl; 
    // d = 42; 
    // std::cout << "value of a after is " <<  d << std::endl;


    // std::cout << "value of a before is " << e << std::endl; 
    // e = 42; 
    // std::cout << "value of a after is " <<  e << std::endl;


    // std::cout << "value of a before is " << g << std::endl; 
    // g = 42; 
    // std::cout << "value of a after is " <<  a << std::endl;

    int some_int = 0;
    const auto &k = some_int; 

    
    return 0; 
}