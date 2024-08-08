#include <iostream>
#include <string>
#include <vector>
#include <memory>
//rule of zero:Design your class so that it doesn't need to declare any of the special member functions (destructor, copy/move constructors, copy/move assignment operators).
//Reason: By relying on member objects to handle their own resource management, you can often avoid writing these special functions altogether, leading to simpler, less error-prone code.

class ResourceManager {
private:
    std::string name;
    std::vector<int> data;
    std::unique_ptr<double> specialValue;

public:
    ResourceManager(const std::string& n, std::initializer_list<int> d, double val)
        : name(n), data(d), specialValue(std::make_unique<double>(val)) {}

    // No need to declare destructor, copy/move constructors, or assignment operators

    void print() const {
        std::cout << "Name: " << name << ", Data: ";
        for (int i : data) {
            std::cout << i << " ";
        }
        std::cout << ", Special Value: " << *specialValue << std::endl;
    }
};

int main() {
    ResourceManager rm1("Resource1", {1, 2, 3}, 3.14);
    ResourceManager rm2 = rm1;  // Compiler-generated copy constructor
    ResourceManager rm3("Resource3", {4, 5, 6}, 2.71);
    rm3 = rm1;  // Compiler-generated copy assignment

    rm1.print();
    rm2.print();
    rm3.print();

    return 0;
}