## OOP overview

The key ideas of object oriented programming are _data abstraction_, _inheritance_ and _dynamic binding_.

Through abstraction, we can define classes that separate interface from implementation. 

Through inheritance, we can define classes that model the _relationships_ among similar types. 

Through dynamic binding, we can use objects of these types while ignoring the details of how they _differ_ 

### Inheritance

Classes related by inheritance form a hierarchy. typically there is a _base class_ at the root of the hierarchy, from which the other classes inherit, directly or indirectly. 

Inheriting classes are known as derived classes.

The base class defines those members that are common to the types in hte hierarhy. 

Each derived class defines those members that are specific to the derived class itself.

In C++, a base class distinguishes functions that are type dependent from those that it expects its derived classes to inherit without change. 

The base class defined _virtual_ functions that it expects its derived classes to define for themselves.