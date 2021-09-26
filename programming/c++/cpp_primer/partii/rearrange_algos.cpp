#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <random>

int main(int argc, const char *argv[])
{

    // // generate random seed
    // std::random_device rnd;
    // // initialise random engine with seed
    // std::mt19937 m_engine(rnd());
    // // distribution of random numbers
    // std::uniform_int_distribution<int> dist(1, 10);

    // std::vector<int> test_vector(1000);

    // std::generate(
    //     test_vector.begin(),
    //     test_vector.end(),
    //     [&]()
    //     {
    //         return dist(m_engine());
    //     });

    std::vector<std::string> random_string =
        {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

    // sort the random string to place words in alphabetical order
    std::sort(
        random_string.begin(),
        random_string.end());

    std::cout << "print sorted string\n";

    for (auto &elem : random_string)
    {

        std::cout << elem;
    }

    std::cout << std::endl;

    std::cout << "remove duplicates\n";

    // algorithms cannot remove elements, so unique
    // returns an interator one past the last unique element
    // in the input sequence
    // in particualr, last_unique_iterator, container.end()
    // gives the non unique elements
    // unique returns one past the last unique element.
    // the elements beyond that point still exist but we don't know what
    // values they have
    // again, hte library algorithms operate on iterators, NOT
    // the containers, so the algorithm will never delete elements from the
    // container
    auto last_unique_iterator = std::unique(random_string.begin(), random_string.end());

    for (auto &elem : random_string)
    {
        std::cout << elem;
    }

    std::cout << std::endl;

    std::cout << "remove the duplicate elements using a container operation\n";

    random_string.erase(last_unique_iterator, random_string.end());

    for (auto &elem : random_string)
    {
        std::cout << elem;
    }
    return 0;
}
