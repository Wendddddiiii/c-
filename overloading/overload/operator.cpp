#include <iostream>

class vec3 {
public:
    //constructor for initialization
    vec3(int x = 0, int y = 0, int z = 0): x_(x), y_(y), z_(z){}

    //overloaded addition assignment operator
    vec3& operator+=(const vec3 &p) {
        x_ += p.x_;
        y_ += p.y_;
        z_ += p.z_;
        return *this;
    }

    vec3& operator-=(const vec3 &p) {
        x_ -= p.x_;
        y_ -= p.y_;
        z_ -= p.z_;
        return *this;
    }

    //method for dot product
    int dot(const vec3 &p) const {
        return x_ * p.x_ + y_ * p.y_ + z_ * p.z_;
    }

    //method for cross product
    vec3 cross(const vec3 &p) const {
        return vec3(
            y_ * p.z_ - z_ * p.y_,
            z_ * p.x_ - x_ * p.z_,
            x_ * p.y_ - y_ * p.x_
        );
    }

private:
    int x_;
    int y_;
    int z_;
};

int main() {
    vec3 a(1, 2, 3);
    vec3 b(4, 5, 6);

    //using addition assignment operator
    a += b;

    //using subtraction assignment operator
    a -= b;

    //using dot product
    int dotProduct = a.dot(b);

    //using cross product 
    vec3 crossProduct = a.cross(b);
    return 0;
}