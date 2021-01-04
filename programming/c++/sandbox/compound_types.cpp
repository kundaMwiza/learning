#include <iostream>

int main() {
    int ival = 1024;
    int &refVal = ival; 
    // once a reference is initialized, there is no way 
    // of rebinding the reference to a different object.
    // a reference is bound to its initializer, so a reference
    // can only be defined if a variable it is referencing has been
    // initialized, in other words, you cannot define a reference without
    // an initial value
    // int &refVal2; error a referrence must be initialized

    std::cout << refVal << std::endl; 

    // after we assign a reference. all operations on that reference are 
    // operatios on the object to which the reference is bound
    // e.g.  below changes ival to be 5 * ival
    refVal *= 5;

    std::cout << refVal << std::endl; 

    // references must have the same type as the objects they are 
    // bound to
    // also cannot bind a reference to a literal, or a more general expression
    // e.g. a reference to the output of a function

    // some trials
    int i = 0, &r1 =i; double d = 0, &r2 = d;
    r2 = 3.141; 
    r2 = r1;
    i = r2;
    r1 = d; 

    // a pointer is a compound type that points to another type. like references
    // pointers are used for indirect access to other objects. unlike a reference
    // however, a pointer is an object in its own right. pointers can be assigned and copied
    // a single pointer can point to several different objects over its lifetime. 
    // a pointer need not be initialized at the time its defined, however like other 
    // built in types, pointers defined at block scope have undefined value if they are
    // not initialized
    
    double mike = 234.33;
    double * p = &mike; 

    // bar two cases, in general the type of a pointer must be the same as the type
    // of the object it points to
    // criteria of the value of a pointer:
    // 1. it can point to an object
    // 2. it can point to the location just immediately past the end of an object
    // 3. it can be a null pointer, meaning that it is not bound to any object
    // 4. it can be invalid, values other than the first three are invalid
    // note that accessing the value of a pointer in cases 2 and 3 is problematic 
    // since we are not accessing the value of an intended object


    // pointer dereferencing
    *p = 2333.44; 
    std::cout << *p << std::endl; 

    // note that in base_type *p, base_type &p, & and * are type modifiers, instead of creating variables
    // of type base_type, they create variables are related to the base type. *p is a pointer
    // an object of type base_type. &p is reference to an object of type base_type
    
    // pointer to pointer example
    int some_int = 0;
    int *first = &some_int; 
    int **second = &first;
    int ***third = &second; 

    // first dereference gives me the value at memory location &second, 
    // which is &first
    std::cout << "the first dereference " << *(third) << std::endl;
    // second dereference gives me the value at memory location &first
    // which is &some_int
    std::cout << "the second dereference " << **(third) << std::endl;
    // third dereference gives the value at memory location &some_int
    // which is 0
    std::cout << "the third dereference " << ***(third) << std::endl; 

    // since references are not objects, you cannot have pointers to references
    // however, since pointers are objects, references can be bound to pointers
    // using the above pointer (third) as an example
    // below we create a reference r2 to the three star pointer third
    int ***&r3 = third; 

    // an example of changing the value of a variable through a reference to a 
    // pointer to that particular variable
    int example_int = 42;
    int *ptr_1, *&r4 = ptr_1;
    r4 = &example_int;
    *r4 = 0; // expect that example_int = 0 now

    std::cout << "the value of example_int is " << example_int << std::endl;
    

    
    return 0;
}