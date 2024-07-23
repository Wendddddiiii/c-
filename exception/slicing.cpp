
#include <iostream>
#include <stdexcept>
//object slicing: when a derived class object is assigned to a base class object, rsulting in the loss of derived class specific members


class Base {
protected:
    int baseData;
public:
    Base(int data) : baseData(data) {}
    virtual void display() { std::cout << "Base: " << baseData << std::endl; }
};

class Derived : public Base {
private:
    int derivedData;
public:
    Derived(int baseData, int derivedData) : Base(baseData), derivedData(derivedData) {}
    void display() override { 
        std::cout << "Derived: Base=" << baseData << ", Derived=" << derivedData << std::endl; 
    }
};

int main() {
    Derived d(10, 20);
    Base b = d;  // Object slicing occurs here
    
    d.display();  // Output: Derived: Base=10, Derived=20
    b.display();  // Output: Base: 10 (derivedData is lost)
}