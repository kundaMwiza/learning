#include <iostream>
#include <string>
#include <vector>
#include <fstream> 


int main(int argc, const char *argv[]) {

    // library defines a collection of IO types in addition to the 
    // istream and ostream types to support other scenarios 
    // e.g. reading and writing to files. These additional operations 
    // are defined in different headers

    // iostream header containes types istream, ostream and iostream for 
    // reading and writing to input, output streams

    // fstream header contains types for reading and writing 
    // from files
    // types: ifstream -> read from a file stream
    // ofstream -> write to a file stream 
    // fstream -> read and write to a file stream

    // sstream header contains types for reading and writing 
    // strings
    // istringstream -> read from a string
    // ostringstream -> write to a string
    // stringstream -> read and write to a string


    // fstream and sstream header files define class types 
    // that inherit from classes in the iostream headers
    // for example ifstream class and istringstream inherits 
    // from the istream class -> so similar operators 
    // e.g. >> and << 
    // so can use ifstream and istringstream objects in the same way 
    // as we have used cin

    // because of inheritance, the use of cin (istream objects) 
    // is similar to the use of ifstream and istringstream objects 
    // so for example, there is no copy or assignment for istream objects
    // can only pass by reference, likewise for ostream objects. And also cannot have const istream objects
    // due to modification

    // example of declaring an object of type ifstream defined in the fstream c++ header
    std::ifstream in1; 

    // each stream type (istream, ostream, ifstream, ofstream, e.t.c.) is a class
    // and each of the classes defines fnctions and flags to describe the state of 
    // the stream type
    // for example std::istream::iostate, std::istream::badbit, std::istream::failbit
    // which return std::istream::iostate objects which describe the status of the stream
    // e.g. std::istream::failbit returns an iostate value to indicate that an IO operation failed
    // std::istream::fail() returns true if failbit or badbit iostate in the stream is set
    // once an error has occurred, subsequent IO operations on that stream will fail:

    int ival;
    std::istream inp_stream; 
    inp_stream >> ival; 

    // if inp_stream receives a string instead of an int, the iostate of the stream will be set
    // and we won't be able to use inp_stream. As such, code should check whether a stream is in 
    // a bad state before it is used
    // the easiest way to determine the state of a stream object is to use that object as a condition:
    // while (cin >> word)
    // the '>>' operator returns its left hand operand, and as a result, the logical state of the istream cin 
    // will be queried, if the stream is not in a failed state, the logical value of the stream is true

    // similar to std::size_t which is a machine dependant unsigned integral type
    // the IO library also defines a type named iostate which is a machine-dependant integral
    // type that conveys information about the state of a stream
    // the type is used as a collection of bits
    // the IO classes define four constexpr values of type iostate 
    // that represent particular bit patterns

    // to turn off specific error bits for a specific iostate, can use bitwise operators 
    // for example cin.rdstate() <- returns the current state of an iostream object
    // cin.rdstate() & ~cin.failbit & ~cin.badbit gives a set of bits where fialbit and badbit 
    // are turned off
    
    return 0;
}