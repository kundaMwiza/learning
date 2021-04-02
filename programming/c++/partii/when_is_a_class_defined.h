#ifndef CLASSDEFINITION 
#define CLASSDEFINITION 1 

// a class is considered declared when the class name is visible to the compiler 
// so the following class SomeClass; declares the class SomeClass.
// however, because the compiler needs to know the definition of the class
// it is illegal to use class instances, and member functions

// for a class to be defined, the class body needs to be parsed completely. 
// because of this, it is not legal to declare objects of the class within 
// the class e.g. below, SomeClass a; where a is an object ot type SomeClass
// because SomeClass, at the point of declaration of a, is not defined.
// since the class is declared however, it is possible to create pointers or 
// references to such class types. It is not legal to directly 
// access members of the class through pointers and references before the class 
// is defined. However, it is possible to use class based operations e.g. accessing 
// data members wihin a class through a pointer, since when the compiler 
// parses a class definition, declarations of functions are firstly resolved
// and then function definitions are resolved.
class SomeClass {
    // simpler type specifier
    // equivalent to friend class SomeClass
    // friend SomeClass; 
    // for overloaded function, there must be a declaration 
    // for each of the overloaded functions that want to be 
    // friends - overloaded functions are different functions
    // even if they share the same name

    public:

    private:
        // from above, the class SomeClass has been declared
        // can create pointers or references to such a class type
        // but cannot create plain objects of SomeClass since don't 
        // know how much memory to allocate.
        SomeClass * first;
        SomeClass * second;

        // ordinarily, when a program uses a name, the compiler 
        // will first look in the scope that used the name
        // if the name is not found, the compiler looks in enclosing scopes
        // if it is not found in those scopes, an error is raised

        // however there is some subtlety when it comes to compiling classes
        // The compiler processes a class in two steps, rather than in the above outlined way:
        // -- first the member declarations are compiled
        // -- function bodies are compiled only after the entire class has been seen
        // so whilst it is illegal to directly use e.g. first->some_data_member directly
        // directly within the class (that is, not in a member function), it is fine to do 
        // so within a member function, since at the point of compiling the function
        // the entirety of the class has been seen, so the compiler knows which 
        // data members and member functions are present within the class

        // classes are processed in this two phase way to make it easier to 
        // organize class code.
        // if classes were not processed in this way, would have to order 
        // member functions in the class in such a way that they can only 
        // use members in the class that are visible to the compiler up until 
        // that point

        // this two phase processing advantage of classes only applies to member functions
        // return types and parameter types (since these are compiled in the first stage) 
        // need to be visible to the compiler within the class, else the compiler 
        // will look in enclosing scopes

        // to access values defined in the outer scope, use the scope operator
        // ::some_var in the outer scope -> the presence of no name before some_var
        // indicates that we are looking in the global scope
};

// making a member function a friend requires careful structuring consideratio for 
// a program to accommodated interdependencies among the declartions of a program 
// e.g. assuming there are two classes Screen and WindowMgr, where WindowMgr 
// has a member function that requires access to private members of Screen.
// when developing, Must define WindowMgr first, and then declare, but not define 
// the member function that requires access to the private members of Screen.
// then defien Screen, listing the member function of WindowMgr that requiers to be 
// a friend
// then define the member function of WindowMgr that needs access to the private members 
// of Screen
#endif