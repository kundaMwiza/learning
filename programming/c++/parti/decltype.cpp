#include <iostream> 

int main() {
    //  sometimes want to define a variable with a type that the compiler
    // deduces from an expression but do not want to use that expression
    // to initialize the variable. For such cases, the new standard
    // introduced a second type specifier, decltype, which returns the type 
    // of its operand. The compiler analyzes the expression to determine its type
    // but does not evaluate the expression:

    // here the base type of sum is based on the return type of the function
    // f.  After determining the base type, sum is then intialized to have the 
    // same value as x, if this is possible.
    // decltype(f()) sum = x;

    // decltype behaves differently from auto when it comes to handling top-level const
    // when the expression to which decltype is applied to is a variable, decltype
    // returns the same type of that variable, including top-level const and references

    const int ci = 0, &cj = ci; 
    decltype(ci) x = 0; // x is a const int with value 0
    decltype(cj) y = x; // y is a reference to const int, therefore just binds to x
    // decltype(cj) z; // error, references have to be initialized at definition 
    
    // note that decltype() is the ONLY scenario in which the type of a reference is used
    // instead of the object to which it is bound

    // decltype of an expression can be a reference type
    int i = 42, *p = &i, &r = i;

    decltype(r + 0) b; // yields an int
    decltype(*p) c; 

    return 0;
}