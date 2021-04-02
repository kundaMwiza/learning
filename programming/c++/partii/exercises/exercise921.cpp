#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "exercise921.hpp"

/**
 * function to read input for an input stream and place 
 * values into a vector (in place addition) - can be extended to support other 
 * data types e.g. float, double e.t.c with templates. TODO: parallelize reading lines?
 * 
 * @param std::istream& input stream 
 * @param std::vector<int>& vector to store values  
*/
void read_ints(std::istream &istream, std::vector<int> &vec) {

    // read until eof
    while (!istream.eof()) {
        std::string buffer;
        
        // get a line from the input stream
        std::getline(istream, buffer);

        // now place each integer in the vector
        for (auto &val : buffer) {
            // delimeter is space
            if (val == ' ') {
                continue; 
            } else {
                // note that characters have integer 
                // values corresponding to their ascii representation
                // so '1' is actually 49, '0' is 48 e.t.c
                // we use std::atoi below to convert the chars
                // bue can also use '1' - '0' to get 49 - 48 = 1
                // this works for values between 0 to 9
                vec.push_back(std::atoi(&val)); 
            }
        }
    }

}
