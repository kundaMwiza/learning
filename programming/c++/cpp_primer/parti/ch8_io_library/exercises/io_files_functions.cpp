#include <fstream>
#include <iostream>
#include <string>


#include "io_files_functions.h"

std::fstream &read_and_output(std::fstream &file_input) {

    std::string temp = ""; 

    // if there is something wrong with the input file, return it 
    // and don't do any processing
    if (file_input.fail()) {
        std::cerr << "The supplied file cannot be processed" << std::endl;
        return file_input;
    }

    while (std::getline(file_input, temp)) {

        std::cout << temp << std::endl;
        
    }

    if (file_input.eof()) {
        std::cout << "--------------------------\n" 
                  << "reached eof in file."
                  << std::endl;
    } 

    return file_input;
}

