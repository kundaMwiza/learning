#ifndef PERSON
#define PERSON 1 

#include <iostream>
#include <string>
#include <vector>

struct Person{

    // data members
    const Person *parent_one = NULL;
    const Person *parent_two = NULL;
    const std::string first_name;
    const std::string last_name;
    std::string address;
    std::vector<const Person*> children; 

    // -- overloaded constructors

    // default constructor
    // as provided by the new standard 
    Person() = default;
    
    // constructor with with no parents
    Person(const std::string fn, const std::string ln, const std::string add)
        : first_name(fn), last_name(ln), address(add) {}

    // constructor with parents
    Person(
        const Person *p1, const Person *p2, const std::string fn
        ,const std::string ln, const std::string add 
        )
        : parent_one(p1), parent_two(p2), first_name(fn)
        ,last_name(ln), address(add) {}

    // -- member functions

    // output a persons simple information -- const member function
    std::ostream& print(std::ostream &os) const {

        os << "Person information: " 
            << "\n----------------------------------"
            << "\nfirst name: "
            << first_name
            << "\nlast name: "
            << last_name
            << "\naddress: "
            << address
            << "\n----------------------------------"
            << std::endl; 
        
        return os;

    }

    // create a function to produce a child 
    Person create_child(
        const Person *other_parent, const std::string &fn, const std::string &ln
        ,const std::string add) {
            // construct with parents
            Person child(this, other_parent, fn, ln, add);
            
            return child;
        }
    
    void add_children(std::initializer_list<const Person*> children_list) {

        // add children to children vector...
        // easiest is a range for 
        for (auto child : children_list) {
            children.push_back(child);
        }

    }

};

// note that by default, when copy initialising a class instance
// all member objects are also copied
// Person instance_two = instance_one;


#endif 

