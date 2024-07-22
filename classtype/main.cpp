//Constructors are special member functions that initialize objects of the class.
//Each class has at least one constructor.
//Constructor has same name of the class and no return type
// a class can have multiple constructors construtor overloading

//default constructor: take no paramter
//Parameterized constructor: Takes one or more parameters
//copy: Creates a new object as a copy of an existing object
//move: Transfers ownership of resources from one object to another

//Constructors are called automatically when an object is created.
//properly initialized before used
#include <iostream>
#include <vector>


int main() {
    auto v41 = std::vector<int> { 5, 2 }; 
    auto v42 = std::vector<int>(5, 2);
    for (auto& num: v41) {
        std::cout <<  num << std::endl;
    }
    for (auto& num2: v42) {
        std::cout << "num2: " << num2 << std::endl;
    }

    return 0;
}