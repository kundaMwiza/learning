#include <iostream>
#include <vector>
#include <string>

int main(int argc, const char *argv[]) {

    // -- first step to function matching is to identify a set of overloaded functions
    // to consider for a function call
    // the functions considered in this case are called candidate functions
    // a candidate function is a function with the same name as the 
    // called function and for a declaration that is visible at the point of call
    
    // -- second step to function matching considered the the functions
    // that can be called with the arguments given to the call operator
    // the selected functions are the viable functions. viable dd
    // functions are functions that have the same number of parameters 
    // as there are arguments in the call, and the types of each argument 
    // matches/ or is convertible to the type of the corresponding parameter 

    // the next step is now to look at the type of the argument, and the corresponding
    // parameters. functions with arguments that match their corresponding parameter exactly have 
    // precedence over functions with arguments that can be converted to their corresponding parameters

    // 1. candidate functions -> functions with declarations in a particular scope that match 
    // the name of the calling function
    // 2. viable functions -> functions which have the number of arguments and type of arguments 
    // matching those of the corresponding parameters/ or are convertible
    // 3. pick the 'best' match -> functions which match closest with the calling functions 
    // specification have precedence
    // the best matching function is the one that has arguments having:
    // - a match for each argument that is no worse than the match required by any other viable function
    // - there is atleast one argument for which the match is better than the match provided by any other viable 
    // function
    // if two functions resolve to being on equal footing for a viable function for the call, 
    // this is ambiguous and the compiler will complain
    return 0; 
}