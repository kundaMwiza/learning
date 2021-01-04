#include <iostream>
#include <vector>
#include <string>

using std::cin; 
using std::cout;
using std::string;
using std::vector;
using std::endl; 


int main() {
    // although can use subscript to access the elements of a container
    // the more general mechanism is the use of iterators - that an be 
    // used for the same purpose. 

    // the standard library defines several other containers apart 
    // from the vector container. as with the vector container
    // the other containers also define iterators that are a more general
    // way of accessing the elements of a container. However, not all of 
    // these containers have a subscript operator.

    // iterators give indirect access to an object, for a interator
    // the object is an element in a container or a character in a string
    // can use iterator to fetch an element and iterators have operations 
    // to move from one element to another. as with pointers, iterators may 
    // be invalid or valid -> a valid iterator either denotes an elment or denotes
    // a position that is one past the last element in a container. All other
    // iterator values are valid

    // unlike pointers -> don't use the address-of operator to obtain an iterator
    // instead types that have iterators have memebers that return iterators. 
    // in particular, these types have members named begin and end. The begin 
    // member reutnrs an interator that denotes the first element (or first character) 
    // if there is one

    vector<int> v{10, 5, 4, 1, 20}; 

    // b denotes the first element
    // e denotes one past the last element in v
    // e is used to denote a nonexistent element off the end of the container
    // it is used as a marker indicating when we have processed all of the elements.
    // the iterator returneb by end is often referred to as the off-the-end iterator or 
    // abbreviated as the "the end iterator". if the container is empty, begin 
    // returns the same iterator as the one returned by end
    auto b = v.begin(), e = v.end(); 

    // iterator operations
    // can compare two valid iterators using == or !=. iterators are equal if they
    // denote the same element or if they are both off-the-end iterators for the same 
    // container, otherwise they are unequal
    auto bb = *b; // returns a reference to the element denoted by the iterator b
    // the iterator is const, but the reference returned is const/not const
    // depending on the vector type
    // iter->mem dereferences iter and fetches the member named mem from the underlying
    // element. This is equivalent to (*iter).mem : this is similar to using a pointer 
    // to access an element of a struct e.g. p->mem = (*p).mem 
    // ++iter incrememts iter to refer to the next element in the container
    // --iter decrements iter to refer to the previous element in the container
    //iter1 == iter2 compares the iterators for equality(inequality)
    // iter1 != iter2
    
    // use an iterator to capitalize the first character of a string

    // define some string 
    string s1 = "mwiza"; 

    auto str_begin = s1.begin(), str_end = s1.end();

    // first check that the string is not empty
    // if they are equal then the string is empty
    // if they are unequal then there is atleast one character in the string
    if (str_begin != str_end) {
        *str_begin = toupper(*str_begin); // map the first character in string to upper
    }

    // write out the new string
    // cout << s1 << endl;

    // use an iterator to convert the entire string to upper
    // can use a range-for or the more verbose version using an iterator

    string s2 = "kunda"; 
    // range for 
    for (auto &temp : s2) {
        // map each character to upper
        temp = toupper(temp);
    }

    // cout << s2 << endl;

    string s3 = "mwizakunda"; 

    // more verbose version 
    // str_iter, when dereferenced returns a reference to the element it 
    // is pointing to
    for (auto str_iter = s3.begin(); str_iter != s3.end(); ++str_iter) {
        // map to upper
        *str_iter = toupper(*str_iter); 
    }

    // print output
    // cout << s3 << endl; 

    // from the above for loop can see that used != or == when testing whether 
    // the for loop had reached termination or not, the reason for using this
    // is a semantic of c++; since iterators have != and == defined, this method
    // of determining termination for a for loop generalizes to all containers that 
    // have iterators defined. iterators don't have < or > defined for them.

    // note that do not need to know the precise type of an iterator, or the precise
    // type of a strings size_type member which is why auto is used

    // the library types that have iterators define types named iterator and const_iterator
    // that represent actual iterator types. in the same way that strings have a size_type member 
    // defined as string::size_type
    // vector<int>::iterator it -> creates an iterator with type defined by the vector<int> class
    // string::iterator it2 -> creates an iterator with type defined by the string class
    // vector<int>::const_iterator it3 -> creates an iterator that can read elements
    // but cannot modify them
    // if a container or string is const, auto iter = container.begin() will cause the base 
    // type of iter to be a const iterator to prevent changing the values of the container
    // however can manually declare that an iterator is const by using e.g.
    // vector<int>::const_iterator iter = container.begin(); 
    // an iterator type supports dereferencing to return references to objects
    // supports access to member elements e.g. iter->mem 
    // supports incrementing the iterator ++iter and --iter 
    // and also supports testing equality between iterator objects e.g iter1 == iter2

    // to let us ask specifically for the const_iterator type to be returned when requesting 
    // an iterator for a container, the new standard defiend two new functions named 
    // cbegind and cend i.e
    // vector<int> v; 
    // auto it1 = v.cbegin()
    // auto it2 = v.cend() 
    // both of these return const_iterators for their containers

    // if the object that an iterator/pointer refers to when dereferenced is of class type
    // in order to access member functions of that class, must use parentheses for a vector 
    // of strings 
    // vector<string> sv{"the", "quick", "brown", "fox", "jumps", "over"}; // list initialize a string vector

    // // get constant begin and end iterators
    // auto sb = sv.cbegin(), se = sv.cend();

    // // access the .empty() member function of a string for the first string:
    // // return the result of whether the first string in the string container is empty
    // // the same syntax would need to be used for a pointer

    // bool first_empty = (*sb).empty(); 
    // bool second_empty = sb->empty();
    // cout << first_empty << endl;
    // cout << second_empty << endl;

    vector<string> prehab_vec{"you", "just", "got", "litt", "up!"};

    // for loop to tell prehab that he just got litt up 
    // emphasise by mapping each string to upper case
    for (auto sb = prehab_vec.begin(); sb != prehab_vec.end(); ++sb) {

        // range for to process each string to upper case
        for (auto &temp_char : *sb) {
            temp_char = toupper(temp_char);
        }
        
        // write to standard output
        cout << *sb << endl;    

    }


    // prgoram to create a vector with ten int elements
    // using an iterator, assign each element a value that is 
    // twice its current value

    // construct a vector with 10 ints
    vector<int> int_vec;

    for (int i = 0; i <= 10; ++i) {
        // append int to int_vec
        int_vec.push_back(i); 
    } 

    // iterate over the vector and multiply each element by two
    for (auto ib = int_vec.begin(); ib != int_vec.end(); ++ib) {
        // double each value
        *ib *= 2; 
        
        // write output to stdout
        cout << *ib << endl; 

    }

    

    return 0;
}

