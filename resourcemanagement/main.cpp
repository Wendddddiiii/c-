//Object: An object is a region of memory that has a type and can store data.
//properties of objects:
//1.type: either a built-in type or a user-defined type
//2.state: Objects can have data members that represent their current state.
//3.behaviour: for class objects, they can member functions to define their behavior.


//1.type: built in type: int, float, char User defined type:instance of classes or structs

//Lifetime: 1.automatic exist till end of scope, dynamic until explicity delete, static for entire program

// access objects: direct access obj.member; pointer access: obj-> member

#include <iostream>
class Point {
private:
    int x, y;  // Data members

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}  // Constructor

    void move(int dx, int dy) {  // Member function
        x += dx;
        y += dy;
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    // Automatic object
    Point p1(3, 4);
    p1.display();  
    p1.move(1, -1);
    p1.display();  

    // Dynamic object
    Point* p2 = new Point(1, 1);
    p2->display();  
    delete p2;  // deallocate dynamic objects

    return 0;
}