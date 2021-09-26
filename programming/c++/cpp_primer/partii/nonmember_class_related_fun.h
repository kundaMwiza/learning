#ifndef NONMEMBER
#define NONMEMBER 1

#include <iostream>

struct someStruct{

    int val_one = 0;
    float val_two = 0.0;


};

// declare a related function, that is not 
// specific to the class above
// this will be defined elsewhere 
// read_int is similar to >> and << which return their 
// left hand operands
// this function would therefore be defined in a source file
// we would include the declaration of this function 
// in that source file, and any other source file using that function
std::istream &read_int(std::istream &input_stream, someStruct &instance);
// one thing to note about the istream and ostream types is that 
// they cannot be copied, which means that they must be passed by 
// reference. and secondly, reading or writing to streams
// changes the streams, so the references cannot const

// functions that are conceptually related to a class
// but are not part of a class are usually declared within the 
// same header file that defines the class 
// however, if the class uses a function that is not related
// the header file for the functions declaration need to be included
// As usual for functions that do not belong to a class
// their declaration has to be separate from their definition
// the declaration must be placed in a header file, whilst the definition 
// in a source file



#endif 
