#include <iostream>
using namespace std;

class point {
public:
    // Constructor
    point(int x, int y)
    : x_{x}, y_{y} {};

    // Friend function declarations
    friend std::ostream& operator<<(std::ostream& os, const point& p);
    friend std::istream& operator>>(std::istream& is, point& p);

private:
    int x_;
    int y_;
};

// Overloaded output stream operator
std::ostream& operator<<(std::ostream& os, const point& p) {
    os << "(" << p.x_ << ", " << p.y_ << ")";
    return os;
}

// Overloaded input stream operator
std::istream& operator>>(std::istream& is, point& p) {
    is >> p.x_ >> p.y_;
    return is;  // Return the input stream to allow for proper chaining
}

int main() {
    point p(2, 9);
    cout << p << endl;

    // Reading new values into p
    cin >> p;
    cout << "After input: " << p << endl;

    return 0;
};