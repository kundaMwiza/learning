#include <iostream>
#include <stdexcept>
#include "function_prac_header.h"

using std::cin;
using std::cout; 
using std::endl; 


/* function to ask the user whether they would like to calculate another factorial */
bool ask_user() {

    char try_again; 

    cout << "Enter another non negative integer y/n?"
         << endl; 

    cin >> try_again;

    if (try_again != '\n' && try_again == 'y') {

        cout << "Enter a non negative integer:"
             << endl;

        return true;
    } else {

        return false;

    }
}

/* 
description: 
    function to calculate the factorial of an interger
inputs:
    int val: the integer to calculate the factorial for
outputs: 
    long unsigned int: the computed factorial
*/  
long unsigned int fact(int val) {

    
    if (val < 0) {
        throw std::domain_error("Input must be non negative");   
    }

    int res = 1;

    while (val > 1) {
        res *= val--; 
    }

    return res; 
    
}