#include <iostream> 
#include <string>

#include "io_functions.h"

#define SUCCESS 0 
#define FAILURE 1

int main(int argc, const char *argv[]) {
    
    auto &out_istream = read_string_still_eof(std::cin);

    if (out_istream.fail()) {
        return FAILURE;
    } else {
        return SUCCESS;
    } 

}