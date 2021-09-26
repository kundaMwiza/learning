#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "read_input.hpp"
// most of the generic algorithms are defined
// in the algorithm header. A set of generic numeric
// agorithms are also defined in the numeric header
#include <algorithm>
#include <numeric>

int main(int argc, const char *argv[])
{
    // typically the generic algorithms do not work on a container
    // instead, they operate by traversing a range of elements bounded
    // by two iterators
    // generally, as the algorithm traverses the range, something is done to each
    // element

    std::fstream int_file(*(++argv));

    std::string throwaway;
    std::getline(int_file, throwaway);

    std::vector<int> int_vec;

    read_file(int_file, int_vec);

    // find a particular value in a vector container
    const int val = 5;

    // what is the output of the find function?
    // it is an iterator pointing to the element if it exists
    // or __last if it does not exist
    // __last is the second iterator passed to the function
    // in our case below, that iterator is the end iterator
    auto result = std::find(int_vec.begin(), int_vec.end(), val);

    std::cout << "the value "
              << val
              << (result == int_vec.end() ? " is not present " : " is present ")
              << "in the vector of integers container"
              << std::endl;

    // also, since iterators act like pointers, we can also pass pointers
    // to the find functions for built in arrays, however just easier to
    // use the libraries std::begin and std::end functions
    // instead of using pointers

    int ia[] = {1, 2, 3, 4, 6, 8};
    int *ptr_result = std::find(std::begin(ia), std::end(ia), val);

    // some key points to make about the generic algorithms that are implemented
    // -- in terms of the operations that can be performed, they can all be handled
    // by iterator operations. the iterator dereference operator gives access to
    // an elements value, if a matching element is found, the generic algorithm
    // can return an iterator to the matching element, the iterator increment operator
    // can be used to advance the iterator until it reaches the iterator passed
    // as the second argument

    // -- However, algorithms do depend on element-type operations - that is
    // the element types of the containers
    // for example, if using find on an arbitrary operator, the element type (its class)
    // must implement the equal to == operator in order to determine if two elements of
    // the same type are the same.
    // custom classes that are therefore acting like containers should implement
    // such operators if they are to be useable with stl generic algorithms
    // othe than this, generic algorithms also provide a way to supply operators (e.g. functions)
    // that can be used if the particular operator is not defined for a custom type

    // KEY CONCEPT
    // the generic algorithms do not themselves execute container operations
    // they operate solely in terms of iterators and iterator operations.
    // the fact that they operate in terms of iterator operations has essential implications
    // algorithms never change the size of the underlying container. They may change
    // the values of elements in the container, or move elements within a container
    // however they do not ever add or remove elements directly.
    return 0;
}
