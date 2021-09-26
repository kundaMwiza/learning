#include <iostream>
#include "longest_substring.hpp"

int main(int argc, const char *argv[])
{

    LongestSubstring obj;

    std::cout << obj.find_longest(std::string("baby")) << std::endl;

    return EXIT_SUCCESS;
}