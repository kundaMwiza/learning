#include <deque>
#include <iostream>
#include <vector>
#include <array>
#include <list>

int main(int argc, const char *argv[])
{

    // every container type defines a default constructor
    // apart from std::array
    // also, apart from array, other containers define
    // constructors that take arguments that specify the size
    // of the container

    // two ways to create a container as a copy of another one
    // directly copy the container (applicable for array)
    // or except array provide iterators
    // for the range that we would like to copy

    // to create a container as a copy of another, the container and element
    // types must match
    // if providing iterators, this is fine so long as the types
    // can be converted betwen the element types of the containers

    // -- copy initialisation of containers

    std::list<std::string> authors = {"Milton", "Shakespare", "Austen"};
    std::vector<const char *> articles = {"a", "an", "the"};

    // create another list by copying an existing one
    std::list<std::string> list2(authors);
    // alternative way
    std::list<std::string> list3 = authors;

    // std::deque<std::string> list4(authors); // error container types do not match

    std::list<std::string> list4(list2.begin(), list2.end()); // copy the entire range using iterators

    std::vector<std::string> list5(articles.begin(), articles.end()); // this is fine since can convert
    // const char * to std::string

    // in the case of using iterators to copy one container into another
    // the new container will have the same size as the range
    // specified by the iterators

    // the above methods were copy initialization methods

    // -- list initialization. as part of the new standard c++11, can list initialize a container

    std::list<std::string> authors_again = {"Milton", "Shakespeare", "Austen"};
    std::vector<const char *> articles_again = {"a", "an", "the"};

    //  --- construction with a size and optional initializer element
    // in the below cases, if no value is specified for initialisation, the class
    // type must provide a default constructor - this is important for custom classes
    std::vector<int> ivev(10, -1); // create a length 10 vector of elements with -1
    std::vector<float> fvev(10);   // create a length 10 vector of value initialised (0)

    // for arrays we need to also provide the dimension, which is part of the type
    // just as with standard C arrays
    std::array<int, 10> iarr{10, 20, 30}; // list initialised array, the rest are value initialised to zero
    // cannot use iterators or std::array<int, 10> arr(size, value) with arrays
    // since the dimesnion of the array is part of its type

    // unlike built in arrays i.e int arr[10] which disallwo copying other arrays
    // there is no such restriction for std::array<type, size>
    // so long as the container type, element type and dimension matches
    // for built in arrays:
    int barr[10] = {1, 2, 3};
    // int barr2[10] = barr; this is an error

    // using stl arrays
    std::array<int, 10> stlarr{10, 20, 30};
    std::array<int, 10> stlarr2 = stlarr; // this is valid since the element
    // types and dimensions match

    std::array<int, 10> starr3 = {10, 5, 11};

    //

    return 0;
}