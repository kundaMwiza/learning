// note that in addition to facilities defined specifically for cpp, the 
// cpp library incorporates the c library. Headers  in C have names of the form .h
// the cpp versions of these headers are named c name e.g. if have a header of the form
// type.h , the cpp version will be defined as ctype. The suffix .h is removed and hte 
// header is prefixed with c to indicate that the header is part of the c library
// so ctype has the same contents as type.h, but in a form that is appropriate for 
// c++ programs

// in particular, the names defined in the cname headers are defined inside the std
// namespace, whereas those defined in the .h versions are not

#include <iostream> 
using std::cin;
using std::cout;
using std::string; 

int main() {

    // range for statement -> used to process every character in a string
    // statement iterates through the elements in a given sequence and performs
    // some operation on each value in that sequence.

    string str("some string,"); 

    // syntax 
    // for (declaration : expression) 
    //      statement
    // where declaration is the variable that will be used to acess the underlying 
    // elements in the sequence
    // expression is an object of a type that represents a sequence
    // on each iteration, the variable in declaration is initialized from the value of the 
    // next element in expression 

    // a string is an expression that represents a sequence of characters, so can be used with
    // the range for statement


    // e.g. new standard way of processing each element in a sequence
    // don't have to worry about the length of the sequence
    // or indexing into the sequence itself -> in the case of not wanting
    // to know the value of the index
    for (char c : str) {
        // some casting of an int to a character
        cout << (char) toupper(c) << std::endl; 
    }

    // count the number of punctuation marks in string
    unsigned num_punct = 0; 
    for (char c : str) {
        num_punct += ispunct(c);
    }

    cout << "The number of punctuation marks in: " << str 
        << " is: " << num_punct << std::endl; 

    
    // // base c++ way of processing each character in a sequence
    // for (string::size_type ind; ind < str.size(); ++ind) {

    //     cout << str[ind] << std::endl; 
    // }


    // if want to process the string in such a way as to change
    // some of the characters in the string - > must define our 
    // looping variable as a reference to the character

    // here auto will be a char, so c is a reference to char
    for (auto &c : str){
        // change each character to be upper case
        // c = (char) toupper(c); // explicit casting
        c = toupper(c); // implicit casting


    } 

    // lets see if the string has changed
    cout << "the new string is " << str << std::endl;

    // range for syntax
    // for (declaration : expression that is a sequence type) {
    // statement to perform on each element of the sequence type 
    // }

    // to access a character in a string, can use a subscript
    // e.g using the operator [] to access an element of the string
    // one thing to note here, for strings and vectors, is that accessing elements 
    // outside of 0 - sequence.size() is undefined
    // therefore, subscripting an empty string is undefined trivially
    // note also that supplying a negative integer index
    // will lead to a type conversion, from signed to unsigned
    // which may be out of bounds..and therefore lead ot undefined behaviour  

    // example to process only the first word of a string and capitalize it
    for (
        decltype(s.size()) index = 0; 
        index != s.size() && !isspace(s[index]); 
        ++index
        )
         {
            s[index] = toupper(s[index]); // capitalize the current character
        }

    
    return 0; 

}