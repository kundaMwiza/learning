## C++ value categories

Early C, there were two value categories: lvalues and rvalues

C++ added further capabilities: classes, const, references. This required new types of value categories to describe what the language is doing.

### Early C 

lvalue and rvalue come from assignment expression. 

#### lvalues & rvalues 

lvalue is an expression referring to an _object_.

an _object_ is a region of storage.

```c++
int n; // defintion for an integer object named n 
n = 1; // assignment expression 
```

the subexpression `n` is an lvalue. The subexpression `1` is just a literal, an rvalue.

```c++
x[i + 1] = abs(p->value);
```

`x[i+1]` is an lvalue, it is a subexpression consisting of an object that can be assigned to.
`abs(p->value)` is an lvalue expression, since it consists of an object that has a region in memory (`p`). The right hand side of an assignment can either be an lvalue or an rvalue.

#### Why introduce rvalues and lvalues?

So that compilers can assume that rvalues don't neccessarily occupy memory. For example the literal `1` may be placed in storage if it were not an rvalue.

In general an lvalue is an expression that refers to an object.

An rvalue is simply any expression that is not an rvalue 

This is true for non-class types (built in types). It's not true for class types.

Example rvalues:
- literals, e.g. 3, 3.14159, 'a'

However character string literals such as "xyzzy" are lvalues - they occupy data storage, since they have to behave like arrays.

```c++
const char arr[] = "mwiza";
```

Here the left hand side is an lvalue subexpression. So is the right hand side.

lvalues can appear on either side of an assignment statement. if an lvalue is placed on the rhs of an assignment statement, the lvalue object is converted to an rvalue. _lvalue-to-rvalue_ conversion.

When an object is treated as an lvalue, we care about the _memory_ location of that object.

When an object is treated as an rvalue, we care about the _value_ that the object has.

this is why only lvalues can appear on the lhs, and rvalue conversion occurs when an lvalue is on the rhs of an assignment expression.

#### lvalues/ rvalues apply to all expressions

For example, the binary operator `+` requires that the operands are either lvalues or rvalues of compatible type.

What about the result of an expression such as `+`? e.g. `m + 1`. the operands are lvalue/rvalue, but what about the result of the expression. The result of expressions are stored in temporary cpu registers, and so do *not* have memory reserved. The results of expressions are rvalues. However, we can assign the value of the temporary object to a region in RAM e.g. `m = m + 1;`. The rhs returns a temporary object stored in cpu registers. After, there is an instruction to move the temporary objects contents (rvalue) to the location given by the lhs lvalue.

Another example, the unary `*` dereference operator. the unary `*` operator returns an lvalue, since the dereference operator goes to a region of memory. That region of memory may be treated as an lvalue or rvalue depending on the expression:

```c++
int a = 5;
int * p =  &a;

*p = 4; // *p subexpression an lvalue ~ we are interested in the memory address of *p

int b = *p; // *p subexpression an rvalue ~ only interested in the value at the memory address, not its actual memory
```

Conceptually  rvalues (of non class type) don't occupy data storage in the object program. small operands like `1` may be provided in the instruction issued to the cpu. However large literals like character arrays or very long sentences can't be placed in instructions, since there is only a finite amount of space reserved for instructions (registers.), so the compiler chooses to reserve a location in memory.

However:
- C/C++ insist that you program as if non-class rvalues don't occupy storage
- C/C++ insist that you program as if lvalues occupy storage

#### Class types

```c++ struct S {
    int x, y;
}

S s1 = {5, 4};
```

Here when s1 is used, it is used as an lvalue since we're interested in the memory location occupied by s1. 

likewise, when a class type if used on the rhs on an expression, 
lvalue-rvalue conversion occurs, the _base address_ of the class object is required in order to determine the member that is to be accessed from the class object. 

lvalue/rvalueness depends on the expression, not the object type.
it is better to talk about how an object is _passed_:

```c++
int x = 5; // 5 passed as an rvalue to the assignment operator
int y = x; // x passed as an lvalue to the assignment operator, lvalue-rvalue conversion occurs
```
#### Non modifiable lvalues 

const objects when used in expressions are non modifiable lvalues.

#### Reference types

a reference is essentially a pointer that's automatically dereferenced each time its used. 

Can think of references as const pointers. i.e pointers whose value cannot be changed themselves. point to the same memory address throughtout the lifetime of the program.

A reference yields an _lvalue_ since it is bound to an object, therefore that object has memory allocated for it.

#### Reference to const

temporary objects created when an rvalue is used as the operand

ordinarily rvalues of built in types don't occupy data storage. 

However when a reference to const is passed a literal, a temporary object is created, and in this way the temporary object does have memory allocated.

The temporary is still an rvalue, but it occupies data storage, just like rvalues of class types.

### Two kinds of rvalues in modern c++

*pure rvalues*  or *prvalues*, which don't occupy data storage:
- literals that don't require large amounts of memory e.g. '1' , 'a'
*expiring values*  or *xvalues*, which do occupy data storage:
- for example reference to const bound to a literal. A temporary object is created in order for the reference to bind to an lvalue

In C++03, references are termed lvalue references. References can only bind to lvalue expressions. In particular:
```c++

int a = 5;
int &a_ref = a; // a is passed as an lvalue. OK
const int &ref = 5; // 5 is passed as a prvalue. Converted into an expiring value (creating a temporary object which has memory allocated). the ref binds to the temporary object (lvalue). OK
```

The new standard C++11 introduced *rvalue references.

`lvalue` references are created with a single `&` operator. an `rvalue` reference is created using the `&&` operator.  For example:

Here ri binds directly to an rvalue. Ordinarily, references could only be bound to lvalues, and that is why C++03 termed references as lvalue references

```c++
int &&ri = 10; // creates an rvalue reference
```

rvalue references are introduced in the langauge to implement something called _move semantics_.

rvalue references are similar to lvalue references. Again, references can only be bound to lvalues, so when an rvalue is the argument to initialise an rvalue reference, the r value is converted into an expiring r value, and then the r value reference is bound to a temporary object.

rvalue references exist in the language mainly to implement move operations that can avoid unnessary copying. 

move assignment operator 
```c++
string &string::operator=(string &&other) {
    string temp(other); // calls string(string const &)
}
```

The creation of temporary objects and binding references to such temporary objects implies that there is a region of memory allocated that the reference is bound to. However since the reference is bound to a region in memory, depending on the context, it can be viewed as an _lvalue_.

In particular, whehter something is an lvalue or an rvalue depends on the context in which it is being operated on. 

in general:
- if it has a name, its most likely an lvalue

### lvalues as xvalues 

its safe to move from an lvalue only if it's expiring.
The compiler can't always recognize an expiring lvalue. 
How can we inform the compiler?

- in other words, convert it to an unnamed rvalue reference
To move from an lvalue, you need to convert it to an expiring value. 

Thats what std::move does:

```c++ 
template <typename T>
constexpr T &&std::move(T &&a);
```

return values don't have names!

The standard defines 

![BBC11109-3150-4889-A06D-FF80789AF058_4_5005_c](/assets/BBC11109-3150-4889-A06D-FF80789AF058_4_5005_c_3x61sq7a2.jpeg)

And the simple way to think about it is:

- prvalues are stored in program code (come with instructions e.g. literals)
- lvalues have a region in memory allocated for them in RAM
- xvalues have temporary memory allocated for them, cpu registers or RAM

Also, an expression is treated as an lvalue if we're interested in the _memory_ location of the object

It is treated as an rvalue if we're only interested in the _value_ of the object

lvalue-to-rvalue conversion
