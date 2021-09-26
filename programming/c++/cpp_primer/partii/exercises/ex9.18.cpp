#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <fstream>

#include "read_input.hpp"

int main(int argc, const char *argv[])
{

    std::vector<std::string> string_container;
    std::deque<std::string> string_deque;
    std::vector<float> float_container;
    std::deque<float> float_deque;
    std::vector<int> int_container;
    std::deque<int> int_deque;

    // get the type of file to be processed
    std::fstream input_file(*(++argv));

    std::string input_type;
    std::getline(input_file, input_type);

    std::cout << "The file type is\n"
              << input_type
              << "\n"
              << std::endl;

    std::cout << "The output values are:"
              << std::endl;

    if (input_type == "string")
    {
        read_file(input_file, string_container);

        for (auto &elem : string_container)
        {
            std::cout << elem
                      << std::endl;
        }

        std::cout << "Place in deque:\n"
                  << std::endl;

        place_in_deque(string_container, string_deque);

        for (auto &elem : string_deque)
        {
            std::cout << elem << std::endl;
        }
    }
    else if (input_type == "int")
    {
        read_file(input_file, int_container);

        for (auto &elem : int_container)
        {
            std::cout << elem
                      << std::endl;
        }

        std::cout << "Place in deque:\n"
                  << std::endl;

        place_in_deque(int_container, int_deque);

        for (auto &elem : int_deque)
        {
            std::cout << elem << std::endl;
        }
    }
    else if (input_type == "float")
    {
        read_file(input_file, float_container);

        for (auto &elem : float_container)
        {
            std::cout << elem
                      << std::endl;
        }

        std::cout << "Place in deque:\n"
                  << std::endl;

        place_in_deque(float_container, float_deque);

        for (auto &elem : float_deque)
        {
            std::cout << elem << std::endl;
        }
    }

    return 0;
}