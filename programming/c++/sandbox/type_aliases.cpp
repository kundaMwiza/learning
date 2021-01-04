#include <iostream> 

int main() {


    // a type alias is a name that is a synonym for another type. Type aliases 
    // let us simplify complicated type definitions, making those types easier to use. 
    // type aliases also let us emphasize the purpose for which a type is used
    // can define a type alias in one of two ways; traditionally using typedef:

    typedef double wages; // wages is a synonym for double
    typedef wages base, *p; // base is a synonym for double, p for double *, i.e
    // pointers to doubles

    // c++ 11, the new standard introduced a second way to define a type alias
    // via an alias declaration
    // using SI = sales_item; // SI is a synonym for sales_item
    // starts with the keyword using, specifies the alias name, and assigns
    // the alias name to the type that is being aliased
    using p = double *; // aliases double * 

    // declarations that use type aliases that represent compound types and const can yield
    // surprising results. e.g. consider a using pstring = char *; pstring is an alias to a 
    // pointer to char 
    using pstring = char *; 
    const pstring cstr = 0; // the const keyword modifies the base type, here the base type is
    // pointer to char, so with const, this becomes a constant pointer to char. therefore cstr
    // is of type constant pointer to char, rather than a pointer to a const char
    const pstring *ps; // again here, const modifies the base type in the declaration
    // so that the base type is a constant pointer to char, so ps is a pointer to a 
    // constant pointer that points to a char


    // auto type specifier - allow the compiler to deduce the type of an object at compile time
    // auto tells the compiler to deduce the type from the initializer, by default, 
    // a variable that uses auto as its type specifier must have an initializer
    // e.g. 
    // auto item =  val1 + val2; // item initialized to the result of val1 + val2

    // can also include several declarators along with a base type
    // auto i = 0, *p = &i; 
    // auto sz = 0, pi = 3.14; // problem here is that compiler won't know how to choose between int and double, so error 

    // compound types, const, and auto

    // if a reference is used with auto e.g. auto f = some_reference; the type of f is
    // inferred from teh type that the reference is referring to

    // when it comes to using the auto specifier with expressions involving const objects
    // top level const is dropped, whilst low level const is preserved
    const int ci = 10, &cr = ci;
    auto b = ci; // b is an int, top level const ignored
    auto c = cr; // c is an int, since cr is just replaced with ci
    auto d = &ci; // &ci is a memory location, so can be thought of as a pointer to const int -> low level const
    // here d is therefore a pointer to a const int 

    // if we want the deduced type to have a top level const, must say so explicitly
    const auto f = ci; // ci is a const int, auto is int since top level is ignored, so f is type const int
    
    return 0; 
}