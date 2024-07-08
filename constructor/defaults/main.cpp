//default constructibility:if it has a constructor that can be called with no arguments
//this can be either an explicitly defined default constructor or an implicitly generated one
//C++ will implicitly generate a default constructor for a class if no constructors are explicitly defined.
#include <string>
struct point2i {
    point2i() = default;//defaulted default constructor
    point2i(const point2i &) = delete;//copy constructor deleted
    point2i(point2i &&) = delete;//move constructor deleted
};

point2i get_point() { return point2i{}; } //create and return a point2i obejct by value

point2i p = get_point();

class ImplicitDefault {
public:
    int x;
    std::string y;
    //we have not defined any constructors here
    //this implicit constructor inits x to 0 and y to an empty string
};

class ExplicitDefault1 {
public:
    ExplicitDefault1() {  // Explicitly defined default constructor
        x = 10;
        y = "Hello";
    }
    
    int x;
    std::string y;
};

class ExplicitDefault2 {
public:
    ExplicitDefault2() = default;  // Explicitly requesting compiler-generated default constructor
    
    int x;
    std::string y;
};

int main() {
    ImplicitDefault obj;// This works - using the implicitly generated default constructor
    ExplicitDefault1 obj1;  // Uses the explicitly defined constructor
    ExplicitDefault2 obj2;  // Uses the explicitly requested, compiler-generated constructor
}


