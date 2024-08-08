#include <iostream>

using namespace std;

class Box {
public:
    //constructor
    Box(double l=2.0, double b=2.0, double h=2.0) {
        cout << "constuctor is called" << endl;
        length = l;
        breadth = b;
        height = h;
    }
    double Volume() {
        return length * breadth * height;
    }
    int compare(Box box) {
        return this->Volume() < box.Volume();
    }
private:
    double length;
    double breadth;
    double height;
};

int main() {
    Box box1(3.0, 1.1, 2.0);
    Box box2(3.0, 9.0, 8.8);
    if(box1.compare(box2)) {
        cout <<  "box2's volume is larger than box1" << endl;
    } else {
        cout <<  "box2's volume is smaller than box1" << endl;

    }
    return 0;
}