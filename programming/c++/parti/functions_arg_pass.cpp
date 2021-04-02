#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl; 

bool str_match(const std::string &, const std::string &); 
bool str_match(std::string *, std::string *); 
void advance_char_ptr(const char * );     

int main() {

    // parameter initialisation from arguments works the same way as 
    // variable initialisation.

    // if a parameter is of type base_type & then on intialising 
    // with an argument, the argument is said to be 'passed by reference' 
    // or the function is 'called by reference'

    // if a parameter is copy initialised from an argument e.g. type arg = value
    // then the argument and the parameter are independent objects. In this case
    // changes to the parameter do not affect the intitialising argument.
    // In this case the arguments are said to be 'passed by value' or the function 
    // is said to be 'called by value'. 

    // -- passing parameters by value -- 
    // for pointer parameters, similarly, the argument and the parameter are distinct
    // objects if passed by value, even if the pointer at initialisation hold the same 
    // memory address. Using pointers is one way of having a function work on the same
    // object in memory, rather than copying it
    // In this case, in cpp, it is best to use reference parameters instead

    // -- passing parameters by reference -- 
    // operations on a reference are just operations on the object to which the 
    // reference refers.
    // because of this, references can be used to avoid copies of large objects

    // using references to avoid copies -- 
    // for large class types and large containers it can be inefficient to copy these objects.
    // also some class types cannot be copied. Functions must use reference parameters to operate
    // on objects of a type that cannot be copied
    // for example strings can be very long, and so passing these to functions by value
    // would require copying the strings. If they are passed by reference, then operations 
    // will be performed on the original string:


    std::string s1 = "mwiza jumps over the big lazy dog"; 
    std::string s2 = "the dog got angry, barked and bit mwiza";

    
    // call function to compare the two strings
    cout << "using references --" << endl; 
    if (str_match(s1, s2)) {
        cout << "The strings are of the same length" << endl;
    } else {
        cout << "The strings are of different length" << endl; 
    }

    // similarly, can pass the strings by value through pointers
    // this is better than directly copying the entire strings
    // but the additional overhead here is allocating memory 
    // for the two pointers

    // call function to compare the two strings
    cout << "using pointers --" << endl;
    if (str_match(&s1, &s2)) {
        cout << "The strings are of the same length" << endl;
    } else {
        cout << "The strings are of different length" << endl; 
    }

    // const parameters and arguments

    // -- top level const
    // when initialising local variables, top level const is ignored
    // similarly, when initialising function parameters, top level const is ignored
    // so can pass a const/ non const object to initialise a top level const parameter
    // because of this, function overloading with funtions of the form 
    // type fn(const type var), type fn(type var) is illegal in cpp, since 
    // top level const is ignored, the two function declarations are pretty much the same
    // -- low level const
    // note that all const references -> references to const are low level const
    // it is not possible to have a top level const reference since references are not objects
    // variables with low level const can be initialised from non const objects
    // but non const objects cannot be initialised from low level const
    // e.g. const int * ptr = &non_const_object is fine, but 
    // non_const_object = low level const_ptr is not fine, since the base type
    // are different
    // similarly with references

    // ideally, use a const reference where possible if the reference 
    // is not required to change the object that is being referenced.
    // references to const can take non const objects as inputs, as well as literals, but this is not 
    // true for non const references. 
    // This is because intialising an object from a low level const is illegal -- 
    // This therefore limits the input types to a function. See below

    cout << "edit to using const string references--" << endl; 
    if (str_match(s1, s2)) {
        cout << "The strings are of the same length" << endl;
    } else {
        cout << "The strings are of different length" << endl; 
    }

    // two properties of arrays that prevent them from being passed by value 
    // to functions: arrays cannot be copied, and arrays are implicitly converted
    // to a pointer that points to the first element in the array. 
    // so the only possible parameter to be passed as input to an array ("by value")
    // is a pointer to the first element of the array
    // However can easily pass arrays by reference to a function

    // methods to pass arrays to functions:
    
    // --- using a marker to specify the extent of an array
    // for example c-style character strings contain '\0'
    // which is the null termination character to conclude an array
    // see example (advance_char_ptr) below which advances a pointer until the null terminated character is found
    
    // --- using the standard libraries
    // either pass a pointer to the beginning element and one past the end
    // or pass the iterators std::(c)begin and std::(c)end iterators
    // below uses iterators
    
    // --- explicitly passing a size parameter 
    // pass a std::size_t parameter to indicate the length of the array

    // similar to the convention of using const references for parameters that
    // are not modified in a function, const pointers should be used as parameters
    // when referencing arrays that are not modified in a function

    // array reference parameters
    // instead of using pointers to access an array from within a function
    // can pass an array by reference to a function e.g. 
    // void some_func( const int (&ref)[10]) {
        // for (auto &elem : ref) {
            // 
        // } 
    // }
    // const if the reference will not be used to modify the array
    // But, unlike pointers that don't need the dimension of the array 
    // since arrays are automatically converted to a pointer to the first element 
    // in the array.
    //  for references, the dimension of hte array they are referencing 
    // is part of the type, so need to include the dimension of the array
    // which means the function defined above only works for 
    // int arrays of dimension 10
    
    return 0; 
}

// bool str_match(std::string &s1_ref, std::string &s2_ref) {

//     return s1_ref.size() == s2_ref.size(); 
// }

// better design of the above function
// this function can also take literals and non const strings as input
// the one above cannot take literals as input
// moreover, the function is not changing the underlying object 
// so it is more clear to the user
bool str_match(const std::string &s1_ref, const std::string &s2_ref) {

    return s1_ref.size() == s2_ref.size();
}

bool str_match(std::string *s1_ptr, std::string *s2_ptr) {
    
    return s1_ptr->size() == s2_ptr->size();
}

// showcasing how to iterate over a character array taking advantage 
// of the fact that c-style character strings have null terminating chars
void advance_char_ptr(const char * char_arr) {

    // test if char_arr is a null pointer e.g. type * declarator = NULL
    if (char_arr) {
        // while char_arr is not pointing to the null terminating character
        while (*char_arr) {
            // advance pointer and print current character
            cout << (*(char_arr++)) << endl; 
        }
    }
}

void iterate_char_arr(std::iterator begin, std::iterator end) {
    // make sure begin != end
    if (begin != end) {
        // while begin != end
        while (begin != end) {
            // advance begin iterator and print current character
            cout << (*(begin++)) << endl; 
        }
    }
}


