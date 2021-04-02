#include <fstream>
#include <iostream>
#include <string>

int main (int argc, const char *argv[]) {

    // for file input and output
    // the fstream header defines three types to support IO
    // ifstream (can only read from), ofstream (can only write to)
    // and fstream (can read and write from)
    // in addition to the default methods provided by the iostream 
    // classes, e.g. std::istream::fail()
    // can also use getline to read lines from an fstream object
    // << can be used to write to an fstream object (similar to writing to cout)
    // >> can be used to read from an fstream object (similar to reading from cin)
    // fstream_obj.eof() can also be used to test whether end of file has been reached


    // the fstream header defines additional methods for working with 
    // IO with files 
    
    // declares an unbound fstream object (not bound to any file)
    std::fstream fstream_obj; 
    // creates an fstream object that is bound to the file given by the string
    // can also use a pointer to a c style character string as input
    // the default mode here is read and write
    // this is a c++11 feature, previously had to provde a pointer to a c-style character string
    std::fstream fstream_bobj("./sample.txt");

    // can also do the same as above but also provide the mode
    // std::fstream fstream_obj("./sample.txt", mode)

    // same as the above, but now binds the unbound object to the file 
    fstream_obj.open("./sample.txt");

    // closes the file and returns void
    fstream_obj.close();

    // fstream_obj.is_open(); check if the fstream object was successfully opened but is not closed

    // since we can use objects of an inherited type in places where an 
    // original type is expected e.g. a function requiring a std::istream&
    // can take a std::ifstream&, since std::ifstream inherits from std::istream
    // in particular, functions that take std::istream& can therefore be called 
    // with arguments that are of type std::ifstream& or std::istringstream&

    // when using files for input and output, it is best to test whether 
    // fstream objects have been successfully bound to files 
    // by using if (fstream_object) {... do processing}
    // or if (fstream_object.fail())

    // NOTE when an fstream object is destroyed, close is called automatically
    // in particular, when an fstream object goes out of scope, the file it is 
    // bound to is automatically closed

    // NOTE anytime the open method is called on an fstream object
    // implicitly or explictly, the file mode is set implicitly or explicitly 
    // for example, ofstream_obj.open("path/to/file"), implicitly, the mode
    // ofstream::trunc and ofstream::out are set..

    // WARNING the only way to preserve the existing data in a file opened 
    // by an ofstream is to specify app or in mode explicitly
    // to write at the end of the file, rathre than truncate (i.e remove file contents)
    // e.g std::fstream some_obj("path/to/file.txt", std::ofstream::app);
    return 0;
}