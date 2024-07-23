#include <iostream>

// Base class with a virtual print_num function
class Base {
public:
    virtual ~Base() = default; // Virtual destructor for proper cleanup
    virtual void print_num(int i = 1) { // Virtual function with default parameter
        std::cout << "Base" << i << "\n";
    }
};

// Derived class overriding the print_num function
class Derived : public Base {
public:
    void print_num(int i = 2) override { // Overridden function with different default parameter
        std::cout << "Derived" << i << "\n";
    }
};

int main() {
    Derived derived; // Creating a Derived class object
    Base* base = &derived; // Base class pointer pointing to Derived class object

    derived.print_num(); // Calls Derived::print_num with default parameter 2
    base->print_num(); // Calls Derived::print_num due to polymorphism with default parameter 1

    return 0;
}

// Explanation: This section of code demonstrates polymorphism in C++ where
// the print_num function is overridden in the Derived class. The Derived class
// provides its own implementation of print_num, which is called when a Derived
// object is used through a Base class pointer.


// Base class with a virtual function returning a reference to LandAnimal
class Base {
    virtual LandAnimal& get_fav_animal();
};

// Derived class overriding the get_fav_animal function
class Derived : public Base {
    // Fail to compile: return type does not match the base class
    Animal& get_fav_animal() override;

    // Compile: return type is a derived class of the base class return type
    LandAnimal& get_fav_animal() override;

    // Compile: return type is a more specific derived class
    Dog& get_fav_animal() override;
};

// Explanation: This section demonstrates method overriding with different return
// types. The return type of an overriding function must be either the same or
// covariant (a derived type of the original return type).


// Base class with a virtual function accepting a LandAnimal reference
class Base {
    virtual void use_animal(LandAnimal&);
};

// Derived class overriding the use_animal function
class Derived : public Base {
    // Compile: All land animals are valid input
    void use_animal(Animal&) override;

    // Compile: Same parameter type as base class
    void use_animal(LandAnimal&) override;

    // Fail to compile: Not all land animals are valid input (only dogs)
    void use_animal(Dog&) override;
};

// Explanation: This section demonstrates method overriding with different parameter
// types. The parameter type of an overriding function must be the same as or a base
// type of the parameter type in the base class function.

