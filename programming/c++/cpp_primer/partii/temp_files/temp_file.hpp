#ifndef TEMP_FILE
#define TEMP_FILE 1

#include <vector>
#include <iostream>

extern int status_code;

template <typename T>
void print_vector_elements(const T &seq_container)
{

    std::cout << "The contents of the input container are:\n"
              << std::endl;

    for (auto &elem : seq_container)
    {
        std::cout << elem
                  << std::endl;
    }
    std::cout << "Finished outputting elements of the container\n"
              << std::endl;
}

#endif