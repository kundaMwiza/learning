#include <iostream>
#include <string>
#include <vector>
#include "read_input.hpp"
#include <fstream>

int main(int argc, const char *argv[])
{

    std::fstream int_file(*(++argv));

    std::string throwaway;

    std::getline(int_file, throwaway);

    std::vector<int> int_vec;

    read_file(int_file, int_vec);

    // get the first element in int_vec

    if (!int_vec.empty())
    {

        std::cout << "printing some values:\n"
                  << int_vec.front()
                  << int_vec.back() << std::endl;

        std::cout << "using at -> make sure that the value is less than container.size()"
                  << std::endl;

        std::vector<int>::size_type index = 3;

        if (index < int_vec.size())
        {
            std::cout << int_vec[index]
                      << int_vec.at(index)
                      << "at will raise out of bounds exception -> safer"
                      << std::endl;
        }
    }

    return 0;
}