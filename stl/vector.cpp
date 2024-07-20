#include <iostream>
#include <vector>

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    std::vector<Point> points;
    points.push_back(Point(1, 2));//aa to the end by copying or moving it 
    points.push_back(Point(11, 22));
    points.emplace_back(3, 4);  // More efficient way to add elements
    points.emplace_back(7, 10);  // More efficient way to add elements
    points.emplace_back(32, 45);  // More efficient way to add elements

    for (const auto& point : points) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }

    return 0;
}
