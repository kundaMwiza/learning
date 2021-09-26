#include<iostream>

#include<vector> 
#include<string> 
#include<stdexcept>  

using std::cin;
using std::cout; 
using std::endl; 


int main() {

    // - exceptions are run-time anomalies - - such as losing a database connection
    // or encountering unexpected input - that exists outside the normal functioning 
    // of a program

    // exception handling is used when one part of a program detects a problem that it cannot
    // resolve. and the detecting part of the program cannot continue
    // exception handling usually consists of two parts. The first part detects the anomaly
    // the second part decides what to do with the anomaly

    // exception handling in c++ involves
    //  - throw exceptions, detecting part of the exception uses to indicate that it 
    // encountered something it can't handle. A throw raises an exception
    // - try blocks, a try block starts with the keyword try and ends with one or more catch 
    // clauses
    // - catch clauses are known as exception handlers
    // a set of exception classes that are used to pass information about what happend 
    // between a throw and an associated catch

    // throw exception - detecting part raises an exception
    // throw consists of the keyword throw followed by an expression. The type of expression
    // determines what kind of exception is thrown. A throw expression is usually followed by 
    // a semi-colon, making it an expression statement

    // int a = 0, b = a; 
    // //  detecting part is the condition a != b
    // if (a != b) {
    //     //  throw raises an exception
    //     // transfer control to a handler that will know how to handle this error
    //     // runtime_error is a standard library exception type defined in the stdexcept header
    //     // must initialise a runtime_error by giving it a string or a C-style character string
    //     // the string provides additional information about the problem
    //     // below are just creating an object of type runtime_error initialised with a string
    //     throw std::runtime_error("The two integers must be the same!"); 
    // }

    // a try block begins with the keyword try followed by a block - a compound statement
    // a sequence of statements enclosed in curly braces
    // following the try block is a sequence of catch clauses 
    // catch clause consists of three parts: the keyword catch, the declaration
    // of objects within parenthesis called exception declaration, and a block
    // NOTE that variables defined inside the try block are inaccessible inside the catch clauses

    // try {
    //     program-statements
    // } catch (exception-declaration) {
    //     handler-statements
    // } catch (exception-declaration) {
    //     handler-statements
    // }

    // try {
    //     int a = 0, b = a; 

    //     if (a != b) {
    //         // objects of type std::runtime_error have a member function called .what()
    //         // which returns a copy of the string that was used to initialise the exception type
    //         throw std::runtime_error("The two integers must be"); 
    //     } 
    // } catch (std::runtime_error())


    // int a = 0; 

    // switch(a) {
    //     case 0:
    //         break; 
    //     case 1: 
    //         break;
    // }

    // do 
    //     a *= 5; 
        
    // while(a >= 0); 

// In complicated systems, the execution path of a program may pass through multiple 
// try blocks before encountering code that throws an exception. For example, a try 
// block might call a function that contains a try, which calls another function with its own try, and so on.
// The search for a handler reverses the call chain. When an exception is thrown, 
// the function that threw the exception is searched first. If no matching catch is found,
//  that function terminates. The function that called the one that threw is searched next.
//   If no handler is found, that function also exits. That function’s caller is searched next,
//    and so on back up the execution path until a catch of an appropriate type is found.
// If no appropriate catch is found, execution is transferred to a library function named terminate. 
// The behavior of that function is system dependent but is guaranteed to stop further execution of the program.
// Exceptions that occur in programs that do not define any try blocks are handled in the same manner:
//  After all, if there are no try blocks, there can be no handlers. If a program has no try blocks and
//   an exception occurs, then terminate is called and the program is exited.

// eg below, basically the search for a catch block is firstly within the enclosing block
// if not found, go back one level 
// and so on 
// if no handler is found -> execution transfered to a library function named terminate
// func() {
    // // try {
    //     func() {
    //         try {}
    //         catch () {

    //         }
    //     }
    // } catch () {

    // }
// }

// the c++ library defines several classes that it uses to report probelms encountered 
// in the functions in the standard library. 
// exception classes are also intended to be used in the programs written
// classes are defined in four headers
// exception header - most general kind of eception class named exception
// communicates that an exception occurred but provides no additional info
// stdexcept - defines classes such as exception, runtime_error, range_error etc
// new header defines bad_alloc exception type
// type_info header defines the bad_cast exception type

// simple program to divide two ints given user input
int a, b;

cout << "Enter two integers" << endl; 

while (cin >> a >> b) {
    try {
        if (b == 0) {
            throw std::domain_error("Cannot divide by zero");
        }
        
        int res = a / b;

        cout << "The division result is " << res 
             << "\n Do you want to run the program again? Enter y or n" 
             << endl;  

        char o;
        cin >> o; 

        // continue or break?
        if (o != '\n' && o == 'y') {
            continue;
        } else {
            break;
        }



    } catch(std::domain_error err) {
        cout << err.what() 
             << "\n Try again? Enter y or n" 
             << endl; 

        char c; 
        cin >> c; 

        // continue or break?
        if (c != '\n' && c == 'y') {
            continue;
        } else if (c != 'n' && c == 'n') {
            continue;
        } else {
            break;
        }
     }
}

return 0; 
}