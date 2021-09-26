#include <iostream>
#include <fstream>
#include <forward_list>
#include <vector>

#include "read_input.hpp"

void insert_string(std::forward_list<std::string> &str_list, const std::string &string1, const std::string &string2)
{

    auto prev = str_list.before_begin();
    auto curr = str_list.begin();
    bool found = false;

    while (curr != str_list.end())
    {
        if (*curr == string1)
        {
            prev = curr;
            curr = str_list.insert_after(prev, string2);
            found = true;
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    if (!found)
    {
        str_list.insert_after(prev, string2);
    }
}

int main(int argc, const char *argv[])
{

    const char *int_name = *(++argv);
    const char *str_name = *(++argv);

    std::fstream int_file(int_name);
    std::fstream str_file(str_name);

    std::string throwaway;
    std::getline(int_file, throwaway);
    std::getline(str_file, throwaway);

    std::vector<int> int_vec;
    std::vector<std::string> str_vec;

    read_file(int_file, int_vec);
    read_file(str_file, str_vec);

    std::forward_list<int> flist;
    std::forward_list<std::string> flist_str;

    auto flist_iter = flist.before_begin();
    auto flist_str_iter = flist_str.before_begin();

    // string - load strings into forward list
    for (auto &elem : str_vec)
    {
        flist_str.insert_after(flist_str_iter, elem);
        ++flist_str_iter;
    }

    std::cout << "after loading strings into forward list, the list is:"
              << std::endl;

    for (auto &elem : flist_str)
    {
        std::cout << elem << std::endl;
    }

    // int - load ints into forward list
    for (auto &elem : int_vec)
    {
        flist.insert_after(flist_iter, elem);
        ++flist_iter;
    }

    std::cout << "after loading ints into forward list, the list is:"
              << std::endl;

    for (auto &elem : flist)
    {
        std::cout << elem << std::endl;
    }

    // remove even elements from our forward list
    std::forward_list<int> flist_cpy(flist);

    auto prev = flist_cpy.before_begin();
    auto curr = flist_cpy.begin();

    std::cout << "removing odd elements from the int list"
              << std::endl;

    while (curr != flist_cpy.end())
    {
        if (*curr % 2)
        {
            curr = flist_cpy.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    std::cout << "output is:" << std::endl;

    for (auto &elem : flist_cpy)
    {
        std::cout << elem << std::endl;
    }

    std::cout << "string function, using first string as quick, insert element as rah"
              << "\nexpect the string to be found and therefore rah to be inserted after"
              << "\nBelow is the output of the modified forward list:"
              << std::endl;

    insert_string(flist_str, "quick", "rah");

    for (auto &elem : flist_str)
    {

        std::cout << elem << std::endl;
    }

    std::cout << "now pass two strings where the first string is not found in the forward list"
              << std::endl;

    insert_string(flist_str, "jah", "rah");

    for (auto &elem : flist_str)
    {

        std::cout << elem << std::endl;
    }

    return 0;
}