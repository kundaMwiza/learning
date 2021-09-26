#include <iostream>
#include <vector>
#include <fstream> 

int main(int argc, const char *argv[]) {

    // as with containers, iterators have a common interface
    // if an iterator provides an operation, then the operation 
    // is supported in the same way for each iterator 
    // that supplies that operation
    
    // e.g. all stl container types allow access to an element 
    // from a container via the dereference operator
    // similar to the increment operator to advance the iterator
    // to the next element
    
    // iterator arithmetic operations apply only to string, vector
    // deque and array, cannot use them for lists or associative 
    // containers 

    // iterator range -> denoted by a pair of iterators each of which refers
    // to an element, or to one past the last element, in the same container
    // these two iterators are usually referred to as 'begin' and 'end' resp.
    // the range is [a, b+1) where a is the first index, b is the last element index
    // left inclusive interval

    std::vector<int> vec_one{1,2,3,4}; 

    // different ways to iterate over an stl container 
    // in decreasing order of reccommendation 

    // range for 
    for (auto &element: vec_one) {
        std::cout << element << std::endl; 
    }

    // using iterators
    // dereference operator returns a reference type (which is an lvalue)
    // any function that returns a reference type is an lvalue 
    for (auto b = vec_one.cbegin(); b != vec_one.cend(); ++b) {
        std::cout << *b << std::endl; 
    }

    // indexing: NOT SUPPORTED for list and forward list
    for (std::vector<int>::size_type i = 0; i != vec_one.size(); ++i) {
        std::cout << vec_one[i] << std::endl; 
    }


    return 0;
} 