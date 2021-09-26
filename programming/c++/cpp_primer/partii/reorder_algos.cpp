#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <random>

int main(int argc, const char *argv[])
{

    std::random_device rnd_dev;
    std::mt19937 m_eng(rnd_dev());
    std::uniform_int_distribution<int> dist(1, 10);

    std::vector<int> test_vector(1000);

    std::generate(
        test_vector.begin(),
        test_vector.end(),
        [&]()
        {
            return dist(m_eng);
        });

    // again, in order to reorder the elements in a container
    // the operator must be valid
    return 0;
}