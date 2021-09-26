#include <iostream>
#include <string>
#include <vector> 

using std::vector;
using std::string;

// variable to store which exercise to run
#define OPTION 2

int main() {
    // a vector is a class template. C++ has both class and function templates. 
    // a template itself is not a function or class. Instead they can be thought of
    // as instructions to the compiler for generating classes or functions
    // the process that the compiler uses to create a class or function from 
    // and the process of a compiler following the instructions of a template
    
    // in order to use a template -> ie specify the instructinos that the ocmpiler 
    // should follow to instantiate a class or function, a user needs to provide some information
    // and this information that a user needs to supply is based on the nature of the template

    // in the case of a vector class template, the additional information that is needed
    // to instantiate a vector type object is the type of the object that will be stored 
    // in the vector. To supply this additional information, the information proceedes 
    // the name of the template, and inside angled brackets is the information required
    // to tell the compiler how to instantiate a vector object e.g. 

    // vector<int> ivec; // creates a vector object that contains int type elements
    vector<vector<string> > file; // vector that holds objects of type vector

    // in the above scenarios, the compiler generates 2 distinct types from the 
    // vector template: vector<int>, vector<vector<string>>

    // note that vector is a TEMPLATE, not a type!, types are generated from the 
    // vector class template e.g. vector<int> is a type, but vector is not.

    // can define vectors to hold objects of most any type - apart from references since 
    // these are not objects

    // as with any class type, the vector template controls how to define and initialize
    // vectors

    // ways to initialize a vector:
    vector<int> v1; // default initialization, v1 is empty
    vector<int> v2(v1); // v2 has a copy of each element in v1, v1 and v2 vectors must be of the 
                        // same type
    vector<int> v3(10, 5); // v3 is a vector that has 10 copies of the value 5
    vector<int> v4(10); // v4 has n copies of a value-initialized object
    vector<int> v5{5, 4, 3}; // v5 has as many elements as there are intializers
    // vector<int> v6 = {5, 4, 3}; // v6 and v5 are equivalent <- this is a c++ 11 feture
                                // this is list initialization

    vector<string> articles = {"a", "an", "the"}; // list intialize a string vector whose elements are strings

    // can use range-for statement provided by c++11

    for (auto var : articles) {
        std::cout << var << std::endl; 
    }

    // note again that when there is a requirement to have more than one intializer
    // e.g. in the following example, there are two initializers, so must use a direct 
    // form of initialisation rather than copy initialization
    // direct form of initialisation is vector<int> var{...}, copy initialization is 
    // vector<int> var() or vector<int> var = 
    // cannot provide a list of initializers using parenthesis e.g. vector<int> v6(5,10,22.. )
    

    // if only supply a size, to a vector when intializing, the library creates a
    // value intialized element initializer for us. The library-generated value
    // is used to initialize each element in the container, the value of the element
    // initializer depends on the type of the elements store in the vector.

    // if the vector holds elements of built-in type, e.g. int, then the element initializer
    // has a value of 0. if the elements are of class type, such as string, then the element
    // initializer is itself default intialized

    vector<int> ivec(10); // ten elements, each initialized to 0

    // when use parentheses, are saying that the values supplied to the parentheses are to be used
    // to construct the object. when curly braces are used, are saying that if possible, want to list 
    // initialize the object. that is, if there is a way to sue the values inside the curly braces as 
    // a list of element initializers, the class will do so. ONLY if it is not possible to list 
    // initialize the object will the other ways to intialize the object be considered.

    // in other words, parentheses are for construction, whereas braces are for list initialization, 
    // but, if the elements in a list cannot be used for list initialization, they will be used to try 
    // and construct an object
    

    vector<string> v6{"hi"}; // creates a vector with one element: the string "hi"
    // vector<string> v7("hi"); // error, cannot construct vector of strings from string "hi"
    vector<string> v8{10}; // fails to list initialize, so construct a vector with 10 element intializers
    vector<string> v9{10, "hi"}; // fails to list initialize, so construct a vector with 10 copies of the 
    // string "hi"

    // for the above; in order to list intialize, the values inside the braces must match the element 
    // type

    // direct initializing a vector only really makes sense if the number of elements for list initialization
    // is small, or are copying one vector to another, or are wanting to initialize a vector with the same value
    // for all elements. In the case of creating a vector of the first n integers, when n is large, doing so 
    // with list initialization would be cumbersome
    // it is better to create an empty vector and then intialize it with a for loop, using the push_back member
    // function to add elements are run time. the push back operation takes a value and "pushes" that value as
    // the new last element onto the "back" of the vector. For example:

    vector<int> v10;

    for (int i = 0; i <= 100; ++i) {
        v10.push_back(5); // append 5 onto the end of the vector
    } 

    // at the end of the loop v10 will have 100 elements, with values from 0 to 100

    // example to grow a vector with strings read from standard input

    string helper; 
    vector<string> some_strings;

    while (std::cin >> helper) {
        // append the string that has been read from standard input onto the back of the vector
        some_strings.push_back(helper); 
    }

    // key concept: vectorS grow efficiently

    // the standard requires that vector implementations can efficiently add elements at run time. 
    // because vectors grow efficiently, it is often unnecessary - and can result in poorer performance
    // to define a vector of a specific size. The exception to this rule is if all the elements actually
    // need the same value. if differing element vaues are needed. It is usually more efficient to define
    // an empty vector and add elements as the values we need become known at run time. This behaviour is 
    // different from how java or C behave. 
    // WARNING: Note also that cannot use a range for if the statement to be 
    // applied to each element of the vector causes the vector to change in size
    // TLDR - it is better to create an empty vector, and grow it at run time, rather than 
    // creating a vector of specific size and adding elements to that - this is contrary to the behaviour of 
    // languages such as C or Java


    // exercises 

    if (OPTION == 1) { 
        // read a sequence of ints from cin and store those values in a vector
        int temp;
        vector<int> int_vec;

        while (std::cin >> temp) {
            // store ints in vector
            int_vec.push_back(temp);
        }

        // output the ints we just read using a range for 

        for (auto temp_int : int_vec) {
            std::cout << temp_int << std::endl; 
        }

    } else if (OPTION == 2) {
        // read a sequence of strings and store those values in a vector
        string temp_str;
        vector<string> str_vec;

        while (std::cin >> temp_str) {
            str_vec.push_back(temp_str); 
        }

        // output the strings we just read using a range for 
        for (auto out_str : str_vec) {
            std::cout << out_str << std::endl; 
        }

    
    }

    // vector member functions;
    // v.empty() returns a bool
    // v.size() returns an object of type std::size_t indicating the number of elements in v
    // v.push_back adds an element with value t to end of v
    // v[n] returns a reference of type (same as element type in vector definition)
    // v1 = v2 elements in v2 are copied into v1, must have the same element type
    // v1 = {a, b, c} assignment, replace the elements in v1 with a copy of the elements in the list
    // v1 == v2 are equal if they have the same number of elements and each element is equal
    // comparison operators e.g. <, <=, >, >=
    // note that to access the operations that can be performed on a vecotr v of type int
    // must do vector<int>:: rather than vector:: since vector is a template rather than a class
    // also, best to index a vector using the corresponding vector<type>::size_type type
    // the subscript operator on a vector and string only fetches an existing element, 
    // it cannot be used to add an element
    return 0;
}