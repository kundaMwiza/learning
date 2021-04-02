#include <iostream>
#include <string>

#include "io_functions.h"

std::istream &read_string_still_eof(std::istream &input_stream) {

    std::string temp; 

    while (input_stream >> temp) {
        std::cout << temp << std::endl;
    }

    if (input_stream.eof()) {
        std::cout << "reached eof";
    } else if (input_stream.fail()) {
        std::cout << "bad processing of input stream";
    } else {
        std::cout << "no problemo"; 
    }

    // clear the buffer
    std::cout << std::endl;


    // return a reference to an istream
    return input_stream;

}