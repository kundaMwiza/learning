#include <iostream>
#include <vector>
#include <string>
#include <list>

int main(int argc, const char *argv[])
{
    // program to assign the elements from a list
    // of char* to a vector of strings

    // create a dummmy vector of strings
    std::vector<std::string> vec_strings;
    std::list<char const *> vec_c_strings = {"one", "two", "three"};

    // std::string and char * are compatible types
    // can user iterator ranges to copy char* from vec_c_strings
    // into vec_strings :

    vec_strings.assign(vec_c_strings.begin(), vec_c_strings.end());

    // output:
    // const iterator is similar to const reference (things its holding const objects)
    std::cout << "For loop using iterators:" << std::endl;
    for (auto it1 = vec_strings.cbegin(); it1 != vec_strings.cend(); ++it1)
    {
        std::cout << *it1 << std::endl;
    }

    std::cout << "For loop using range for" << std::endl;
    for (auto &elem : vec_strings)
    {
        std::cout << elem << std::endl;
    }

    return 0;
}