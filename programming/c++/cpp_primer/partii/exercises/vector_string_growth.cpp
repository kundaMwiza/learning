#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "read_input.hpp"

int main(int argc, const char *argv[])
{

    std::fstream int_file(*(++argv));
    std::string throwaway;

    std::getline(int_file, throwaway);
    std::vector<int> int_vec;

    read_file(int_file, int_vec);

    std::cout << "the integers that have been read are:"
              << std::endl;

    for (auto &elem : int_vec)
    {

        std::cout << elem << std::endl;
    }

    std::cout << "printout some information about the allocated int vector"
              << std::endl;

    std::cout << "the size of the vector is: "
              << int_vec.size()
              << "\nthe remaining number of elements that can be fit is: "
              << int_vec.capacity()
              << "\nafter reserving 1000 elements: ";

    int_vec.reserve(1000);

    std::cout << int_vec.capacity()
              << std::endl;

    // below code illustrates the difference between size and capacity
    // size is the number of elements in the container, whereas
    // capacity is the number of elements that the container can fit
    // before needing to reallocate more memory for the container.

    // int_vec.insert(int_vec.end(), {10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    std::vector<int> int_vec_temp({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    std::vector<int> int_vec_cpy(int_vec);

    // clear elements
    int_vec_cpy.clear();

    // add elements and check the capacity
    for (auto &elem : int_vec)
    {

        std::cout << "the size of the container: "
                  << int_vec_cpy.size()
                  << "the capacity of the container: "
                  << int_vec_cpy.capacity()
                  << std::endl;

        int_vec_cpy.push_back(elem);
    }

    for (auto &elem : int_vec_temp)
    {

        std::cout << "the size of the container: "
                  << int_vec_cpy.size()
                  << "the capacity of the container: "
                  << int_vec_cpy.capacity()
                  << std::endl;

        int_vec_cpy.push_back(elem);
    }

    return 0;
}