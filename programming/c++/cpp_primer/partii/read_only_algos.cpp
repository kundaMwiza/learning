#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <string>

int main(int argc, const char *argv[])
{
    // ---------------------------------------
    // READ ONLY algorithms
    // ---------------------------------------

    // a number of the algorithms provided in the standard library
    // read, but never write to the elements in their input range
    // functions such as 'find' and 'count' are such algorithms
    // another one is 'accumulate' which accumulates the values in the container
    // how this is done again depends on the container and the element type

    std::random_device rnd_dev;
    std::mt19937 m_engine(rnd_dev());
    std::uniform_int_distribution<int> dist(1, 10);

    std::vector<int> test_vector(1000);

    // fill vector with random values
    std::generate(
        test_vector.begin(),
        test_vector.end(),
        [&]()
        { return dist(m_engine); });

    // the type of the third argument determines the operations that
    // can be performed. In particular, since
    auto result = std::accumulate(test_vector.begin(), test_vector.end(), int(0));

    std::cout << "the result is: " << result << std::endl;

    // since the string class defines the addition operator
    // it is possible to use the accumulate class to concatenate strings
    // the third element, being a string dictates that we can do this
    std::vector<std::string> str_vec({"first", "second"});

    // note that passing an empty string "" as the third argumetn would result
    // in error since an empty string resolves to a c-style character string
    // which is a pointer to a const char, and pointers cannot be added to strings
    // for algorithms that do not write, but read, it is best to use constant iterators
    std::string str_concat = std::accumulate(str_vec.cbegin(), str_vec.cend(), std::string(""));

    std::cout << "concatenating the strings: " << str_concat << std::endl;

    // Anotehr read only algorithm
    // equal which lets us determine whether two sequences hold the same values
    // it returns a logical
    // the algorithm takes three iterators, the first adn second correspond to the begin
    // and end iterators of the container, and the last element is the end iterator of the second
    // container
    // in particular, the equal algorithm assumes that the second container is atleast as large
    // as the first container

    std::vector<int> c_one(1000), c_two(1000);

    std::generate(
        c_one.begin(),
        c_one.end(),
        [&]()
        { return dist(m_engine); });

    std::generate(
        c_two.begin(),
        c_two.end(),
        [&]()
        { return dist(m_engine); });

    // because == operates in terms of iterators
    // can compare elements of different types, so long as they are compatible
    // for example std::vector<std::string> and std::vector<const char *>
    bool are_equal = std::equal(c_one.begin(), c_one.end(), c_two.end());

    std::cout << "containers equal: " << are_equal << std::endl;

    // algorithms that take a single iterator denoting a second sequence
    // assume that the second sequence is at least as large as the first.

    std::fill(c_one.begin(), c_one.end(), int(-5));

    std::cout << "the value of the first element is " << c_one.back() << std::endl;

    // algorithms do not check write operations, they can't, since they just use
    // iterators
    return 0;
}