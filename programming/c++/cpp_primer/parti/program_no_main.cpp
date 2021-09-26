#include <iostream>

int i = 100, sum = 0; 
int  main () {
    for (int i = 0; i != 10; ++i) {
        sum += i;
    }   
    std::cout << i << " " << sum << std::endl; 
    return 0;
}

