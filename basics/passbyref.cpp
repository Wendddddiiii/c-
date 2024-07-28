#include <iostream>

auto swap(int& x, int& y) -> void {
    auto const tmp = x;
    x = y;
    y = tmp;
}


auto main() -> int {
    auto i = 1;
    auto j = 2;
    std::cout << i << ' ' << j << std::endl;
    swap(i, j);
    std::cout << i << ' ' << j << std::endl;

}