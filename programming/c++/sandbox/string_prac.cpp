#include <iostream> 
#include <string>

using std::string; 
using std::cin; using std::cout; 


int main() {
    //  initialising a string class 
    // default initialisation to the empty string
    string s; 
    // initialising a string equal to a string literal
    string s1 = "mwiza is the best";
    // s2 is a copy of s1
    string s2 = s1; 

    // here s4 is a copy of the string "cccccccc" 10cs..
    // this type of initialisation is defined by the string class
    // note that when a string is initialised from a string literal
    // the null character is not included
    string s4(10, 'c'); 

    // when initialize a variable using =, asking the compiler to copy 
    // initialize the object by copying the initializer on the RHS into 
    // the object being created. e.g. string s = "ssdfdsf" or string s = s1
    // are both forms of copy initialization. Direct initialization includes
    // omitting the = i.e string s("blah"); or string s(n, 'c)
    // if have a single initializer, can use either copy or direct intialization
    // but if initializing a variable from multiple values, have to use the direct
    // form of initialization

    string s5 = "hiyra"; // copy initialization
    string s6("hiyra"); // direct initialization
    string s7(10, 'c'); // direct initialization

    // if want to use several values to initialize a variable
    // can do so by by indirectly using the copy form of initialization
    // by creating a temporary object to copy

    // temporary variable is on the RHS, that is then used to copy initialize 
    // s8 
    string s8 = string(10, 'c'); 

    // along with defining how objects are created and initialized, a class also defines
    // the operations that objects of the class type can perform. 

    // can defien operations by name e.g. add() function. a class can also define 
    // what various operator symbols, such as << or +, mean when applied to objects of the
    // class' type.

    // os << s writes s onto output stream os, can be std::cout for example
    // or a user define file. returns os

    // is >> s writes the input stream into the string s, the input stream is 
    // whitespace separated returns s
    string k1, k2, k3, k4; 

    cin >> k1 >> k2 >> k3; 

    // std::getline(is, s) reads a line of input from is into s. returns is
    getline(cin, k2); 

    std::cout << "the first verification is k1 " << k1 
              << "the second verification is " << k2 << std::endl; 


    std::cout << "is the string empty? " << k1.empty() << std::endl; // returns true if the string is empty, otherwise returns false
    std::cout << "the number of characters in our string is " << k1.size() << std::endl; // reutnrs the number of characters 

    // note that string.size() returns an object of type string::size_type rather than an int or unsigned

    char &test = k1[1]; // returns a reference to the char at position n in string test, positions start at 0

    std::cout << "the string at position 1 is " << test << std::endl; 

    string k12 = k1 + k2; // addition of strings returns the concatenation of strings

    std::cout << "the concatenated string is " << k12 << std::endl; 

    k1 = k2; // replaces characters in k1 with a copy of k2

    std::cout << "the new k1 is " << k1 << std::endl; 

    int equalyno = k1 == k2; 
    int equalyno2 = k1 != k2; 

    std::cout << "are the strings k1 and k2 equal? " << equalyno << std::endl; 
    std::cout << "are the strings k1 and k2 equal? " << equalyno2 << std::endl; 


    // other comparisons are case sensitive e.g. <, <=, >, >= 
    // and use dictionary ordering to make the comparison

    // like the behaviour of the built in types when it comes to using
    // the standard input and standard output e.g. std::cin and std::cout
    // the << and >> operators defined for the string class also return the
    // left hand operand as the return result, so for example

    // string j1, j2; 

    // cin >> j1 >> j2;  cin >> j1 returns cin after writing the contents of cin into j1
    // after the next contents of cin can then be read into j2, this behaviour is similar 
    // for cout

    // note that cin is white space separated for reading from standard input into strings
    // so the , this behvaior is defined by the string class, so after each white space
    // separated word, there will still be input in the standard input if there is the more than
    // one 'word' in the standard input

    string test_cin;

    while (cin >> test_cin) {
        std::cout << "The word we just read from standard input is " << test_cin << std::endl; 
    }


    std::cout << k1 << std::endl; 


    // testing getline to see if it stops reading from cin when the first character is the
    // newline char \n
    string get_line_test;

    getline(std::cin, get_line_test); 

    std::cout << "getline read in: " << get_line_test << std::endl;


    // companion types are types that make it possible to use the library types
    // in a machine-independent manner. string::size_type is one of these companion types
    // string::size_type is of type unsigned. when companion types are used as the output
    // of a member function, when defining a variable that holds these outputs, the 
    // companion type should be used as the base type. e.g. string::size_type = k1.size(); 
    // if tedious to write string::size_type, in the new standard c++ 11 can use
    // auto and decltype e.g.g decltype() var or auto var = and the compiler should
    // provide the appropriate type for var  
    // moving forwards, when using functions from libraries, should look at the return type
    // of funtions in order to decide the most appropriate type to store a variable
    // when using string::size_type in an expresson, it is best to use unsigned ints rather
    // than ints to avoid conversion from ints to unsigned

    // rules for string comparisons

    // 1 
    // if two strings have different lengths and if every character in the shorter
    // string is equal to the corresponding char of the longer sring, then the shorter
    // string is less than the longer one

    // 1
    // if any characters at corresponding positions in the two strings differ, then 
    // the result of the string comparison is the result comparing the first character
    // at which the strings differ
    
    // for strings, assignment replaces the contents of a string with the
    // contents of another string


    return 0;

}