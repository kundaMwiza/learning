#include <iostream>
#include <vector>

// adaptors are a general concept in the c++ library
// there are different kinds of adaptors - container
// iterator and function adaptors.
// adaptors are a mechanism for making one thing act like another

#include <stack>
#include <queue>
#include <string>
#include <fstream>
#include "read_input.hpp"

int main(int argc, const char *argv[])
{

    std::fstream int_file(*(++argv));
    std::string throwaway;

    // read file type from the header
    std::getline(int_file, throwaway);

    std::vector<int> int_vec;

    // read ints into int_vec from int_file
    read_file(int_file, int_vec);

    // print out the vector to see if we have read the file correctly
    std::cout << "printing out values read from int_file to int_vec" << std::endl;

    for (auto &elem : int_vec)
    {

        std::cout << elem << std::endl;
    }

    // creating a stack from a vector<int>, this constructs an empty vector
    std::stack<int, std::vector<int>> vec_stack;
    // by default the container that is adapted to by stack
    // is a deque, so here we create an empty deque to hold ints
    std::stack<int> deque_stack;

    // construct a stack by copying from a vector of ints
    // std::stack<int, std::vector<int>> vec_stack(int_vec);

    // relational operators for the adaptors return the result
    // of comparing the underlying sequential containers that the
    // adaptors are adapting

    // a.empty() returns false if the container has elements, and true otherwise
    // adaptors also have the swap member function.
    // the adaptors will swap the underlying containers that they are bound to
    // however, the underlying containers must have the same container type
    // and element type in the container.

    // adaptors require the ability to add and remove elements from the underlying
    // sequential container, so cannot use an array
    // for semantic reasons, they cannot also use forward lists since
    // they need access to adding, removing the last element

    // a stack requires only push_back, pop_back, and back operations
    // so can use vector, deque, list, string for a stack (to remove the last character)

    // stack operations
    // -- push element to the top of the stack -> push_back member -> push
    // -- remove element from the top of the stack -> pop_back member -> pop
    // -- access element from the top of the stack -> back member -> top

    // queue operations
    // -- push element to the back of the queue -> push_back -> push
    // -- pop element from the queue (one at the front) -> pop_front() -> pop
    // -- access element from the queue -> front() -> front

    std::queue<int, std::vector<int>> int_queue;

    // program using stack type

    std::stack<int> intStack; // empty stack

    // fill up the stack
    for (std::stack<int>::size_type ix = 0; ix != 0; ++ix)
    {
        intStack.push(ix);
    }

    while (!intStack.empty())
    {
        int value = intStack.top();
        // remove the element from the top of the stack
        intStack.pop();
    }
    return 0;
}

// class mwiza
// {
//     // by default a struct has all members public
//     // by default a class has all members private
//     // if all members are to be public, use a struct
//     // no difference in behaviour otherwise

//     // friends go here - friends have access to private data members

// public:
//     // static members have to be initialised outside of the class
//     // and also note that they do not inherit data members of the
//     // calling object
//     static const int blah;

//     // rah can be modified even within const member functions
//     mutable int rah;

//     // const member function
//     // note that this is a pointer to the object
//     // calling the function
//     // so to return the object itself, need to dereference the pointer

//     // void some_func(int a, int b) const {
//     //     *this
//     // }

//     // default constructor since our own constructor has been provided
//     mwiza() = std::default;

//     mwiza(int a, int b)
//         : some_val(a), another(b) {}

//     int some_val;
//     int another;

// private:
//     int some_other_int;
// }

// // static object initialised outside of the class
// mwiza::blah = 0;