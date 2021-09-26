#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include "temp_file.hpp"

int main(int argc, const char *argv[])
{
    // excepting array, all of library containers provide
    // flexible memory management. Can add or remove elements dynamically
    // changing the size of the container at run time

    // below non valid for array
    // c.push_back(t), c.emplace_back(args)

    // push back creates a copy of element t, and places it on the end of the container
    // emplace_back(args) constructs an element from args, places that element at the end of the
    // container, there is no copying that takes place
    std::deque<double> vec1(10, 0);
    std::vector<int> vec2(10, 3);

    double db1 = 0;

    // using an rvalue reference
    vec1.push_back(5.6);

    print_vector_elements(vec1);

    // using a double object
    vec1.push_back(db1);

    print_vector_elements(vec1);

    // by construction using emplace
    vec1.emplace_back(7.8);

    // same with push_front, using emplace_front or push_front

    // placing elements anywhere in the container using emplace and insert
    // the below return references to the objects that have just been added
    // first element is an iterator where the element will be placed before
    vec1.emplace(vec1.cbegin(), 0.9);

    print_vector_elements(vec1);

    // overloaded insert function

    // using an il
    vec1.insert(vec1.cbegin(), {5.8, 9.9, 10.9});

    print_vector_elements(vec1);

    // using iterator ranges
    vec1.insert(vec1.cbegin(), vec2.begin(), vec2.end());

    print_vector_elements(vec1);

    // using val, t
    vec1.insert(vec1.cbegin(), 10, -2);

    print_vector_elements(vec1);

    // last version is just placing an individual element before an iterator
    vec1.insert(vec1.cbegin(), -5);

    print_vector_elements(vec1);

    // adding elements to a vector, string, or deque potentially invalidates
    // all existing iterators, references, and pointers itno the container

    return 0;
}
