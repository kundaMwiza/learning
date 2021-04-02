#include <vector>
#include <string>
#include <iostream>

int main(int argc, const char *argv[])
{
    // define a dummy vector of ints
    std::vector<int> vec_ints(10, -1);

    // container types define three size-related operations
    // size -- number of elements in the container
    // empty -- bool that is true if size is zero and false o/w
    // max_size ---- geq to the number of elemenets a container
    // to that type can contain

    // std::forward_list does not define a size member function
    // (since there is no way of storing the number of elements)

    // some outputs:

    std::cout << "the number of elements in vec_ints:\n"
              << vec_ints.size()
              << "\nthe max size of vec_ints is:\n"
              << vec_ints.max_size()
              << "\nis vec_ints empty?:\n"
              << vec_ints.empty()
              << std::endl;

    // container types support relational operators
    // every container type (incuding associative containers) supports the binary equality operators (== and !=)
    // all containers except associative containers support relational operators"
    // >, >=, <, <=
    // RH and LH operands must be of the same container type
    // and have the same base element
    // cannot compare std::vector<int> with std::list<int>

    // comparing two containers performs a pairwise comparison of the elements
    // these work similarly to the string relational operators:
    // -- if the two containers are of the same size, and all elements are equal,
    // then the containers are equal
    // -- if they have different sizes, but every element of the smaller one
    // is equal to the corresponding element of the larger one, then the smaller
    // one is less than the other
    // -- if neither container is an initial subsequence of the other, then the result
    // of the comparison is based on the first unequal elements
    // e.g. two vectors of ints veca = {1, 2, 5, 6}, vecb = {2, 3, 5}
    // then vecb > veca is TRUE

    // examples
    std::vector<int> v1 = {1, 3, 5, 7, 9, 12};
    std::vector<int> v2 = {1, 3, 9};
    std::vector<int> v3 = {1, 3, 5, 7};
    std::vector<int> v4 = {1, 3, 5, 7, 9, 12};

    // v1 < v2 is true
    // v1 < v3 false
    // v1 == v4 true
    // v1 == v2 false

    // NOTE: Relational operators use their elements relational operator
    // in particular, if the operators are not defined for custom classes
    // then it is not possible ot use relational operators on such classes

    return 0;
}