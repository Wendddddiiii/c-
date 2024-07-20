//declaration v.s. definition

#include <iostream>

//decalaration of a func
int add(int a, int b);

//decalaration of a class
class Rectangle;

// Declaration of a variable (extern)
//extern: declare a global variable or function that is defined in another file or translation unit
//It's used for declaration, not definition.
//share global variables across multiple files.
//For functions, "extern" is implied and usually omitted in declarations.
extern int globalVar;

extern const double PI;

//definition 
int add(int a, int b) {
    return a + b;
}

class Rectangle {
private:
    int width;
    int height;
public:
    Rectangle(int w, int h): width(w), height(h) {}
    int area() {return width * height;}
};

// Definition of the previously declared variable
int globalVar = 10;

// Definition of the previously declared constant
const double PI = 3.14159265358979323846;

// Function using declarations and definitions
int main() {
    int result = add(5, 3);  // Using the defined function
    std::cout << result << std::endl;
    Rectangle rect(4, 5);    // Using the defined class
    int area = rect.area();
    std::cout << area << std::endl;
    std::cout << globalVar << std::endl;
    std::cout << PI << std::endl;

    return 0;
}