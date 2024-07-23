//slicing problem exception handling: when catching exception by value, slicing problem occurs


#include <iostream>
#include <stdexcept>
class BaseException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Base exception";
    }
};

class DerivedException : public BaseException {
public:
    const char* what() const noexcept override {
        return "Derived exception";
    }
};

int main() {
    try {
        throw DerivedException();
    }
    catch (BaseException e) {  // Caught by value, slicing occurs
        std::cout << e.what() << std::endl;  // Outputs: "Base exception" we lose the overridden what() method of derived exception
    }
}