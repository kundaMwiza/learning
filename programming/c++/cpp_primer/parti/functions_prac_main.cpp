#include <iostream>
#include <stdexcept>
#include "function_prac_header.h"

using std::cin;
using std::cout; 
using std::endl; 

int main() { 

    cout << "Factorial calculation application\n" 
         << "Enter a non negative integer:"
         << endl; 

    int inp;
    long unsigned int out; 
    bool try_again;  
    
    while (cin >> inp) {
        
        try {
            // collect input and calculate
            out = fact(inp); 
            cout << "The result is: "
                 << out 
                 << endl; 

            try_again = ask_user();

            if (!try_again) {
                break;
            }

        } catch (std::domain_error err) {
            
            // user has entered a negative value
            cout << err.what()
                 << endl; 
            
            try_again = ask_user(); 

            if (!try_again) {
                break;
            }
            
        }
        
    }

    return 0;
}

