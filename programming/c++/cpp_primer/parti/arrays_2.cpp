#include <iostream>
#include <vector>

using std::vector;
using std::endl; 
using std::cin; 
using std::cout; 

int main() {

    // arrays hold objects, so cannot have references inside an array

    // character arrays -> additional form of initialization
    // can initialize a character array from a string literal -> 
    // but it is important to remember than when using this form of initialization
    // extra space should be allocated for the null character that terminates the string
    char a1[] = {'C', '+', '+'}; // no null character needed since list initializing from characters
    char a2[] = {'C', '+', '+', '\0'}; // explicit null
    char a3[] = "C++"; // actually allocated memory for four characters including the null char
    

    // cannot initalize an array as a copy of another array e.g. 
    int a4[] = {'l', 'a'}; 
    // int a5[] = a4; // this would result in error

    // arrays can hold objects almost of any type
    // because arrays are objects, can define pointers and references to arrays
    // with parenthesis it is easier to say that the modification within parathenses
    //  only apply to the identifier in the parenthesis. So for example int (*parray)[10] 
    // creates a pointer named parray, that points to a an array of 10 ints. Whereas int *parray[10]; 
    // the modifier * applies to everything on the left, that is, an array of dimension 10 is created with 
    // the name parray, and all elements of the array are pointers which point to int
    int *ptrs[10]; // default initialize an array of 10 pointers to int
    int *(*some_ptr)[10] = &ptrs; // create a pointer to an array of 10 pointers to int 

    // NOTE that can only initialize an array from a const size 

    // like the vectory and string types, can use a range for or the subscript operator to 
    // acess elements of an array
    // note that the operator to subscript is also defined as part of the array type, just like 
    // the iterators and [] operators are defined by the string and vector types

    // when using a variable to subscript an array, should normally define the type to have type size_t. 
    // size_t is a machine specific unsigned type that is guaranteed to be large enough to hold 
    // the size of any object in memory.
    // size_t type is defiend inside the cstddef header, which the C++ version of the stddef.h header from C
    
    // when traversing an array, it is best to use a range for, since the dimension of the array is 
    // defined as part of the array, range for will know when to stop traversing the array
    auto begin_iterator = std::begin(a1);
    auto end_iterator = std::end(a1); 

    for (begin_iterator; begin_iterator != end_iterator; ++begin_iterator) {
        cout << *begin_iterator  << endl; 
    }

    // some exercises with arrays
    const int arr_size = 10;
    int ten_arr[arr_size]; 
    int sten_arr[arr_size];
    
    // assign each element the value of its index
    for (size_t i = 0; i <= arr_size; ++i) {
        ten_arr[i] = i;
    }

    for (int &i : ten_arr) {
        sten_arr[i] = i;
    }

    // using vectors
    vector<int> vten_arr(10, 0);
    vector<int> svten_arr(10, 0); 

    for (vector<int>::size_type vind; vind <= arr_size; ++vind) {
        vten_arr[vind] = vind; 
    } 

    // copy the first vector into the second vector
    svten_arr = vten_arr; 





    return 0;
}