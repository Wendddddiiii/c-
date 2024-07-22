#include <iostream>
#include <string>

class Initial {
private:
    int a;
    double b;
    std::string c;
    const int d;
    int& e;

public:
    // Constructor with initializer list
    //same name as the class and no return type
    Initial(int x, double y, const std::string& z, int& ref)
        : a(x) 
        , b(y)
        , d(100)
        , e(ref)
    {
        std::cout << "Constructor body starts\n";

        //assign to c in the constructor body
        c = z;

        //modfit a in the constructor body
        a += 5;

        std::cout << "Constructor body ends\n";
    }

    void display() const {
        std::cout << "a: " << a << "\n";
        std::cout << "b: " << b << "\n";
        std::cout << "c: " << c << "\n";
        std::cout << "d: " << d << "\n";
        std::cout << "e: " << e << "\n";
    }
};

int main() {
    int ref_value = 200;
    Initial obj(10, 3.14, "Hello", ref_value);
    obj.display();

    return 0;
}