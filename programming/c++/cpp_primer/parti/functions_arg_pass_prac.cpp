// standard
#include <iostream>
#include <string>
#include <vector>

// custom
#include "functions_arg_pass_prac.h"

// alias
using std::cin;
using std::cout; 
using std::endl; 
using std::string; 


bool contains_capital(const string &inp_str) {  

    for (auto &letter : inp_str) {

        unsigned char letter_upper = std::toupper(letter);

        if ((letter != ' ') && (letter_upper == letter)) {
            return true;
        }
    }

    return false;
}

void str_to_upper(string &inp_str) {

    for (auto &letter : inp_str) {
        letter = std::toupper(letter);
    }
}