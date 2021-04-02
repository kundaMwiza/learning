#include <vector>
#include <iostream>

#include "ex9.15_fun.hpp"

int main(int argc, const char *argv[])
{

    // two dummy vec ints
    std::vector<int> vec1{1, 2, 3};
    std::vector<int> vec2{2, 3, 4};
    std::vector<int> vec3{1, 2, 3};

    std::cout << "comparing vec1 and vec2 result:\n"
              << compare_vectors(vec1, vec2)
              << std::endl;

    std::cout << "comparing vec1 and vec3 result:\n"
              << compare_vectors(vec1, vec3)
              << std::endl;

    return 0;
}