#include <iostream>
//virrual functions allow defining a function in a base class that can be overidden in derived classes, 
//enable run time polymorphism


class Animal {
public:
    virtual void makeSound() {
        std::cout << "The animal makes a sound" << std::endl;
    }
    virtual ~Animal() {}  // Virtual destructor for proper cleanup
};
//dog cat classes can override the virtual function
//when we call animalSound() with pointers to Dog and Cat objects
//the correct overriden func is called based on the actual object type, not the pointer type
//this is why catching exception by ref is importrant: preserved the polymorphic behavior and allow catch and handle more specific expcetions 
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "The dog barks" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "The cat meows" << std::endl;
    }
};

void animalSound(Animal* animal) {
    animal->makeSound();
}

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    
    animalSound(dog);  
    animalSound(cat);  
    
    delete dog;
    delete cat;
}