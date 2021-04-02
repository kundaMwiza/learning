#include <iostream>
#include <string>
#include <vector>

#include "Person.h"

int main(int argc, const char *argv[])
{

    // create adam & eve
    Person adam("adam", "first", "eden");
    Person eve("eve", "first", "eden");

    Person child_one = adam.create_child(&eve, "one", "1", "somewhere");
    Person child_two = adam.create_child(&eve, "two", "2", "somewhere");

    // // make sure kieran and kieran know about their children..
    adam.add_children({&child_one, &child_two});
    eve.add_children({&child_one, &child_two});

    // print some information of their children
    for (auto child : adam.children)
    {
        child->print(std::cout);
    }

    return 0;
}