#include <compare>
#include <iostream>

class point {
public:
    point(int x, int y)
    : x_{x}
    , y_{y} {}

    // hidden friend - preferred
    // return type deduced as std::strong_ordering
    friend auto operator<=>(point p1, point p2) = default;

private:
    int x_;
    int y_;
};

auto main() -> int {
    auto const p2 = point{1, 2};
    auto const p1 = point{1, 2};
    std::cout << "p1 == p2 " << (p1 == p2) << '\n';
    std::cout << "p1 != p2 " << (p1 != p2) << '\n';
    std::cout << "p1 < p2 " << (p1 < p2) << '\n';
    std::cout << "p1 > p2 " << (p1 > p2) << '\n';
    std::cout << "p1 <= p2 " << (p1 <= p2) << '\n';
    std::cout << "p1 >= p2 " << (p1 >= p2) << '\n';
}