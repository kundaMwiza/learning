#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::endl; 
using std::cin; 
using std::cout; 

int main() {

    // iterators are a type that support the following core operations
    // 1 dereferencing
    // 2 ability to access class members using the arrow syntax 
    // e.g. iter -> mem = (*iter).mem
    // 3 ability to increment and decrement the iterator using ++ and --
    // 4 ability to test equality between iterators using != and == 

    // on top of these core operations, the vector container and string class
    // define further operations that their iterator types have
    // iter +n / -n : advance the iterator by n steps forwards / or backward
    // and return the iterator after advancement
    // iter += n/ -=n : same as above but compound assignment
    // iter1 - iter2 : subtracting iterators yields the number that when added
    // to the the right-hand iterator yields the left-hand iterator (defined only for 
    // when iter1 is at a position that is greater than the position of iter2)
    // both iterators must denote elements in, or noe past the end of/ the same container
    // >, >=, <, <= relational operators on iterators. One iterator is less than another
    // if it refers to an element that appears in the container before the one 
    // referred to by the other iterator. iterators using in the comparison must be valid
    // iterators

    // arithmetic operations on iterators
    vector<int> int_vec(10, 0);

    // get iterator positioned halfway in int_vec 
    auto int_halfway = int_vec.begin() + int_vec.size() / 2; 

    // can then use this iterator to advance from halfway towards the end

    // when use arithmetic operations on two iterators that refer to the same
    // container or string, the result of e.g. iter1 + iter2, or iter1 - iter2 
    // is the signed distance between the two iterators. the type returned by the 
    // arithmetic operation that is comparing two iterators is of type 'difference_type'
    // that is platform agnostic, in the same way that size_type is also platform agnostic
    // e.g. vector<int>::difference_type val = iter1 - iter2; 
    // note that this type is only defined for vector and string since they 
    // support arithmetic operations between iterators

    // simple binary search on a vector container which has iterators
    // that support arithmetic operations between them
    // suppose we just have integers from 0 to 10
    vector<int> binary_vec; 

    for (unsigned i = 0; i <= 10; ++i) {
        binary_vec.push_back(i); 
    }

    // now conduct binary search using iterators
    auto beg = binary_vec.cbegin(), end = binary_vec.cend();
    
    // get the middle iterator, note that (end - beg) / 2 is of type different_type
    // which can be added to an iterator to return a new iterator
    auto mid = beg + (end - beg) / 2; 

    // would like to search for the value 7
    int sought = 7; 

    while (mid != end && *mid != sought) {

        if (sought > *mid) {
            // set the new beginning iterator
            beg = mid + 1;
        }

        else {
            end = mid - 1; 
        }

        mid = beg + (end - beg) / 2; 

    }

    // if sought has been found, print the success value
    if (*mid == sought) {
        cout << "SUCCESS" << endl;
    } 

    else {
        cout << "FAILURE" << endl; 
    }




    
    return 0;
}