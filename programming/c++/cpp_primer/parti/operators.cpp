#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl; 

int main() {
    // assignment operators
    // the left-hand operand of an assignment operator must be a modifiable lvalue
    // and note that there is a difference between initialization and assignment
    // below -> initialization
    int i = 0, j = 0, k = 0; 
    const int ci = i; 

    // below assignment illegal  LHS is an rvalue 
    // 1024 = k;
    // i + j = k;  
    // ci = k;  here cannot modify a const int

    // the result of an assignment is its left hand operand
    // so can do things like below

    if (int i = 0) {
        cout << "the if condition is TRUE" << endl; 
    }
    
    cout << "the if condition is FALSE" << endl; 

    // assignment is right associative ->
    // declare a1 and a2
    int a1, a2;

    // first assignment = defining a1 and a2
    // right associativity means that a2 is defined first, and then a1 is copy 
    // initialized from a2
    a1 = a2 = 0;

    // assignments can occur inside conditions for example 

    // int a3 = get_value();
    // while ((int i = get_value) != 42) {
    //  do something
    // }

    // since assignments can be used inside conditions, they should not be 
    // confused with the equality operator e.g. in the example below, the code
    // will not neccessarily error since it is valid to perform an assignment 
    // inside a condition. If the original intention is to test for equality
    // then there is a bug with this code
    // if (i = j) {
        // 
    // } 

    // compound assignment operators (a op=b is the same as a = a op b ) 
    // arithmetic operators:
    // += -= *= /= %=
    // bitwise operators (to be covered later)
    // <<= >>= &= ^= |= 
    // a consequence of using compound assignment operators is that
    // the left hand operand is only evaluated once. when using the 
    // regular assignment e.g. a = a op b, the operand a is evaluated
    // twice, once on the lhs and once once on the rhs
    // where the evaluation of an operand is time sensitive
    // the choice of operator (compound or not) can have performance consequences

    // increment and decrement operators
    // the increment ++ and decrement -- provide a convenient notational
    // shorthand for adding or subtracting 1 from an object. This notation arises
    // from convenience when applying these operators to iterators -> since 
    // many iterators do not support arithmetic operations
    // two forms of increment and decrement operators:
    // postfix and prefix obj++ and ++obj. postfix returns
    // the unincremented value, whereas prefix returns the incremented value 
    // both operators require an lvalue as input. prefix returns an lvalue
    // postfix returns an rvalue

    // a common pitfall of increment and decrement iterators is in operators
    // that do not define the order of evaluation. For example, expressions like this
    // are undefined:
    // *beg = toupper(*(beg++));
    // if the rhs is evaluated first, then the lhs will be performing 
    // *(beg + 1) = toupper(*(beg++));
    // however if the lhs is evaluated first, the result will be 
    // *beg = toupper(*(beg++))

    // member access operators
    // the dot (.) and arrow (->) operators provide for member access. 
    // the dot operator fetches a member from an object of class type. 
    // arrow is defined so that ptr->mem is a synonym for (*ptr).mem
    // the arrow operator requires a pointer operand and yields an lvalue
    // the dot operator yields an lvalue if the object from which the member is 
    // fetched is an lvalue; otherwise the result is an rvalue

    int a4 = 0, a5 = 0;

    vector<string> vec_string{"blah", "two"};
    
    vector<string>::iterator vec_string_iter = vec_string.begin();

    // increment has a higher precendence than dereference
    // first postfix returns the unincremented iterator
    // which is the dereferenced
    cout << *vec_string_iter++ << endl; 

    // illegal since string cannot be incremented
    // cout << (*vec_string_iter)++ << endl; 

    // illegal since dot has a higher precedence than dereference
    // so empty called on an object of type vector<string>::iterator, which is illegal
    // cout << *vec_string_iter.empty() << endl;
    
    // arrow operator operates on pointers
    // below is equal to (*iter).empty() which is valid
    cout << vec_string_iter->empty() << endl; 

    // prefix increment operator has a higher precedence than dereference
    // is the iterator incremented and then dereferenced, or is 
    // a dereference performed first, and the string (illegally) incremented?
    // illegal since iterator is first dereferenced
    // cout << ++*vec_string_iter << endl; 

    // legal, incremented, and then the member function empty() 
    // is called on the resulting string
    cout << vec_string_iter++->empty() << endl; 


    // ternary if else operator
    // cond ? expr1 : expr2
    // expr1 and expr2 must be expressions of the same type
    // or converteable to the same type
    // the result of the conditional operator is an lvalue
    // if both expressions are/convert to lvalues. Otherwise an rvalue  
    int a7 = a4 == a5 ? 9 : 10;
    cout << a7 << endl; 

    // since the conditional operator has fairly low precedence, it is advised
    // to parenthisize the conditional operator when used in a compound expression
    // e.g. 
    // the first example works as intendend, since parenthesized
    // cout << ((a7 == 5) ? 5 : 4) << endl; 
    // for the second example, << has higher precedence than ? 
    // so the right hand operand to the << operator is (a7==5)
    // which then proceedes to evaluate cout ? 5 : 4 
    // cout << (a7 == 5) ? 5 : 4 << endl; 
    // here the << operator has the highest precedence, so the 
    // right hand operand to the << operator is a6 
    // which then proceedes to evaluate cout == 5 ? 5 : 4
    // cout << a6 == 5 ? 5 : 4 << endl; 


    // using bitwise operators
    // create a placeholder to store atleast 32 bits
    // unsigned long guaranteed to be atleast 32 bits on any machine
    // initialize to zero so all bits are switched off
    unsigned long holder = 0;

    // if want to turn a bit, e.g. bit 27, can use 
    // a integer literal that has bit 27 turned on, 
    // and all other bits turned off
    // eg. 1UL << 27
    // 1UL only has the lowest bit turned on, and all bits to the left
    // set as zero
    // bitwise shift left adds zeros to the right of 1UL
    // to then set our holder to have bit 27 on, can use bitwise or
    holder |= (1UL << 27);

    // if want to turn off the 27th bit, can use bitwise or via
    holder &= ~(1UL << 27);

    // if want to know the value at the 27th bit, can use bitwise and
    // with an unsigned long literal that has only bit 27 turned on:
    // note that need to cast the value to a boolean to find out 
    // whether the resulting value is non zero or equal to zero
    // if it is zero, then bit 27 was off. if it is non-zero
    // then bit 27 is on, in which case the result is true
    cout << (bool) (holder & (1UL << 27)) << endl; 

    // sizeof operator -> returns the size, in bytes, of an expression or a type name.
    // the operator is right associative. The result of sizeof is a constant expression
    // of type size_t (machine independent? unsigned int)
    // operator takes one of two forms sizeof(type) or sizeof(expr)
    // size of does not evaluate its operand, it takes an operands TYPE
    // and returns the type of that
    // for example:
    int a8 = 5, *a9 = &a4; 
    cout << (sizeof(int)) << endl; 
    cout << (sizeof a9) << endl;
    cout << (sizeof *a9) << endl;  

    // under the new standard, can use the scope operator to request for the size
    // of a member of a class type. Ordinarilly needed an object of a class type
    // in order to access the members of a class type. 

    // note that since a reference is just an alias for another object, 
    // sizeof &ref returns the size of the type that ref referes to
    
    // sizeof returns the size needed to hold a pointer
    // sizeof an array is the size of the entire array since the 
    // type is e.g. an array of 10 ints, sizeof will be sizeof(int) * array size
    // because sizeof returns a constant expression, can use the result 
    // of a sizeof expression to specify the dimension of an array
    // sizeof string or vector does not return the size used by the objects elements
    // it only returns the memory allocated to an instance of vector or string

    vector<int> vec_int{5, 10, 15};

    cout << (sizeof vec_int) << endl;
    cout << vec_int.size() << endl;  
    cout << sizeof(int) << endl; 

    // the only operators with a guaranteed order of evaluation are &&,  ||,  ? :, and the comma operator
    // (,) which evaluates from left to right. 

    // the comma operator is a binary operator, taking two operands that are evaluated 
    // from left to right
    // the left hand expression is evaluated and the result is discarded. The result of the comma
    // expression is the value of the right hand operand. The result is an ltype if the right hand operand
    // is an ltype. Common use of the comma operator is in for loops:
    // for (int i = 0, j = 0; i <= 10; ++i, --j)
    // note that the last clause of the for loop header is an expression e.g. (++i, --j)
    // the comma operator can be used pretty much anywhere since the left hand evaluation is discarded
    // and the result of evaluating the expression is the result of evaluating the right hand operand.
    // The result returned is either an lvalue - if the right operand is an lvalue

    return 0; 
}