#include <iostream>
#include <stdexcept>

class Animal {
public:
    virtual ~Animal() = default;
    virtual void makeSound() const {std::cout << "Animal sound.\n";}
};

class Dog : public Animal {
public: 
    void makeSound() const override {std::cout << "Wood!\n";}
    void wagTail() const {std::cout << "Dog is wagging its tail\n";}
};

class Cat : public Animal {
public:
    void makeSound() const override {std::cout << "Meow!\n";}
    void purr() const { std::cout << "Cat is purring\n";}
};

void downcast(Animal* animal) {
    // Using dynamic_cast with pointers
    Dog* dog = dynamic_cast<Dog*>(animal);
    if(dog) {
        std::cout << "This animal is a Dog.\n";
        dog -> wagTail();
    } else {
        std::cout << "This animal is not a Dog.\n";
    }
    // Using dynamic_cast with references
    try {
        Cat& cat = dynamic_cast<Cat&>(*animal);
        std::cout << "This animal is a Cat.\n";
        cat.purr();
    } catch (const std::bad_cast&) {
        std::cout << "This animal is not a Cat.\n";
    }

    // Using static_cast (unsafe, use only when you're certain)
    Dog* certainDog = static_cast<Dog*>(animal);
    // Note: This will compile and run without error, even if animal isn't a Dog!
    // Only use when you're absolutely sure about the type.
    certainDog->wagTail(); // Dangerous if animal isn't actually a Dog!
}

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    Animal* animal3 = new Animal();

    std::cout << "Testing with Dog:\n";
    downcast(animal1);

    std::cout << "\nTesting with Cat:\n";
    downcast(animal2);

    std::cout << "\nTesting with generic Animal:\n";
    downcast(animal3);

    // Clean up
    delete animal1;
    delete animal2;
    delete animal3;

    return 0;
}