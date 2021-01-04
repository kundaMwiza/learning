#include <iostream>
#include <vector>
#include <string>

using std::string; 
using std::vector; 
using std::cin; 
using std::cout;

#define OPTION 2

int main() {

    // exercise to read in a series of words, convert them to upper 
    // and write them back to standard output
    if (OPTION == 1) {
        string temp_word;
        vector<string> words; 

        while (cin >> temp_word) {
            for (auto &temp_char : temp_word) {
                temp_char = toupper(temp_char);
            }
            words.push_back(temp_word);

        }

        for (auto temp_str : words) {
            cout << temp_str << std::endl; 
        }

    } 
    
    // exercise to read in a series on integers, and compute various sums
    else if (OPTION == 2) {
        int temp_int;
        vector<int> int_vec; 

        while (cin >> temp_int) {
            int_vec.push_back(temp_int); 
        }

        // print each pair of adjacent elements

        for (vector<int>::size_type i = 0; i < int_vec.size(); ++i) {
            cout << "Sum of adjacent elements " << i << " and " << i + 1 
            << " is " << int_vec[i] + int_vec[i + 1] << std::endl; 
        }

        // print the first and last elements
        // must have atleast two elements
        if (int_vec.size() >= 2) {
            cout << "the sum of the first and last elements is " << 
            int_vec[0] + int_vec[int_vec.size()] << std::endl;  
        } 

        // print the sum of i and -i 
        vector<int>::size_type vec_size = int_vec.size(); 

        if (int_vec.size() >= 2) {
            for (vector<int>::size_type i = 0; i <= vec_size / 2; ++i) {
                cout << "the sum of index " << i << " and index " << vec_size - i <<
                " is "  << int_vec[i] + int_vec[vec_size - i] << std::endl; 
            }
        }
        
    }

    return 0; 
}