#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#include "read_input.hpp"

// -- RECAP from sequential containers chapter
// construction (6 different ways)
// assignment - via equals (2 ways), swap, overloaded assign (3 ways)
// insertion - push_back/front, emplace_back/front, emplace/ overloaded insert
// note that insertion via emplace(iter) and insert(iter) insert BEFORE iter.
// the operations that take an iterator as an argument also return iterators
// to the first element that was inserted
// accessing - back/front, indexing [], and lastly using at() which can return
// an exception
// deletion - pop_back/front, erase(iterator), erase(iterator range)
// these erase the elements at the iterator/ range, and return an iterator
// to one past the erased element(s)
// HOW a vector grows - size and capacity - reallocation
// forward_list specific operations -> erase_after, insert_after, before_begin_iterator
// string specific operations -> compare, substr, find, append, erase etc as well as unique ways of construction

template <typename T>
void print_output(const T &seq_container)
{

    for (auto &elem : seq_container)
    {

        std::cout << elem << std::endl;
    }
}

int main(int argc, const char *argv[])
{

    // the c++ standard library provides more than 100 algorithms
    // however, the algorithms have a consistent architecture
    // in particular, the algorithms use unifying principles so
    // that using them is easier for the end user

    // with only a few exceptions, the algorithms operate over a
    // a range of elements using iterators - this range is can be denoted
    // as the input range. the iterator range is a left inclusive interval
    // where the first element is included in the range, and the second
    // iterator denotes one passed the last element to be processed

    // generally algorithms can be classified by whether they are read only
    // can write and read, and whether they rearrange the order of elements

    // -- read only algorithms
    // examples - find(), count(), accumulate() (defined in the numeric header)
    // accumulate takes an input range, and the third argument is the starting value
    // for accumulation, assuming the iterators point to containers with integral values
    // the accumulate function will accumulate/ sum the values given by the input range
    // the type of the third argument to accumulate determines which addition operator
    // is used, and therefore affects the type of output returned
    // also, the fact that the third argument is used for the start of accumulation
    // means that the underlying type pointed to by the iterators must be capable
    // of addition. in particular, since std::string defines the addition operator
    // can concatenate a series of strings stored in a vector

    std::fstream int_file(*(++argv));
    std::string throwaway;
    std::getline(int_file, throwaway);

    std::vector<int> int_vec;
    read_file(int_file, int_vec);

    // sum all the values in int_vec - can easily use a range for
    // but can just use the generic algorithm defined by the standard library
    int sum = 0;
    int result = std::accumulate(int_vec.begin(), int_vec.end(), sum);

    std::cout << "the result of accumulating all the values in integer vector "
              << result
              << std::endl;

    // -- concatenate a series of string from a vector
    std::vector<std::string> str_vec({"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"
                                                                                                      "."});
    // note that cannot use a literal as the start value here since that is a
    // char *, rather than a string
    // again, the argument provided as the third value determines the type of
    // operations that can be performed
    std::string accum_start = "";
    std::string str_result = std::accumulate(str_vec.begin(), str_vec.end(), accum_start);

    std::cout << "The result of concatenating the vector of strings is: "
              << str_result
              << std::endl;

    // algorithms operating on two sequences - equal() determines if two
    // sequences hold the same values. WARNING - The second sequence should hold
    // at least as many elements as the first, or reading out of bounds
    // occurs
    std::vector<int> first_seq({5, 10, 15, 20});
    std::vector<int> second_seq({6, 10, 15, 25});

    bool compare_result = std::equal(first_seq.begin(), first_seq.end(), second_seq.begin());

    std::cout << "The result of comparing the two sequences is "
              << compare_result
              << std::endl;

    // algorithms that write container elements
    // some algorithms assign new values to the elements in a sequence
    // for these algorithms, must take care to ensure that
    // the sequence into which the algorithm writes is at least as large
    // as the number of elements asked to be written
    // -- some algorithms write to elements in the input range itself - not so dangerous
    // e.g. std::fill(b, e, val) will fill range [b, e) with val

    std::vector<int> fill_ex(first_seq);

    std::fill(fill_ex.begin(), fill_ex.end(), 1);

    print_output(fill_ex);

    // some algorithms assume that the writing space is atleast as large
    // as the number of elements that are requested to be written
    // for example std::fill_n(iter, count, value)
    // if count is larger than the container size, then will be writing
    // out of bounds
    // algorithms do not check write operations!
    // in particular, for dynamically allocated containers such as vector
    // writing with an iterator does not modify the size of the container
    // since the algorithms would dereference an iterator, rather than using
    // operations directly on the container such as push_back,which would
    // resize the container if the capacity has been reached

    // replace all values with -99
    std::fill_n(fill_ex.begin(), fill_ex.size(), -99);

    print_output(fill_ex);

    // one way to ensure that an algorithm has enough elements to hold
    // the output is to use an insert iterator
    // an insert iterator is an iterator that adds elements to a container
    // e.g. analogue with push_back
    // bask_inserter defined in the iterator header -> takes a reference
    // to a container and returns an insert iterator bound to that container
    // when assign through the iterator, the assignment operator calls push_back
    // to add an element to the container

    // returns an insert iterator
    auto ex_back_insert = std::back_inserter(fill_ex);

    // assignment calls push_back to add an element to the container
    // disadvantage is that the container size will grow, rather than overwriting
    // a particular element
    *ex_back_insert = 5;

    print_output(fill_ex);

    // in this way, even if we advance the insert iterator,
    // the back inserter will "add" elements to the container
    // meaning that the container has the potential to be resized
    std::fill_n(std::back_inserter(fill_ex), fill_ex.size() + 10, 99);

    print_output(fill_ex);

    // std::back_inserter()
    // algorithms that reorder container elements
    return 0;
}