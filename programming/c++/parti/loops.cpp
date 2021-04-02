#include <iostream>

int main() {
    
    // define some initial variables
    int curr_val, cnt, n_iter, val;
    cnt = 1;
    curr_val = 0;

    // ask the user how many inputs they will be entering
    std::cin >> n_iter; 

    for (int i = 1; i <= n_iter; ++i) {
        // user sends input
        std::cin >> val;
        if (val == curr_val) {
            ++cnt; 
        } 
        else { 
            std::cout << "the value " << curr_val << " occurs " << cnt << " times." << std::endl;
            curr_val = val; 
            cnt = 1;
        }
    }

    return 0;
}