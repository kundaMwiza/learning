#include <iostream>
#include <string>
#include <vector>

#include "abstract_data_types.h"

using namespace std;

int main(int argc, const char *argv[]) {

    salesData total; 

    if (read(cin, total)) {
        saledsData trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans); // update the running total
            }
            else {
                print(cout, total) << endl; // print the result
                total = trans
            }
        }

        print(cout, total) << endl; 
    } 
    else {
        cerr << "No data?!" << endl; 
    }



    return 0;
}