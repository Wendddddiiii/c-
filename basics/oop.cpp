#include <iostream>

class Car {
public:
    std::string make;
    std::string model;
    int year;
    std::string color;

    void accelerate() {
        std::cout << "You step on the gas" << std::endl;

    }

    void brake() {
        std::cout << "you step on the brake" << std::endl;
    }
};

int main() {
    Car car1;  
    car1.make = "Ford";
    car1.model = "Mustang";
    car1.year = 2022;
    car1.color = "red";

    std::cout << car1.make << std::endl;
    std::cout << car1.year << std::endl;
    std::cout << car1.model << std::endl;
    std::cout << car1.color << std::endl;
    car1.accelerate();
    car1.brake();
    return 0;   
}