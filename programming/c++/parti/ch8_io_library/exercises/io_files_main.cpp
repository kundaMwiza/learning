#include <fstream>
#include <iostream>
#include <string>

#include "io_files_functions.h"

int main(int argc, const char *argv[]) {
    
    // the first pointer in argv gives the file name

    // create an fstream object and bind it to the file ../sample.txt
    std::cout << "the number of supplied arguments is: \n"
            << argc 
            << "\n"
            << "the file name of the main function is: \n"
            << "\n"
            << std::endl;

    std::fstream file_input(argv[1]); 

    // read the file and output each line
    auto &throwaway = read_and_output(file_input);

    // close the connection to the file
    // can only have one object bound to a given file at a given time
    throwaway.close();
    
    return 0;
}