## Dynamic memory c++ 

in C++, dynamic memory is managed through a pair of operators: `new`, which allocates, optionally initializes, an object in dynamic memory and returns a pointer to that object. And `delete`, which takes a pointer to a dynamic object, destroys the object and frees the associated memory. 

Two issues with dynamic memory 
- memory leak (forgetting to free dynamically allocated memory)
- dangling pointers (freeing objects but continuing to use pointers to those objects)

C++ introduces two smart pointers that manage dynamic objects. These types are defined in the _memory_ header.

- `shared_ptr`, which allows multiple pointers to refer to the same object
- `unique_ptr`, which "owns" the object to which it points, preventing other pointers from pointing to the same object.
- `weak_ptr`, a weak reference to an object managed by `shared_ptr`. 

#### The `shared_ptr` class

Like vectors, smart pointers are template classes. They require additional information to create smart pointers:

```c++
#include <memory>
// defines a null shared_ptr
// default initialised shared_ptr's point to null
std::shared_ptr<int> sp; 
std::shared_ptr<std::vector<int>> spvi; 
```

smart pointers can be used in ways that are similar to regular pointers. Below are operations that are shared between unique_ptr's and shared_ptr's 

```c++
#include <memory>
// default initialised poitners point to null
std::shared_ptr<T> sp;
std::unique_ptr<T> up;
p; // use p as a condition, returns false if p is a null ptr
*p; // return the object pointed to by p
p->mem; // similar to (*p).mem, here mem is short for member
p.get(); // returns the pointer in p
swap(p,q); // swaps the pointers in p and q e.g. to change the objects that the pointers are pointing to
```

Operations specific to shared_ptr's:
```c++
#include <memory>

// function to create a shared pointer
// args are the arguments required to construct the object that the shared pointer will point to
std::shared_ptr<T> p = std::make_shared<T>(args);

// construct a shared pointer using copy construction
// this increments the reference count in p
std::shared_ptr<T> sp(p); 

// p and q are shared pointers pointing to types that are convertible. Decrements p's reference count and increments q's reference count. Deletes p's existing memory if p's count goes to zero
p = q; 

// returns true is p's reference count is 1 else false i.e p.use_count()
p.unique() 
// returns the number of objects sharing with p, may be a slow operation, intended primarily for debugging purposes 
p.use_count()
```
When a `shared_ptr` is copied, the reference count is incremented:
- when the `shared_ptr` is copy constructed from a shared pointer:

```c++
auto sp = std::make_shared<T>(args);
// reference count of sp increased by 1 
std::shared_ptr<T> p(sp);
// reference count of sp increased by 1 again
std::shared_ptr<T> q = sp;

// passing a shared_ptr<T> by value to a function, 
// increased by 1
Type func_name(std::shared_ptr<T> l);

// returning a shared_ptr by value from a function
// increased by 1
std::shared_ptr<T> func_name();
```

`shared_ptr`'s reference count is decremented when a `shared_ptr` is assigned to a different object, of when it goes out of scope. Once a `shared_ptr`'s counter goes to zero, the `shared_ptr` automatically frees the object that it manages:

```c++
// sp reference count goes to 1
auto sp = std::make_shared<T>(args);
// sp now points to a different address, 
// reference counts goes to zeo (sp)
// r reference count increases by 1
sp = r;
```

When the last shared_ptr pointing to an object is destroyed, the shared_ptr class automatically destroys the object to whic hthat shared_ptr points. It does this through another special member function known as a destructor.

