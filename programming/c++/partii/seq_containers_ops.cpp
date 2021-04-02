#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(int argc, const char *argv[])
{
    // sequential containers differ in how they organize
    // their elements based on: how stored, accessed, addition
    // removal of elements
    // previous scripts looked at operations for all containers
    // now looking at sequential container specific operations

    // -- addition of elements to sequential containers
    // except array (fixed size), all sequential containers support
    // addition of elements to the container using flexible memory
    // management

    // operations to add elements
    // assume c a container
    // c.push_back(t), c.emplace_back(args) adds element t or args to the end of c, returns void
    // c.push_front(t), c.emplace_front(args), like push_back, but to the front
    // the above assume a position in the container, which is why they don't require
    // a index, for example the below

    // to use the below member functions, need to specify an index into the container
    // of where to add the elements
    // c.insert(p, t), c.emplace(p, args), creates an element with value t or
    // constructed from args _before_ the element denoted by iterator p. returns
    // an iterator referring ot the element just added

    // insert is an overloaded function:
    // c.insert(p, b, e) p an iterator indicating where to add elements before
    // b, e iterator range
    // c.insert(p, n, t) insert n values with value t
    // c.insert(p, il) il braced list ~ std::initializer_list

    // Cannot use push_front or emplace_front for vector and string
    // Cannot use push_back or emplace_back for forward_list

    // examples --
    std::vector<double> vec_doubles{0, 1.2, 3.3};
    std::deque<double> deque_doubles{0, 1.2, 3.4};

    // returns void
    vec_doubles.push_back(0.5);
    // emplace_back is a variadic function (not using an initializer list)
    vec_doubles.emplace_back(0.4, 0.7);

    // cannot use push_front or emplace_front for vectors and strings
    deque_doubles.push_front(0.7);
    // variadic function
    deque_doubles.emplace_front(0.4, 0.6);

    // now more general ways of adding elements to sequential containers..
    // all of the below methods return an iterator pointing to the first element
    // inserted

    // the first parameter specifies an iterator, and values will be added
    // before this iterator value
    vec_doubles.insert(vec_doubles.end(), 9);
    // again emplace is a variadic function
    vec_doubles.emplace(vec_doubles.end(), 9.4, 3.3);

    // now overloaded insert member method
    // using iterator ranges - use deque_doubles, holds a compatible type (double)
    vec_doubles.insert(vec_doubles.end(), deque_doubles.begin(), deque_doubles.end());
    // using an initializer list
    vec_doubles.insert(vec_doubles.end(), {1.2, 3.3});
    // insert(p, n, t)
    vec_doubles.insert(vec_doubles.end(), 10, -1);

    // adding elements or removing elements from containers could potentially invalidate
    // existing iterators, references, and pointers into the container

    // adding elements anywhere but the end of a vector or string
    // or anywhere but the beginning or end of a deque,
    // will need elements to be moved, memory allocated
    // which can be slow for large instances of containers

    // even though can use insert and emplace to insert element arbitrarily
    // at any position, it should be avoided since the operation can be expensive

    // NOTE: when an object is used to initialize a container,
    // or an object is inserted into a container, a copy of that
    // object's value is placed in the container, not the object itself
    // same as when an object is passed to a non reference parameter
    // therefore subsequent changes to the values in the container
    // have no effect on the initializer

    // the emplace functions construct objects in the container, rather than copying from a
    // the objects passed as input as with push_back, push_front and insert
    // e.g. c.emplace(constructor args) vs c.push_back(obj_to_be_copied)
    return 0;
}