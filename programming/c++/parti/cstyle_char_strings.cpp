#include <iostream>
#include <string>
#include <vector>

int main() {


    // c-style character strings are not a type, but a convention for how to manipulate
    // and use character strings
    // a c-style character string is of the form char c[] = {'a', 'b', 'd', '\0'};
    // or char c[] = "somestring";. The array must end with a null terminating character
    // The C std library defines functions for operating on c style character strings
    // e.g. strlen, strcmp, strcat and strcpy. the inputs to these functions are 
    // pointers pointers to character arrays that have a null terminating character at the end
    // the functions are undefined if the input to the function is an array which does not have
    // a null terminating character at the end of the array e.g. 
    // char bc[] = {'a'}; does not have a null terminating character, so strlen(bc) is undefined

    // for string comparison operations e.g. == != < > , the c++ type string uses
    // dictionary ordering to compare strings -> according to the two rules
    // 1 two strings are equal if the lengths of both strings are the same
    // and every character is the same. 
    // 2 if the two strings differ in characters, the result is based on the 
    // first instance of where the two strings differ in characters
    // when comparing c-style character strings however, the comparison 
    // is based on the pointers/ iterators -> comparing memory location, rather than 
    // their values. In particular, if the pointers point to two different 
    // character arrays, then comparisons between the two pointers is undefined


    //  can initialise a string using a null terminated character array
    char s1[] = {'a', 'r', 'e', '\0'}; 
    std::string s2 = "blah blah";

    std::cout << s1 + s2 << std::endl; 

    // cannot initialize a character pointer from a string
    // to convert a string into a c-style character string, there is a member
    // function for strings c_str() that converts a string into a 
    // c style character string -> returns am array of constant char
    const char *cs1 = s2.c_str(); 

    // an array can be used to initialize a vector. To do so, 
    // a pointer to the first element to be copied and a pointer one past the element that needs 
    // to be copied. e.g. 
    int int_arr1[] = {0, 1, 2}; // array of 3 ints
    // initialize a vector using an array with two pointers
    std::vector<int> int_vec1(std::begin(int_arr1), std::end(int_arr1)); 
    
    for (int &i : int_vec1) {
        std::cout << i << std::endl; 
    }

    // alternatively can subset the array by using a range
    // copies the second element
    std::vector<int> int_vec2(int_arr1 + 1, int_arr1 + 2); 

    for (int &i : int_vec2) {
        std::cout << i << std::endl; 
    }

    // advice -> modern c++ programs should use vectors and iterators instead of 
    // built in arrays and pointers, and use strings rather than c-style array-based 
    // character strings

    return 0; 
}