#include <iostream> 

// allow access to all identifiers in the 
// std namespace in the global namespace
using namespace std; 

int main() { 

    // passing command line arguments to main
    // arguments provided by the user are passed to main via two optional 
    // parameters 
    // int main (int argc, char *argv[]) {...}
    // the second argument is an array of pointers to c-style character strings
    // the first argument gives the number of strings in the array
    // when arguments are passed to main. the first element in argv is either 
    // the empty string or the name of the program
    // subsequent elements are the arguments provided on the cmd line 
    // the element just past the last pointer is guaranteed to be 0
    // when using arguments in argv, should start from argv[1], 
    // argv[0] is a poitner to either the empty string or the name of the program
    return 1; 
}