#ifndef MEMBERINIT
#define MEMBERINIT 1


class someClass {

    public: 

    // when it comes to data member initialisation 
    // through either the default constructor or a custom constructor
    // there is a difference between assignment and initialisation
    
    someClass() = default;

    // when a constructor has an initializer list that is empty 
    // i.e that part of the syntax that follows after the colon,
    // but before the function body
    // then all data members are either in class initialized 
    // if in-class initializers are available, or default initialised 
    // by the default constructor, if it is defined
    // in the case below, that means member_one, member_two and member_three
    // will all be initialised to zero
    // however, that means we can no longer change member_three since it is const 
    // and has already been initialised..
    // someClass(int o, float t, int ct) 
    // {
    //     member_three = 5; // error because member_three is const, and has already 
            // been initialised
    // } 

    // here all three data members are explicitly initialised
    someClass(int o, float t, int ct) 
        : member_one(o), member_two(t), member_three(ct) {} 


    private:

        int member_one;
        float member_two;
        const int member_three;

};
#endif 