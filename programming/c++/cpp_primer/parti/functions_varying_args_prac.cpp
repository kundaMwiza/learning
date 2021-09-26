#include <iostream>
#include <initializer_list>

using namespace std;


long int sum_ints(initializer_list<int>); 

int main() {


    // sum of elements 1 through 10
    cout << "The sum of integers 1 through 10 is: \n"
         << sum_ints({1, 2, 3, 4, 5, 6, 7, 8, 9 , 10})
         << endl; 
    

    return 0; 


}

long int sum_ints(initializer_list<int> int_list) {

    long int output = 0; 

    // can either use iterators to loop over int_list list
    // or range for with the new standard

    for (auto &int_elem : int_list) {

        output += int_elem; 
    }

    return output;
}