#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char *argv[])
{
    std::vector<char> vec_char({'a', 'b', 'c', 'd'});

    // construct using iterators

    std::string first_str(vec_char.begin(), vec_char.end());
    std::string second_str = "blah blah blah!!";

    // using substring - std::string::substr(pos, n)

    std::cout << "take string: " << second_str
              << "\nsubstring the first 3 chars: "
              << second_str.substr(0, 3)
              << std::endl;

    std::cout << "appending a string at the end of a string "
              << "note that string.push_back() only supports appending characters"
              << "the string is: "
              << first_str
              << std::endl;

    first_str.append("rad");

    std::cout << "appending elements results in: "
              << first_str
              << std::endl;

    return 0;
}