#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <random>
#include <sstream>
#include <fstream>

int main(int argc, const char *argv[])
{
    // a predicate is an expression that can be called and returns a value
    // that can be used as a condition
    // predicates are expressions that have the callable operator implemented
    // the expression just has to return anything that is testable to true or false
    // e.g. a unary predicate can be a function or a lambda expression returning
    // an integer which can be converted to true or false
    // a binary one can take two arguments and return a testable expression
    // more explicit predicates return bool objects

    std::string sent = "the quick brown fox jumps over the lazy dog";
    std::istringstream inp_string(sent);
    std::vector<std::string> vec_strings = {"the", "quick"};

    std::string temp;

    while (inp_string >> temp)
    {
        vec_strings.push_back(temp);
    }

    auto one_past_it = std::partition(
        vec_strings.begin(),
        vec_strings.end(),
        [](const std::string &inp_string)
        {
            return inp_string.size() <= 3;
        });

    std::cout << "those matching condition\n";

    for (auto it = vec_strings.begin(); it != one_past_it; ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "those not matching conditoin\n";

    for (auto it = one_past_it; it != vec_strings.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}