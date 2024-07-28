#include <iostream>

class point {
public:
    point(int x, int y)
        : x_{x}
        , y_{y} {};
    //nodiscard suggests that these values are important and should be used when the functions are called.
    [[nodiscard]] int x() const{
        return this -> x_;
    }
    [[nodiscard]] int y() const{
        return this -> y_;
    }
    static point add(point const& p1, point const& p2);
private: 
    int x_;
    int y_;
};


void print(std::ostream& os, point const& p) {
    os << "(" << p.x() << "," << p.y() << ")";
}

point point::add(point const& p1, point const& p2) {
    return point {p1.x() + p2.x(), p1.y() + p2.y()};
}

int main() {
    point p1 {1, 2};
    point p2 {2, 3};
    print(std::cout, point::add(p1, p2));
    std::cout << "\n";
}