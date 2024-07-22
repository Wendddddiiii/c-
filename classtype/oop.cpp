#include <iostream>
#include <string>

class Car {
private:
    // Private data members (state of the object)
    std::string brand;
    std::string model;
    int year;
    double fuel;
    bool isRunning;

public:
    // Constructor
    Car(const std::string& b, const std::string& m, int y)
        : brand(b), model(m), year(y), fuel(50.0), isRunning(false) {
        std::cout << "Car created: " << brand << " " << model << std::endl;
    }

    // Public member functions (interface)

    // Inline member function (defined inside the class)
    void start() {
        if (!isRunning) {
            isRunning = true;
            std::cout << "The car is now running." << std::endl;
        } else {
            std::cout << "The car is already running." << std::endl;
        }
    }

    // Function declaration (will be defined outside the class)
    void stop();

    // Const member function (doesn't modify the object's state)
    void displayInfo() const {
        std::cout << year << " " << brand << " " << model 
                  << " (Fuel: " << fuel << "L)" << std::endl;
    }

    // Mutator function
    void refuel(double amount) {
        if (amount > 0) {
            fuel += amount;
            std::cout << "Refueled " << amount << "L. New fuel level: " << fuel << "L" << std::endl;
        }
    }

    // Accessor function (const as it doesn't modify the object's state)
    double getFuelLevel() const {
        return fuel;
    }
};

// Member function defined outside the class
void Car::stop() {
    if (isRunning) {
        isRunning = false;
        std::cout << "The car has stopped." << std::endl;
    } else {
        std::cout << "The car is already stopped." << std::endl;
    }
}

int main() {
    // Instantiate a Car object using the constructor
    Car myCar("Toyota", "Corolla", 2022);

    // Use the public interface
    myCar.displayInfo();
    myCar.start();
    myCar.refuel(10);
    std::cout << "Current fuel level: " << myCar.getFuelLevel() << "L" << std::endl;
    myCar.stop();

    return 0;
}