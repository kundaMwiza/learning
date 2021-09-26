#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <string>

#include "read_input.hpp"

int main(int argc, const char *argv[])
{

    std::fstream int_file(*(++argv));
    std::fstream str_file(*(++argv));

    std::string throwaway;
    std::getline(int_file, throwaway);
    std::getline(str_file, throwaway);

    // now read integers and strings into respective containers
    std::vector<int> int_vec;
    std::vector<std::string> str_vec;

    read_file(int_file, int_vec);
    read_file(str_file, str_vec);

    // ex10.1
    // count how often the value 6 occurs in the containers
    int val = 6;
    auto int_result = std::count(int_vec.begin(), int_vec.end(), val);

    std::cout << "the value val = "
              << val
              << " appears: "
              << int_result
              << " times in the vector of integers"
              << std::endl;

    // doubly linked list to hold a sequence of strings
    std::list<std::string> str_list;

    // read values from a vector of strings
    // to a doubly linked list of strings
    for (auto &elem : str_vec)
    {
        str_list.push_back(elem);
    }

    // ex10.2 count how many times the string "the"
    // occurs in the doubly linked list of strings
    // construct using a char arr[]
    std::string str_val("the");

    auto str_result = std::count(str_vec.begin(), str_vec.end(), str_val);

    std::cout << "the value val = "
              << str_val
              << " appears: "
              << str_result
              << " times in the vector of integers"
              << std::endl;

    return 0;
}