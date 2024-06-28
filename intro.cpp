//oop: a way to organize designs and implementations
//objects(entity), not control, or data flow, is the primary focus
//focus on things, not operations
//data is the status

#include <iostream>
using namespace std;

class Point3d {
public: 
    Point3d(float x, float y, float z);
    void print() const;
private:
    float x;
    float y;
    float z;
};

// Constructor definition
Point3d::Point3d(float x, float y, float z) : x(x), y(y), z(z) {}

// Method definition
void Point3d::print() const {
    cout << "Point(" << x << ", " << y << ", " << z << ")" << endl;
}
int main() {
    Point3d a(1, 23, 11); // Object creation
    a.print(); // Method call

    return 0;
}

