#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout; 
using std::endl; 
using std::string;
using std::vector; 

int main() {
    

    // note that arrays and pointers are directly linked
    // so that for an array a e.g. int a[] = {1, 2, 3}; ,
    // the identifier a is a pointer to the first element of the array
    // when we specify a[1], this is the same as advancign the pointer 
    // a by 1 e.g. *(a + 1), which gives the memory location of the next 
    // integer, dereferencing returns the integer at that location
    // similarly, for multidimensional arrays, which are jsut arrays of arrays
    // are simply arrays of pointers, where e.g. a[1][2] corresponds to *(*(a + 1) + 2)
    // (a + 1) gives the memory location of the second pointer in the array, 
    // dereferencing gives the value at that memory location, which is apointer to an int
    // advancing that pointer by 2 * sizeof(int) gives the memory location of an integer
    // dereferencing gives the integer value

    // it is best to initialize a multidimensional arrays using nested brackets e.g. 
    int ia[3][4] = {
        {1, 2, 3, 4} 
        ,{5, 6, 7 , 8}
        ,{9, 10, 11, 12}
    }; 

    // missing out some elements leads to them being value initialized
    // e.g. the last value in each row is zero
    int ia2[3][4] = {
        {1, 2, 4} 
        ,{5, 7 , 8}
        ,{9, 11, 12}
    }; 

    // creating references or pointers to arrays - without specifying all indices:


    int (&int_ref)[4] = ia[0]; // create a reference to the first row of ia

    for (int &i : int_ref) { 
        cout << i << endl; 
    }

    // note that can also use a range for in the new standard to iterate over a multidimensioal 
    // array rather than using bounds for rows/ cols e.t.c 
    // when iterating over multidimensional arrays, it is best to set iterators to be references
    // to prevent the typical pointer-array conversion that takes place
    for (auto &i : ia) {
        for (auto &j: i) {
            cout << j << endl; 
        }
    }

    // for example, writing the loop below is illegal since
    // the sequence ia is an array of array, so each iterator should be 
    // an array. but the compiler convertes each array to a pointer to the
    // first element of its array. e.g. int * - which is not a sequence type
    // and as a result the second loop cannot be evaluated.
    // for (auto i : ia) {
    //     for (auto j : i) {
    //         cout << j << endl; 
    //     }
    // }
    
    // note that much in the same way that an array is just a pointer to 
    // its first element e.g. int a[] = {1, 2}; , a here is just int * a = &1; 
    // that is, the memory location of first integer in the array

    // so for a multidimensional array e.g. ia, ia is a pointer to a an array. that is, its value 
    // is the memory location of the first array.  
    return 0;
}