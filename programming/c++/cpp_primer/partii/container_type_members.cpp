#include <iostream>
#include <vector>
#include <fstream>
#include <list>

int main(int argc, const char *argv[]) {
    
    // each container defines several types
    // e.g. size_type, iterator and const_iterator
    // they also provide reverse iterators

    // they also provide types such as 
    // value_type, e.g. std::vector<T>::value_type 
    // value_type is just an alias for 
    // std::vector<T>::reference is also just an alias for T&
    // and std::vector<T>::const_reference is an alias for const T&
    // these additional types are more useful in generic programs 
    // e.g. template <typename T> return_type func(T) 
    // {std::vector<T> vec; std::vector<T>::value_type a // a is of type T}

    // examples - doubly linked list of strings 
    list<string>::iterator iter; 
    // get the difference type between iterators of type vector<int>::iterator
    std::vector<int>::difference_type count;
    
    // size_type objects should be used when indexing into 
    // containers. container_type::size_type are machine dependent types
    // that are guaranteed to fit the largest index available in a container
    // though the use of indexing is discouraged, and iterators or 
    // range fors should be used instead

    std::vector<int>::size_type idxr;

    // several versions of the begin and end iterators
    // versions with r return a reverse iterator 
    // those starting with c return a const iterator

    std::list<std::string> a{"Milton", "Shakespeare", "Austen" };

    auto it1 = a.begin(); // a.begin() returns a std::list<std::string>iterator
    auto it2 = a.end(); // returns a std::list<std::string>iterator
    auto it3 = a.rbegin(); // returns an interator that poitns to the last element 
    auto it4 = a.crbegin(); // returns a const_interator pointing ot the last element


    // the functions that do not begin with c are overloaded 
    // by const/ non const member function
    // if an object is const, the const member function will be used 
    // else the non const member function will be used
    // when begin or end are used on a container
    // the constness of the iterator depends on the constness of the object

    std::vector<int> v1; 
    const std::vector<int> v2;
    return 0;

}
