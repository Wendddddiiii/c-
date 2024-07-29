#include <iostream>

//pass by reference

void swap(std::string &x, std::string &y);

int main() {
    std::string x ="kool-aid";
    std::string y ="water";

    swap(x, y);

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    return 0;
    
}

void swap(std::string &x, std::string &y) {
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}