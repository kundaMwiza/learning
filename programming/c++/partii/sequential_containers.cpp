#include <iostream>
#include <vector> 
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <string>

int main (int argc, const char *argv[]) {

    // declarations of stl sequential containers
    std::vector<int> vec{0, 1, 2};
    std::deque<float> deque{0, 1, 2};
    std::list<int> dllist{0, 1, 2};
    std::forward_list<float> sllist{0,1,2}; 
    std::array<int, 10> arr{0,1,2};
    std::string some_string = "blah blah blah";

    // indexing is supported by some containers, but 
    // is not recommended if change to other contianers 
    // may be desired that do not support indexing
    // access element six o
    some_string[5];
    
    // below is the same thing as the above
    *(some_string.begin() + 5);

    // for example, doubly linked lists do not define the 
    // indexing operator, and therefore the above expression
    // would be invalid for doubly or singly linked lists
    // dllist. // does not have []
    // std::list<int>:: // does not have []

    // the order of the elements in a SEQUENTIAL CONTAINER 
    // corresponds to the positions in which the elements are 
    // added to the container

    // ORDERED/ UNORDERED 
    // ASSOCIATIVE CONTAINERS - hold elements in a position that 
    // depends on a key associated with each element
    
    // the CONTAINER types employ generic programming, are provide 
    // a common interface

    // A container holds a collection of objects of a specified type
    // the order in a sequential container is based on the order 
    // of addition to the container, rather than the value of each 
    // element in the container

    // the library also provides container adaptors, which adapt a container 
    // type by defining a different interfact to the container's operations

    // overview of sequential container types -- tradeoff relative to 
    // cost to add or delete elements in the container
    // cost to perform nonsequential access to elements of the container 

    // -- vector flexible size array, fast random access 
    // deleting elements other than at the back can be slow 

    // -- deque double ended queue. fast random access 
    // deleting elements at the front and back is fast, can be slow in the middle

    // -- list doubly linked list. bidirectional sequential access
    // fast insert/ delete at any point in the list

    // -- forward list singly linked list. unidirectional access
    // fast insert/ delete at any point in the list

    // -- array fixed size array, fast random access 
    // cannot add or remove elements, but can change their value
    // safer and easier to use than built in arrays 
    // use std::array<int, 10> var rather than e.g. int var[10];

    // -- string not really a container, but similar to vector, e.g. std::vector<char>
    // fast random access, fast insert/ delete at the back, can be slow in the middle

    // apart from std::array which is a fixed size container, containers provide 
    // efficient flexible memory management, can add and remove elements, growing and 
    // shrinking the size of the container

    // STRING AND VECTOR hold elements in contiguous memory - which means 
    // can access any element in O(1) time by just computing the address
    // however when it comes to removing elements/ adding elements in the middle of the 
    // sequence type, it can be slow since elements to the left/right have 
    // to be moved to maintain contiguity

    // list and forward list are designed to have fast deletion/ insertion of any element 
    // in the list (O(1)), since linked lists are used and the container is not stored
    // in contiguous memory. However, in order to access any element, need to iterate 
    // over the list so O(n) lookup time. And since not contiguous, can have high overhead

    // a deque is similar to string and vector - supports constant time access of any 
    // element in the container type. And constant deletion/insertion at the front/back
    // of the container. however deletion in the middle can be slow
    // HOWEVER, in comparison to vector, it does not guarantee contiguity of 
    // element storage

    // ordinarily, it is best to use vector unless there is a good reason to prefer 
    // another container

    // BEST PRACTICES -- use an STL container, with iterators, avoid using subscripts
    // this way, the container used can be usually easily swapped if a different 
    // container is required
    // container operations - some operations are provided by all container types
    // -- type aliases 
    // e.g. iterator -> corresponding to the containers iterator e.g. std::array<int, 10>::iterator
    // machine dependent unsigned ints
    // size_t, difference_type e.t.c
    // value_type -> gives the element type of the container e.g. std::vector<int> gives int
    // reference -> elements lvalue type, same as value_type& e.g. for std::vector<int> gives int&
    // const_reference -> similar to the above, but gives const int & (reference to const object)
    // -- construction 
    // type of the elements used to initialize c must be of valid type or compatible..
    // C c; default construction
    // C c(a); construct c from a by copying
    // C c(b, e); copy elements from the range denoted by iterators b and e;
    // C c{a,b,c}; direct list initialization
    // constructors that take a size are valid for sequential containers 
    // e.g. C seq(size_t n) -> n value intiialized elements (explicit constructor)
    // e.g. C seq(n t) -> n value initialized elements with value t
    // -- assignment and swap
    // c1 = c2; // replace elements in c1 with those in c2 -> valid for array
    // c1 = {a, b, c, } // not valid for array, 
    // a.swap(b) // swap elements in a with those in b 
    // swap(a,b) // equivalent to a.swap(b)
    // -- size 
    // c.size() number of elements in c -> not valid for forward list 
    // c.max_size max no of elements c can hold
    // c.empty() bool false if c has any elements, true otherwise
    // -- add/remove elements (not valid for array)
    // c.insert(args) // copy elements from args into c
    // c.erase(args)
    // c.clear() remove all elements from c
    // -- equality and relational operators (not valid for unordered associative contianers 
    // == , >, < 
    // -- obtain iterators
    // c.begin(), c.rbegin(),..


    // the containers are implemented generically, so that they are class templates 
    // taking a user specified type
    // they are typically defined in headers with their own name e.g. #include <deque>
    // #include <list> std::array<int, 10>

    // almost any type can be used as the element type of the container (except references)
    return 0;
}