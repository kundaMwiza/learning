#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <numeric>
#include <functional>
bool less_than(const int &val, const int &compare)
{
    return val < compare;
}

int main(int argc, const char *argv[])
{

    std::random_device rnd_dev;
    std::mt19937 m_eng(rnd_dev());
    std::uniform_int_distribution<int> dist(1, 10);

    std::vector<int> test_vec(1000);

    std::generate(
        test_vec.begin(),
        test_vec.end(),
        [&]()
        {
            return dist(m_eng);
        });

    // lambda functions are most useful for simple operations
    // that do not need to be used in more than 2 places
    // if we need to use the same operation several times
    // then can just create a function
    // lambda functions are convenient because the capture list
    // allows other argumetns to be used in the function without
    // requiring additional parameter names in the lambda expression

    // new library function called 'bind', defined in the functional header
    // the function can be thought of as a general purpose adaptor for function
    // objects. It takesa a callable object and returns a new callable object
    // that adapts the parameter list of the original callable object
    // for example the less_than function declared above
    // the bind function is defined in the functional header
    // placeholders are _n to correspond to the nth parameter
    // so for example below, we use a placeholder to define a callable that
    // will receive a value for the first parameter, but provide the
    // second parameter an argument. in particular, the new callable is a unary predicate
    auto less_than_adapt = std::bind(less_than, std::placeholders::_1, 5);

    auto found_iterator = std::find_if(
        test_vec.begin(),
        test_vec.end(),
        less_than_adapt);

    for (auto it = found_iterator; it != test_vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}