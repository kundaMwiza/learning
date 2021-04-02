#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout; 
using std::endl;


int main() {

    // most statements in cpp end with a semi colon
    // usually statements have a side effect when evaluated
    // e.g. print or update the value of a variable.
    // the expression statement below declares an int variable ival
    int ival;
    // add 5 to ival
    ival + 5;

    // null statements are the simplest form of a statement in c++
    // an empty statement is a null statement -> it is a single semicolon 
    ; 

    // null statement is useful when language requires a statement but the 
    // program logic does not ~akin to pass in python
    // e.g. when all the work required by a loop can be done inside the 
    // condition:
    string s;

    // keep reading so long as the input by the user is not a space
    // if read is succesful, test if its a space, if so keep reading from stdin
    // null statements should be commented to alert readers that they are intended
    while (cin >> s && !isspace(s) ) 
        ;  // null statement

    // a compound statement, usually referred to as a block/ is a (possible empty) 
    // sequence of statements. A block is a scope. Names introduced inside a block
    // are accessbile only in that block and in blocks nested inside that block
    // Names are visible from where they are defined until the end of the (immediately)
    // enclosing block
    

    // switch statement 
    // after a case label is matched, execution starts at that label and continues 
    // across all the remaining cases or until the program explicitly interrupts it
    // to avoid executing code for subsequent cases 
    // note that if the integral type for a case matches the expression in the switch condition
    // all subsequent statements will ALSO be run even if there isn't a match with that specific case
    // this is why break is usually used within each case of a switch statement
    // label must be an integral constant, not float!
    // switch (expression) {
    //     case label: 
    //         expression;
    //         break;
    //     case label:
    //         expression;
    //         break;  
        // default: executed when no case matches
    //  
    // }

    // When execution jumps to a particular case, any code that occurred inside the switch before that label is ignored
    //  it is illegal to jump from a place where a variable with an initializer is out of scope to a place where that variable is in scope:
    // if need to define a variable for a particualr case, can do so by creating a block {} for that case

    // do while 
    // variables in condition must be defined outside of the do while statement 
    // do {
    //     statement;
    // } 
    // while (condition);


    // jump statements

    // A break statement terminates the nearest enclosing -while-, -do while-, -for-, -or switch statement-.
    //  Execution resumes at the statement immediately following the terminated statement.
    // a break can appear only within an iteration statement or switch statement. A break affects only the nearest 
    // enclosing loop or switch

    // A continue statement terminates the current iteration of the nearest enclosing loop and immediately
    // begins the next iteration. It can only appear inside a for, while or do while. Like the break statement, 
    // it only affects the nearest enclosing loop. A continue may only appear inside a switch only if 
    // the switch is embedded inside an iterative loop


    // goto statement
    // a goto statement provides an unconditional jump from the goto to another statement in the same function
    // goto statements make programs hard to understand and hard to modify - avoid using these 
    // syntactic form 
    // goto label; where label is an identifier that identifies a statement.
    // a labeled statement is any statement that is preceded by an identifier followed by a colon:
    // e.g. end: return; here the identifier is end.
    // goto end would go to the statement executing return

    goto end; 

    // label identifiers are independent of names used for variables and other identifiers
    // so a labeled statement may have the same identifier as another entity in the program
    // the goto and the labeled statment to which it transfers control must be in the same function
    // similar to switch, a goto cannot transfer control from a point where an intialized variable
    // is out of scope to a point where that varaible is in scope
    // using a goto to jump back to a point prior to a variable is defined will destroy the variable
    // and reconstruct it

    end: return 1;
}