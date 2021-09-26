#include <iostream>
#include <vector>
#include <fstream> 

#include "exercise921.hpp"

#define NDEBUG 1

int main(int argc, const char *argv[]) {

    std::ifstream open_file(argv[1]);

    // check if file opening was a success 
    if (open_file.fail()) {
        std::cout << "unable to open file:" << argv[1] << std::endl; 
        return 1;
    }

    std::vector<int> int_vec; 

    read_ints(open_file, int_vec);

    // see if we have read the value correctly 
    
    // debugging code 
    // check if we have read the inputs correctly
    #ifndef NDEBUG

    std::cout << "inputs read:" << std::endl;

    for (auto &elem : int_vec) {
        std::cout << elem << std::endl;
    }

    #endif

    // ask the user to enter a value
    std::cout << "Enter the integer value you would like to find "
            << "in the file you provided"
            << std::endl;

    // which value would you like to find user?
    int val_to_find = 0;

    // make sure istream is not corrupt
    if (std::cin >> val_to_find) {

        bool output = find_value(int_vec.begin(), int_vec.end(), val_to_find);

        if (output) {
            std::cout << "The value has been found" << std::endl; 
        } else {
            std::cout << "The value has not been found" << std::endl;
        }
    }


    return 0;
}