#include <iostream>
#include <vector>
#include <array>

// high level overview
// assignment invalidates iterators, pointers and references
// bound to sequential containers. swap  invalidates them
// For strings only.
// For example if we have std::vector<int> &vec[8], using the assignment operator
// on the std::vector<int> may change the size of the vector
// and so, the reference to the 9th position in the vector is invalidated
int main(int argc, const char *argv[])
{
    // assignment related operators
    // there is a difference between assignment and initialisation
    // assignment occurs after an object has already been intiialised
    // assignment operators act on the entire container
    // and replaces all the elements in the left hand container
    // with copies of elements from the right hand operand

    std::vector<float> vec1(10, -1);
    std::vector<float> vec2(5, -2);

    // copy elements from v2 into vec1,
    // vec1 will now have only 5 elements
    // containers must be of the same type and have the
    // same base element
    // this is possible for arrays, but the size of the arrays
    // must be the same
    vec1 = vec2;

    // vec 1 will now only have 3 elements
    // NOT VALID FOR ARRAY
    // for array, must use the above assignment
    vec1 = {2.3, 3.3, 4.4};

    // more efficient that vec1 = vec2
    // exchange elements in c1 with those in c2
    // c1 and c2 must have the same type
    // may be faster since just changing the identifer
    // of the memory location
    vec1.swap(vec2);

    // same as above
    swap(vec1, vec2);

    // unlike array, swap does not copy elements from one
    // container to another, the underlying data structures
    // are just exchanged, which is an O(1) operation.
    // after the swap the pointers, iterators and references are still valid
    // and point to the original elements

    // for all sequential containers apart from string and array:
    // iterators, references and pointers are not invalidated
    // after using swap since

    // -- string
    // O(1) to swap underlying data structures, however,
    // pointers, references and iterators are invalidated

    // -- array
    // time to swap is proportional to the sizes of the two arrays
    // since the elements are copied
    // however, iterators, references and pointers remain bound to the same
    // elements

    // as with construction, can also provide iterators corresponding
    // to a sequential container of the same type and base element type
    // for assignment:

    // the assignment operator is overloaded

    // replace the values in vec1 with the values given by the range
    // indicated by the iterators
    vec1.assign(vec2.begin(), vec2.end());

    // replace the values in vec1 with those is vec2
    vec1.assign(vec2);

    // replace the values in vec1 with 10 values value initialised
    // to -1
    vec1.assign(10, -1);

    // WARNING - assignment operators with sequential containers
    // invalidate iterators, references, pointers to the containers
    // Apart from the string container, pointers, references and
    // iterators remain valid, and except for array, the containers
    // that the iterators, pointers and references refer to are swapped

    return 0;
}