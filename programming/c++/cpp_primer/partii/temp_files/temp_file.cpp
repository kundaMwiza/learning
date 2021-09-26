#include <iostream>
#include <vector>
#include "temp_file.hpp"

int main(int argc, const char *argv[])
{

    // assignment and swap

    std::vector<int> vec1({1, 2, 3, 4, 5});
    std::vector<int> vec1_temp(10, -1);
    std::vector<double> vec2({3.0, 4.0});
    // initialisation is also an overloaded function
    // can use il, iterators or val, t
    std::vector<double> vec3(vec1.begin(), vec1.begin());

    // different ways to use the assignment operator with
    // sequential containers

    std::cout << "vec1 has size"
              << vec1.size()
              << std::endl;

    // now assign vec1 with vec1_temp
    vec1 = vec1_temp;
    print_vector_elements(vec1);

    // alternative using an il
    vec1 = {5, 6, 7};
    print_vector_elements(vec1);

    // now using overloaded assign function
    // using iterators
    vec1.assign(vec2.begin(), vec2.end());

    print_vector_elements(vec1);

    // using il
    vec1.assign({1, 2, 3, 4, 5, 6});

    print_vector_elements(vec1);

    // using val, t
    vec1.assign(10, -2);
    print_vector_elements(vec1);

    // using swap
    std::swap(vec1, vec1_temp);

    print_vector_elements(vec1);

    std::cout << "the value of the status code is"
              << status_code
              << std::endl;

    return 0;
}