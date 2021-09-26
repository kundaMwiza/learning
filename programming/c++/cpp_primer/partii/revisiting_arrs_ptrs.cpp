#include <iostream>
#include <vector>
#include <random>

int main(int argc, const char *argv[])
{

    // important points to note for arrays and pointers

    // 1. arrays of type T are decayed into pointers of type T
    // when they used as lvalues. They can only be decayed once!
    // for example, a 2 dimensional array T arr[m][k] when
    // passed as an lvalue will decay into T (*arr)[k], a pointer
    // to an array of type T
    // 2. arrays of type T are not converted into pointers of type T
    // in certain scenarios, e.g. using th sizeof operator,
    // binding references to arrays etc

    // illustrating case 1
    int arr[5] = {1, 2, 3};
    int arr2[5][4] = {
        {1, 2, 3, 4},
        {2, 3, 4, 5}};

    // here arr is converted to a pointer to an int (int *)
    std::cout << "the value of arr = " << arr << std::endl;
    // here arr2 is converted to a pointer to an array of 4 integers  (int (*)[4])
    std::cout << "the value of arr2 = " << arr2 << std::endl;

    // illustrating case 2

    // since elem is a reference type, arr is not decayed to a pointer
    // in particular, that allows the range for to access the elements in the array
    std::cout << "output for case 2, one dimensional array" << std::endl;
    for (auto &elem : arr)
    {

        std::cout << elem << std::endl;
    }

    // in this case, we bind each row to row_arr
    // for each row_arr, we bind a reference to each element
    // if we had omitted the references, the arrays would have decayed
    // into pointers, and cannot use range for with pointers, only sequency types
    std::cout << "output for case 2, two dimensional array" << std::endl;
    for (auto &row_arr : arr2)
    {
        for (auto &elem : row_arr)
        {
            std::cout << elem << std::endl;
        }
    }

    return 0;
}
