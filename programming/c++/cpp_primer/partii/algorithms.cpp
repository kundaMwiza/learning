#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

// how pointers work
// a pointer is just a memory address
// whose register value is another memory address
// the dereference operator takes the value at a memory address
// e.g. the address pointed to by a pointer
// goes to the memory address, and returns the value at that address
// the value returned may or may not be another memory address
// how this is interpreted is based on the element type as
// specified in the programs code

int main(int argc, const char *argv[])
{
    // this works because we have null terminated characters for
    // c style character strings e.g. '\0'
    // it is undefiend otherwise.. e.g. if
    // i create a c style character string without
    // a null termination character e.g. char some_arr[] = {'a', 'b'};
    // but doing char some_arr[] = "string"; will add a null termination character
    // however, it is advised not to use c style char strigns in c++
    std::size_t arr_size = std::stoi(argv[1]);
    std::size_t seed = std::stoi(argv[2]);

    std::random_device rnd_dev;
    // using a seed instead
    std::mt19937 mersene_engine(seed);
    // std::mt19937 mersene_engine(rnd_dev());
    std::uniform_int_distribution<int> unif_dist(1, arr_size);

    std::vector<int> example_vector(arr_size);

    std::generate(
        example_vector.begin(),
        example_vector.end(),
        [&]()
        { return unif_dist(mersene_engine); });

    // for (auto &elem : example_vector)
    // {

    //     std::cout << elem << std::endl;
    // }

    unsigned int find_val = 5;

    // find returns an iterator to the first element that matches the value required
    // if there is no match, find returns the end iterator
    // the algorithms defined by the c++ language are generic
    // and typically just take in iterators that represent a range
    // in the stl container
    // however, in order to perform operations on the cntainer
    // the specific operations to be performed have to be supported
    // by the container elements. For example find relies on the
    // == logical operator being defined for the element type of find_val below
    // if it is not defined, then the algorithm would not be able to work
    // in particular, the element type provided to find determines what operations
    // can be performed by the algorithm, as well as any return types
    auto result = std::find(example_vector.begin(), example_vector.end(), find_val);

    if (result != example_vector.end())
    {
        std::cout << "the value: " << find_val << " was found!" << std::endl;
    }

    unsigned n_counts = std::count(example_vector.begin(), example_vector.end(), find_val);

    std::cout << "found value: "
              << find_val
              << " this number of times: "
              << n_counts
              << std::endl;

    // key concept
    // the generic algorithms do not themselves execute container operations.
    // they operate solely in terms of iterators and iterator operations.
    // algorithms never change the size of the underlying container
    // however there is a special class of iterators (back inserters and front inserters)
    // that execute insert operations on the underlying contianer
    // the iterator itself may have the effect of adding elements to the container
    // the algorithm itself, however, never does so

    return 0;
}