#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

int main(int argc, const char *argv[])
{

    // iostream types are not containers
    // however, there are iterators that can be used with objects of the
    // IO types (istream, ostream, ifstream, ofstream fstream, e.t.c)
    // an istream iterator reads an input stream,
    // an ostream iterator writes an output stream
    // the iterators treat their corresponding stream as
    // a sequence of elements of a specified type
    // with stream iterators can use the generic algorithm
    // to read/ write data from stream objects

    // construct a sentence from a c-style char arr i.e const char *
    std::string sentence = "the quick brown fox jumps over the lazy dog blah";

    // initialise sstream to read from
    std::stringstream string_stream(sentence);
    // open a file stream to write to
    std::fstream file_stream("test_output.txt", std::fstream::out | std::fstream::trunc);

    // istream/ ostream iterator operations
    // construction
    // std::istream_iterator<T> in(is); binds an input
    // stream iterator to a input stream
    // std::istream_iterator<T> end; creates an off the end iterator
    // for an istream_iterator of type T
    // in1 == in2 must be reading the same element type
    // they are equal if they are both the end value or are bound to the
    // same input stream
    // *in returns the value read from the input stream
    // in-> get the member of the object read from the input stream
    // ++in, in++, reads the next value from the input stream using >> for the
    // element type, both return references to iterators

    // ostream iterator
    // std::ostream_iterator<T> out(os); out writes values of type T to output stream os
    // std::ostream_iterator<T> out(os, d); out writes values of type T followed by d to output stream os
    // d points to a null terminated character array
    // note that this is after every write to the output stream. E.g. can include commas after
    // every write to the output stream

    // out = val  uses the operation << on the output stream that the iterator is bound to
    // val must have a compatible type to T
    // *out, ++out and out++ do nothing to out

    // when an istream iterator object is created, the element type that is to be read from the input stream
    // is required to be specified

    std::istream_iterator<std::string> str_iter(string_stream);

    if (!file_stream)
    {
        std::cout << "there is a problem with the file stream" << std::endl;
        return 1;
    }

    std::istream_iterator<std::string> str_eof;
    std::ostream_iterator<std::string> str_out_iter(file_stream);

    std::cout << "print output from input stream" << std::endl;

    unsigned int n_cols(2), cols_written(0);

    for (auto it = str_iter; it != str_eof; ++it)
    {
        std::cout << *it << std::endl;
        std::cout << "position number " << cols_written << std::endl;

        *str_out_iter++ = *it;
        cols_written += 1;

        // include new line
        if (cols_written == n_cols)
        {
            file_stream << "\n";
            cols_written = 0;
        }
        else
        {

            file_stream << ",";
        }
    }

    // using accumulate to sum values read from standard input
    std::istream_iterator<int> stdin_iter(std::cin), stdin_eof;

    auto total_sum = std::accumulate(
        stdin_iter,
        stdin_eof,
        int(0));

    std::cout << "the total sum is " << total_sum << std::endl;
    return 0;

    // the ostream_iterator can be defined for any type that has an output operator <<
    // i.e std::ostream_iterator<T> stream T must define the << operator otherwise will not
    // be able to write outputs to the output file stream
    // this is also the case for istream iterators. The element type needs to define
    // the << operator

    auto str_iter = sentence.rbegin();
    // reverse iterators implement the base member function to convert a reverse
    // iterator into a forward iterator
}