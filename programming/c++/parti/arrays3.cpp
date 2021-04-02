#include <iostream>
#include <vector>
#include <string>

using std::vector; 
using std::string;
using std::cin;
using std::cout; 
using std::endl; 

int main() {

    string nums[] = {"one", "two", "three"};
    string *p = &nums[0]; // create pointer to the first element of nums

    // arrays have a special property - in most places when an array is used,
    // the compiler automatically substitutes a pointer to the first element

    string *p2 = nums; // equivalent to &nums[0]

    // implication of using an array as an initializer with base type auto
    // is that the deduced type of the expression is of the form base_type * 
    // that is, a pointer to an object of type base_type
    // note that this conversion does not occur when decltype is used
    // the type returned by decltype(nums) is an array of 3 strings 
    // for example

    // pointers that address elements in an array have additional operations
    // pointers to array elements support the same operations as iterators
    // on vectors or strings. Can use the increment operator to move from 
    // one element to the next

    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = a1; 

    // output the second element in the array
    cout << ++p << endl; 

    // to get an iterator that is off the end, can access an element one past the
    // end of the array    
    // get the memory of the last element in the array
    // can now use a comparison between the array pointer and the off the end iterator
    // e.g. p != off_the_end -> stop iterating if the memory locations do not match
    // note though that the only thing that can be done with off the end iterators
    // is to store the memory location. Cannot dereference them or increment them 
    // as that is undefined behaviour
    int *off_the_end = &a1[10]; 

    // using pointers as iterators for arrays
    for (int *p = a1; p != off_the_end; ++p) {
        cout << *p << endl; 
    }

    // library begin and end functions to return iterators  c++ 11 features
    // function like the begin and end functions for containers like vector 
    // or classes like string 
    // though unlike the begin and end functions defined in containers
    // the std::begin and std::end functions take an array as an argument
    // each of them returns a pointer to the first element of the array
    // and one off the end of the array respectively - functions are defined
    // in the iterator header

    int a2[] = {0, 1, 2, 3}; 
    int *beg = std::begin(a2);
    int *end = std::end(a2); 

    // pointers that address array elements can use all the iterator operations
    // that is dereference, increment, comparisons, addition of an integral value, and 
    // subtraction of two pointers, ex

    int a3[] = {0, 1, 2, 3, 4};
    int *ip = a3; 
    int *ip2 = ip + 2; // gives a pointer pointing to the third element of the array

    // subtracting two pointers referring to elements of the same array gives the distance
    // between the two pointers. 
    // the result of subtracting two pointers is a library type named ptrdiff_t
    // similar to types like string::difference_type

    // pointers and subscripts 
    // note that writing a3[2] actually obtains a pointer to the first element, then 
    // increments the pointer by 2, and returns a pointer to the third element
    // that is int * p = a3, a3[2] = p + 2
    /
    // unlike subscripts for vector and string, the index of the built-in subscript operator
    // is not an unsigned type and can be negative. So can write a3[-2] which corresponds to p - 2
    // but note that this is invalid as the resulting index is out of bounds..





    return 0;
}
