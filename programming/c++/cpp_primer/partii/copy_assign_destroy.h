#ifndef CADESTROY 
#define CADESTROY 1 

// in addition to defining how objects of the class type are initialized
// classes also control what happens when we copy, assign or destroy objects
// of a class type

// objects can be copied e.g. when intialising a variable or passing 
// an object by value

// objects are assigned when the assignment operator is used

// objects are destroyed when they cease to exist e.g. 
// when a local object is destroyed on exist from the block
// it was created
// for objects storeed in a vector or array, the objects are 
// destroyed when the vector or array is destroyed
// if these operations are not defined, in a similar way to the 
// construction of class data members, using the synthesized default constructor
// the compiler will synthesize operators for assignment, copying and destorying class 
// instances


// for example, copying one class instance into another via
// total = trans; the compiler will perform the following
// total.bookNo = trans.bookNo 
// total.units_sold = trans.units_sold;
// total.revenue = trans.revenue;

// however it is possible to define our own operators for assignment
// ,copying and destroying class instances
// and this is required for some classes. For example defining a data member 
// as const var;
// means that it is illegal to copy one instance's data member into another
// and also, classes that manage dynamic memory cannot generally rely 
// on synthesized versions provided by the compiler
// though, using the vector template, or string - the syntheiszed versoins 
// for copy assignment and destruction work correctly, sincethe 
// vector class takes care of copying or assigning the elements in the member
// if memory is managed dynamically inside a class, operations should be defined 
// for copy, assignment and destruction of class data members, or other 
// objects created within the class

#endif 
