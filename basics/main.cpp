

#include <iostream>

// calculate area of rectangle
double calculateRecArea(double height, double width) {
    return height * width;
}

// calculate area of sqaure
double calculateSquArea(double side) {
    return side * side;
}

void processInt(int value) {
    std::cout << "Processing Integer: " << value << std::endl;
}

// Process floating-point values
void processDouble(double value) {
    std::cout << "Processing double: " << value << std::endl;
}


void processString(const std::string& value) {
    std::cout << "Processing string: " << value << std::endl;
}

void processBoolean(bool value) {
    std::cout << "Processing bool: " << (value ? "true" : "false") << std::endl;
}

int main() {
    double height = 6.0;
    double width = 4.0;
    double side = 5.0;

    std::cout << "Area of rectangle: " << calculateRecArea(height, width) << std::endl;
    std::cout << "Area of square: " << calculateSquArea(side) << std::endl;

    processInt(42);
    processBoolean(false);

    return 0;
}