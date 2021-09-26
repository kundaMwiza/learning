#include <vector>
#include <list>

int main(int argc, const char * argv[]) {

    std::vector<int> vecA = {1,2,3};

    // six ways to create and initialise a vector

    //  copy list initialisaiton
    std::vector<int> vecB = {1, 2, 3};
    // copy initialisation from another vector with teh same element types
    std::vector<int> vecC = vecB;
    // direct list initialisation 
    std::vector<int> vecD{1,2,3}; 

    // copy initialisation from another vector 
    // creates a new vector that has the same size and values as vecA
    std::vector<int> vecE(vecA);

    // using iterators
    std::vector<int> vevF(vecA.begin(), vecA.end());

    // specifying a size and optional initializer
    std::vector<int> vecG(10, 5);

    // default construction - empty 
    std::vector<int> vecH; 

    // illegal to copy when container types and or element types differ
    // but can be fine if the types are convertible itrators are used 
    std::vector<float> vecI{1.0, 2.0}; 

    // the below works since floats can be truncated to ints..
    std::vector<int> vecJ(vecI.begin(), vecI.end()); 



    return 0; 
}