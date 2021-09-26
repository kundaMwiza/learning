#ifndef IMPLICITCAST
#define IMPLICITCAST 1


// #includes go here - esp for functions defined elsewhere


// classes can define implicit conversions as well 
// similar to how automatic conversions can occur between arithmetic types

// -- converting constructors
// a constructor that can be called with a single argument defines an implicit
// conversion from the constructors parameter type to the class type (that is,
// the name of the class that houses the specific constructor
class IllustratorClass
{
    
    
    // friends and mutateable objects go here
    public:

        // constructors and their declarations go here

        // define the default constructor 
        // though not needed for this class as we have used 
        // a delegate construtor when the user does not provide arguments
        // IllustratorClass() = default;

        // custom constructor to initialise a class instance
        IllustratorClass(int arg1, int arg2) 
            : imem_one(arg1), imem_two(arg2) { }

        // delegate constructor - our default constructor
        // if no args supplied by user, initialize data members 
        // with zeros
        IllustratorClass() 
            : IllustratorClass(0, 0) { }

        // example 1 of a converting constructor taking only one argument
        // using a delegate constructor to initialise 
        // two private data members with the same argument
        IllustratorClass(int arg1) 
            : IllustratorClass(arg1, arg1) { }

        // another example of a converting constructor
        // this constructor can receive inputs of type int
        // but can be implictly converted to type IllustratorClass
        IllustratorClass(int arg1); 


        // define a member function to be used to modify member one
        // using another class instance's member one value
        // this function can take as input an integer, since 
        // the class has converting constructors (constructors that 
        // can take one argument and execute)
        // when the integer is passed as input, the compiler creates a 
        // temporary instance of IllustratorClass, using one of the 
        // converting constructors, that temporary is then passed 
        // as the argument to inst_two. This works in this case since 
        // inst_two is a reference to const: const references can take 'literals' 
        // as input, since temporaries are created.
        // this behaviour is similar to passing a string to a 
        // const string&
        // if the paramter type was a plain IllustratorClass (copy, not reference)
        // this would also work
        // when using converting constructors, only one class-type conversion is allowed
        // for example change_member_one(9.5f) is an error 
        // because there is firstly an implicit conversion via truncation of the float 
        // to an integer, and then the integer is implictly converted to IllustratorClass type
        // the workaround to this is to ensure there is only one implicit conversion
        // change_member_one(int(9.5f)) -> explicit conversion to int, implicit conversion to IllustratorClass 
        // change_member_one(IllustratorClass(9.5f)) -> implicit conversion to int, explicit conversion to IllustratorClass
        int change_member_one(const IllustratorClass &inst_two) {

            imem_one += inst_two.imem_one; 

            return imem_one; 
        }

        
    private:

        // typically class data members will go here

        int imem_one;
        int imem_two;


};

// to prevent users from using converting constructors
// the c++ keyword explicit can be used 
// to specify which constructors may not be used for implicit 
// converstions

class ExplicitKeyword {

    public:

        ExplicitKeyword(int arg1, int arg2)
            : imem_one(arg1), imem_two(arg2) {}

        // the below constructors are examples of 
        // converting constructors
        // the keyword explicit prevents the constructors 
        // being used with implicit conversions

        // the explicit keyword is only allowed on constructor 
        // declarations within a class, it is not valid on 
        // constructors defined outside the class

        // one thing to onte when using the explicit keyword 
        // to declare to the compiler which constructors cannot 
        // be used with implicit conversion is that such constructors
        // can only be used with direct initialization:
        // that is ExplicitKeyword item(arg);
        // they cannot be used with copy initialization:
        // ExplicitKeyword item = arg;
        // since this kind of initialization will require that the RHS
        // is implicitly converted to an object of type ExplicitKeyword
        // in other words, a converting constructor will be needed in order 
        // to create an ExplicitKeyword object, which can then be assigned to the LHS
        explicit ExplicitKeyword(int arg1) 
            : ExplicitKeyword(arg1, arg1) {}

        explicit ExplicitKeyword()
            : ExplicitKeyword(0, 0) {}

        // library classes with explicit constructors   
        // single parameter constructors
        // string constructor that takes a single parameter of type const char *
        // vector constructor that takes a size argument is explicit


        // now it is no longer possible to pass an integer 
        // to the following member function given the above 
        // constructors since all the converting constructors 
        // are now explicit rather than implicit
        // that is change_member_one(5) will not compile 
        // for this class
        int change_member_one(const ExplicitKeyword &inst) {

            imem_one += inst.imem_one; 

            return imem_one;
        }

    private:

        int imem_one;
        int imem_two;

}; 


#endif