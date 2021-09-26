// builtin
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
// custom
#include "read_input.hpp"

// read integers from each line and place in a vector
void read_file(std::istream &input_file, std::vector<int> &ref_container)
{
    std::string temp_string;

    while (std::getline(input_file, temp_string))
    {
        ref_container.push_back(std::stoi(temp_string));
    }
}

// read strings from each line and place in a vector
void read_file(std::istream &input_file, std::vector<std::string> &ref_container)
{
    std::string temp_string;

    while (std::getline(input_file, temp_string))
    {
        ref_container.push_back(temp_string);
    }
}

// read floats from each line and place in a vector
void read_file(std::istream &input_file, std::vector<float> &ref_container)
{
    std::string temp_string;

    while (std::getline(input_file, temp_string))
    {
        ref_container.push_back(std::stof(temp_string));
    }
}