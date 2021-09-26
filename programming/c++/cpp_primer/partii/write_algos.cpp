#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <random>
#include <iostream>

int main(int argc, const char *argv[])
{

    // -------------------------------------------------------
    // algorithms that write to containers
    // -------------------------------------------------------

    std::random_device rnd_seed;
    std::mt19937 m_eng(rnd_seed());
    std::uniform_int_distribution<int> dist(1, 50);

    std::vector<int> c_one(1000), c_two(1000);

    // algorithms
    // std::fill takes an input range to the contianer
    // and also has a value that will be used to fill the container range
    std::generate(
        c_one.begin(),
        c_one.end(),
        [&]()
        {
            return dist(m_eng);
        });

    std::generate(
        c_two.begin(),
        c_two.end(),
        [&]()
        {
            return dist(m_eng);
        });

    // fill c_one with all zeros
    std::fill(c_one.begin(), c_one.end(), int(0));

    std::cout << "fill vector with all zeros: " << c_one.back() << std::endl;

    // a similar algorithm to fill is fill_n which takes an iterator for the destination
    // a count and a value to fill
    // if the destination thats provided does not have as many elements as are required
    // to be in the container for the fill process, that is undefined behaviour

    // back inserters and front inserters - insert iterators
    // insert iterators use operations such as push_back and push_front
    // rather than assignment operators to add elements to the container
    // this allows for adjusting container capacity

    // insert interators take references to containers
    // and returns an inserter that is bound to that container
    auto it = std::back_inserter(c_one);

    // when assignment is performed with the back inserter
    // essentially, ther iterator calls push back on the container
    // in a sense, the assignment operator is defined to call push back on the
    // container
    *it = 34;

    // a redundant example since we can just use construction with n,t

    std::vector<int> trivial_vec;

    std::fill_n(std::back_inserter(trivial_vec), 10, 0);

    // more useful would be to append values to an existing container
    std::fill_n(std::back_inserter(c_one), 10, 15);

    // another writing algorithm 'copy'
    // takes three iterators, the first two denote the input range
    // the last iterator denotes an iterator for the destination contianer
    // the second container must be at least as large as the input range
    // otherwise there will be undefined behavior

    std::copy(c_one.begin() + 5, c_one.end(), c_two.begin());

    // for example can use copy to copy one built in array into another array

    int b_arr[] = {5, 10, 15};
    // ensure that the size of the second array is at least as large
    // as the first array
    int b_arr_two[sizeof(b_arr) / sizeof(*b_arr)];

    // copy values from the first array to the second
    std::copy(std::begin(b_arr), std::end(b_arr), std::begin(b_arr_two));

    // some algorithms that can write to the input sequence also provide
    // copying variants of the algorithms in order to not overwrite the
    // original sequence
    // for example the replace algorithm takes 2 iterators, and two values
    // the first is the input range, and the last two are the
    // value to match, and the value to replace with the matched value

    // replace values 5 with 10 inplace
    std::replace(c_one.begin(), c_one.end(), 5, 10);

    // an alternative version that does not perform inplace replacment
    // is a 'copy' versoin of the algorithm
    std::vector<int> result_vec;

    // use a back inserter to insert elements into a new container
    // rather than overwriting the previous one
    std::replace_copy(c_one.begin(), c_one.end(), std::back_inserter(result_vec), 10, 5);

    return 0;
}