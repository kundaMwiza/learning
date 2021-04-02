#include <iostream>

int main() {

    // types of operators
    // unary operators -> take one operand as input
    // binary operators -> take two operands as input
    // ternary opeartor -> take three operands as input e.g. a ? b : c which is an ifelse
    // another operator is the function call, which takes any number of arguments

    // overloaded operators/ functions are operators/ functions that behave differently 
    // depending on the input
    // e.g. >> and << and the same ones defiend for string and vector types, are 
    // overloaded operators
    // however the number of operands, precedene and associativity of the operator cannot be changed

    // every expression in cpp is either an rvalue or an lvalue
    // in C -> intended to have a simple mnemonic purpose -> lvalues could stand on the left hand side
    // of an assignmnet, whereas rvalues could not e.g. const objects as operands to the binary assignment 
    // operator can not be on the left hand side, so const objects are expressions that are not lvalues 

    // in C++ -> an lvalue expression yields an object or a function, however, some lvalues, such as const objects,
    // may not be on the left hand operand of an assignment

    // decltype() if the operand expression yields an lvalue, the result is a reference type
    // decltyppre() if the operand expression yields an rvalue, the result is just the type of the expression
    
    int a = 5; 
    int *p = &a; // p is a pointer to an int &a yields int* as an rvalue, left hand operand is an lvalue of type int *

    decltype(*p) k = a; // dereference yields an lvalue, in this case an int, so k is int&, and its a reference to the int a
    decltype(&p) t = &p; // here &p returns an lvalue of type int **, so t is int **, and intialize it to point to p

    // an expression with two or more operators is a compound expression. To evaluate a compound expression, need to 
    // group operands with operators. Precedence and associativity determine how the operands are grouped.
    // Can ovveride grouping of operands with expressions by using parenthesis in compound expressions
    // operands with higher precedence group more tightly than operands of operators at lower precedence
    // associativity determines how to group operands having the same level of precedence
    // multiplication and division have the same level of precedence, but higher precedence than addition
    // so operands to multipplication and division group before operands to addition and subtraction
    // arithmetic operators are left associative, meaning that operators with the same level of precedence group left to right
    // e.g. 3 + 4 * 5, multiplication has a higher precedence than division, so the result is 23
    // 20-15-3 is 5 - 3 = 2, due to left associativity of operators of the same precedence
    // 6 + 3 * 4 / 2 + 2 = 6 + 12/ 2 + 2 = 6 + 6 + 2 = 14 since * and / have the same precedence, left associativity enacts 
    // leading to 3 * 4 being computed first. After, division has a higher precedence than addition, so that is performed

    }