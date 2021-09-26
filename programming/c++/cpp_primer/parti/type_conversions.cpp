#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl; 
using std::string;
using std::vector; 

int main() {

    // in c++ some types are related to each other. When two types are related,
    // can use an object or value of one type where an operand of the related type
    // is expected.
    // two types are related if there is a conversion between them

    // implicit conversions
    // 3.541 is of type double, 3 of type int, 3 is automatically 
    // converted to double so that both operands to + are of a common type
    // the implicit conversions among the arithmetic types are defined
    // to preserve precision, if possible. 

    // When implicit conversions occur: 
    // - values of integral types smaller than int are first promoted to 
    // an appropriate larger integral type
    // - in conditions, non bool expressions are converted to bool
    // - in initializations and assignments, the intializer/ right hand operand
    // is converted to the type of the left hand operand 
    // - in arithmetic and relational expressions with operands of mixed types
    // the types are converted to a common type. typically they are converted to 
    // a common type that is widest

    int ival = 3.541 + 3; 

    // other implicit conversiosn are array to pointer 
    // e.g:
    // any re
    int a1[2][5] = {
        {1, 2, 3, 4, 5}
        ,{2, 3, 4, 5, 6}
        };
    
    for (auto &i : a1) {
        for (auto &j : i) { 
            cout << j << endl; 
        }
    }

    for (auto i = std::begin(a1); i != std::end(a1); ++i) {
        for (auto j = std::begin(*i); j != std::end(*i); ++j) {
            cout << *j << endl; 
        }
    }


    // Explicit conversions
    // a named cast has the following form:
    // cast_name <type> (expression);
    // type is the target type of the conversion. expression is the value 
    // to be cast. If type is a reference, then the result is an lvalue
    // since references are bound to objects
    // cast_name may be one of static_cast, dynamic_cast, const_cast
    // and reinterpret_cast
    
    
    // static_cast - for any well-defined type conversion - other than those
    // involving low level const e.g. const int a
    // example:
    int i1 = 5, j1 = 4; 
    double a2 = static_cast<double>(i1) / j1;

    // can use a static_cast to obtain the value of a pointer that is stored
    // in void*
    // for example 
    void* p1 = &i1; 
    // retrieve int
    int * ptr = static_cast<int*>(p1);
    
    // write to stdout 
    cout << *cptr << endl;


    // const_cast -> changes only the level const of an object, cannot
    // change the base type of an object
    // only const_cast can be used to change the constness of an expression
    // that is, cannot use static_cast, dynamic_cast etc 
    // can be used to convert from nonconst to const, and const to nonconst
    // in the latter case, using a const_cast to write to a const object
    // is undefined since the compiler will let us write at the objects memory
    // location
    const char c1{'a'};
    const char *const_p = &c1;
    char *nonconst_p = const_cast<char*>(const_p); 
    
    // using nonconst_p to write at the memory location of c1 is undefined e.g.
    // *nonconst_p = "K"; is undefined

    // reinterpret_cast -> performs a low level reinterpretation of the bit 
    // pattern of its operands. For example can use a reinterpret_cast 
    // to cast a char to an int:
    int *ip;
    char *pc = reinterpret_cast<*char>ip;
    // any subsequent use of pc will assume that it is a char* 
    // this can result in run time failures - since at the memory location
    // of *ip is actually an int rather than a char. For this reason,
    // reinterpret_cast is not recommended. 

    // old  C style casts e.g.g type () or (type) () when in use
    // correspond to one of the explicit casts


    return 1;
}