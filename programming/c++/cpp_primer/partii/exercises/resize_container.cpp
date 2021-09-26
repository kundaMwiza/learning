#include <iostream>
#include <fstream>
#include <vector>

#include "read_input.hpp"

int main(int argc, const char *argv[])
{

    std::fstream int_file(*(++argv));

    std::vector<int> int_vec;

    std::string throwaway;

    std::getline(int_file, throwaway);

    read_file(int_file, int_vec);

    std::cout << "the read int file has the following values"
              << std::endl;

    for (auto &elem : int_vec)
    {

        std::cout << elem << std::endl;
    }

    std::cout << "resizing int_vec to hold 100 elements" << std::endl;

    int_vec.resize(100);

    std::cout << "now the values in the container are:" << std::endl;

    for (auto &elem : int_vec)
    {

        std::cout << elem << std::endl;
    }

    std::cout << "resizing int_vec to hold only 3 elements" << std::endl;

    int_vec.resize(3);

    std::cout << "now the values in the container are:" << std::endl;

    for (auto &elem : int_vec)
    {

        std::cout << elem << std::endl;
    }

        return 0;
}