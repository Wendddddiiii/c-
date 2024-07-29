#include <iostream>

//constructor: automatically called when an object is instantiated 
//useful for assigning values to attributes as arguments

class Car {
public:
    std::string make;
    std::string model;
    std::string color;
    int year;
    Car(std::string make, std::string model, std::string color, int year) {
        this->make = make;
        this->model = model;
        this->color = color;
        this->year = year;
    }
};

int main() {
    Car car1("toyota", "mustange", "blue", 1998);
    std::cout << car1.model << std::endl;

    return 0;
}