#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "read_input.hpp"

int main(int argc, const char *argv[])
{
    const char *file_str = *(++argv);

    std::string temp_throwaway;
    std::fstream input_file(file_str);

    std::getline(input_file, temp_throwaway);

    std::vector<int> int_vec;
    read_file(input_file, int_vec);

    // create a copy so we don't lose the original container
    std::vector<int> int_vec_copy(int_vec);

    if (!int_vec_copy.empty())
    {
        std::cout << "last element is:"
                  << int_vec_copy.back()
                  << std::endl;

        int_vec_copy.pop_back();

        std::cout << "the next element after removing the last one is:"
                  << int_vec_copy.back()
                  << std::endl;

        std::cout << "overloaded erase method"
                  << std::endl;
        int_vec_copy.erase(int_vec_copy.begin(), (int_vec_copy.end() - 2));

        for (auto &elem : int_vec_copy)
        {
            std::cout << elem << std::endl;
        }

        std::cout << "full elements are"
                  << std::endl;

        for (auto &elem : int_vec)
        {
            std::cout << elem << std::endl;
        }
    }

    return 0;
}