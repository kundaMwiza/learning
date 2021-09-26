#ifndef CONSTRUCTOR
#define CONSTRUCTOR 1

// each class defines how objects of its type can be initialized
// classes control object initialization by defining one or 
// more special member functions known as 'constructors'
struct salesData{
    // the job of a contructor is to initialize the data members e.g. int x
    // rather than member functions of a class object
    // the contructor is run whenever an object of a class type is created
    // (this is similar to __init__ in python)

    // constructors have the same name as the class, unlike other 
    // functions (member or non member) functions, constructors have:
    // no return type
    // a possible empty parameter list 
    // a possible empty function body
    // constructors can also be overloaded just as normal functions
    // i.e the parameter list be of either different length, or have different types
    // unlike other member functions, constructors may not be 'const member functions'
    // since, whether an instance of the class is const or not is not assumed 
    // before the instance has been initialised. Only then is the constness of the object
    // important

    // classes that do not have constructors for data members use a synthesized default 
    // constructor. The synthesized constructor intializes each data member of the class
    // via:
    // if there is an in-class initializer, it is used to intiialize the member
    // otherwise, the data member is default initialized, based on the type of 
    // the data member e.g. strings are initialised to the empty string
    // NOTE: a compiler only generates a default constructor automatically only if 
    // a class declares no constructors
    // WARNING: classes that have members of built-in or compound type usually should
    // rely on the synthesized default constructor only if all such members have 
    // in class initializers e.g int x = 0;
    // another reason is if a data member is of a class type that does not 
    // not have a default constructor, in this case the default constructor cannot 
    // initialize the member.

    // other salesData members
    std::string isbn() const {return bookNo;}
    salesData& combine(const salesData&);
    double avg_price() const;
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0; 

    // define four constructors for the salesData class
    // new standard way of defining a synthesized default constructor
    // if the user provides no arguments, units_sold and revenue are 
    // in-class initialized, bookNo is default initialized.
    // below is the new standard way c++11
    salesData() = default;

    // SYNTAX for a general constructor is 
    // class_name(parameter list) : values_init {function body}
    // overloading the class constructor, so users can different ways to 
    // initialise the class 
    // pass only a string to initialise bookNo, for the other data members (units_sold and revenue)
    // the synthesized default constructor will in-class initialise
    salesData(const std::string &s): bookNo(s) {// empty function body} 
    
    // pass all parameters for initialisation
    salesData(const std::string &s, const unsigned usold, const double rev) 
        : bookNo(s), units_sold(usold), revenue(rev) {// empty function body }

    // if for example further data members are required to be intialised,
    // can do that in the function body if the initialisation is more complex

    // note the already established way of initialising a string 
    // std::string some_string("some value") <- construct the string from the input argument
    // this is constructor initialisation, or direct initialisation
    // there is also copy initialisation of a class type

    // declare a member function that will be defined outside the class
    salesData(std::istream &); 


};

salesData::salesData(std::istream &is) 
    // empty constructor initializer list
    // this means that data members are either in-class initialized 
    // if initializer values are provided, or default initialized, if a 
    // synthesized default constructor is defined in the class
    // in this case, revenue and units_sold are in-class initialized
    // bookNo is default initialized to the empty string
    // read below then modifies these values
    // in particular, it is better to have an initialize list when 
    // there are built in types with no in-class initializers..
    : {
        // read(is, *this) some function named read that will read a transaction into the object
    }


#endif 