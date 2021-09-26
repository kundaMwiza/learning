#include <iostream>
#include <deque>
#include <numeric>
#include <algorithm>
#include <random>

template <typename T>
void print_output(const T &container)
{

    for (auto &elem : container)
    {

        std::cout << elem << std::endl;
    }
}

// adaptors
// container adaptors like stack queue
// function adaptors like std::bind
// iterator adaptors like std::back_inserter and std::front_inserter
// adapters bind to objects and modify the operations performed on the
// objects
int main(int argc, const char *argv[])
{

    //
    // insert iterators - bound to a container
    // assignment operations call operations on the contianer
    // to insert elements into the container
    //

    // insert iterators
    // insert iterator operations
    // it = t; this inserts the value t at the current position denoted by it
    // *it, ++it and it++ do nothing to it, each operation returns it

    // three kinds of inserters, front_inserters, back_inserters and inserter
    // front_inserters bind to containers that have the push_front operation implemented e.g. deque
    // back_inserters bind to containers that have the push_back operation implemented e.g. vector
    // inserters bind to containers and take an additional argument for an iterator into the container that
    // they are binding to. The iterator should point to a position in the container

    std::mt19937 eng(123);
    std::uniform_int_distribution<int> dist(1, 10);

    std::deque<int> copy_deque(10), front_deque, back_deque, gen_deque;

    std::generate(
        copy_deque.begin(),
        copy_deque.end(),
        [&eng, &dist]()
        {
            return dist(eng);
        });

    std::cout << "container values are" << std::endl;
    print_output(copy_deque);

    // front inserter -> inserts elements into the container it is bound to
    // using the push_front operation
    std::copy(
        copy_deque.begin(),
        copy_deque.end(),
        std::front_inserter(front_deque));

    std::cout << "front inserter outputs are" << std::endl;
    print_output(front_deque);

    // back inserter -> inserts elements into the container it is bound to
    // using the push_back operation
    std::copy(
        copy_deque.begin(),
        copy_deque.end(),
        std::back_inserter(back_deque));

    std::cout << "back inserter outputs are" << std::endl;
    print_output(back_deque);

    // general inserter, will insert elements before the position
    // pointed to by the general inserter
    // after an element is inserted, the iterator is advanced to point
    // back to the original position
    // in other words, the general inserter works like push_back(), only
    // though elements are not inserted at the back of the container
    std::copy(
        copy_deque.begin(),
        copy_deque.end(),
        std::inserter(gen_deque, gen_deque.begin()));
    std::cout << "gen inserter outputs are" << std::endl;

    print_output(gen_deque);

    // auto f_inserter = std::_Weak_result_type_imp
    return 0;
}