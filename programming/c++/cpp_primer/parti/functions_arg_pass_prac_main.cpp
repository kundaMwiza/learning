// standard library
#include <iostream>
#include <string>

// custom functions
#include "functions_arg_pass_prac.h"

using std::cin; 
using std::cout; 
using std::endl; 
using std::string;

int main() {

    // test if string has a capital 
    string s1 = "mwiza jumps over the big lazy dog";
    string s2 = "Mwiza jumps over the big lazy dog";

    // test if s1 and s2 contain a capital letter
    cout << "The following string:\n" 
         << s1 
         << endl; 

    if (contains_capital(s1)) {
        cout << "contains a capital letter" << endl;    

    } else {
        cout << "does not contain a capital letter" << endl;
    }


    cout << "The following string:\n" 
        << s2
        << endl; 

    if (contains_capital(s2)) {
        cout << "contains a capital letter" << endl; 

    } else {
        cout << "does not contain a capital letter" << endl;
    }


    // convert s2 to lowercase
    (cout << "converting string:\n"
         << s2 
         << "\nto upper case:\n")
         << (str_to_upper(s2), s2)
         << endl; 


    return 0;
}

