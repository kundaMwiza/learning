#include <iostream>

using std::string;
using std::cin; 
using std::cout; 

#define OPTION 6

int main() {

    string line_str; 

    if (OPTION == 1) {
        // read input a line at a time
        while (getline(cin, line_str)) {
            cout << line_str << std::endl; 
        }
    }



    if (OPTION == 2) {

        // program to read two strings and report whether the 
        // strings are equal
        string s1, s2; 

        cin >> s1 >> s2; 

        // test if the strings are equal
        bool str_equal = s1 == s2; 
        cout << "are the strings equal? " << str_equal << std::endl; 
    
        // if not equal report which one is larger
        if (!str_equal) {
            if (s1.size() < s2.size()) {
                cout << "the larger string is " << s1 << std::endl;  
            } else if (s1.size() > s2.size()) {
                cout << "the larger string is " << s2 << std::endl; 
            }
            else {
                cout << "both strings have the same length " << std::endl; 
            }
        }
    } 
    
    else if (OPTION == 3) {

        string s1, s2; 

        cin >> s1 >> s2; 

        // report where the strings have the same length
        if (s1.size() < s2.size()) {
            cout << "The following string is larger: " << s2 <<  std::endl; 
        } else if (s1.size() > s2.size()) {
            cout << "The following string is larger: " << s1 << std::endl;
        } else {
            cout << "The strings have the same length" << std::endl; 
        }

    } 

    else if (OPTION == 4) {
        string temp_str, large_str; 

        while (getline(cin, temp_str)) {
            large_str += " " + temp_str;
        }

        cout << "the concatenated string is: " << large_str << std::endl; 
    } else if (OPTION == 5) {
        string temp_str, large_str;

        while (cin >> temp_str) {
            large_str += " " + temp_str ;
        }

        cout << "the concatenated string is: " << large_str << std::endl;

    }

    string k(10, 'l');
    cout << k << std::endl;  

    



    return 0;
}