#include <array>
#include <iostream>

int main() {
    std::array<int, 3> ages{18, 19, 20};
    for (int i = 0; i < ages.size(); ++i) {
        std::cout << ages.at(i) << std::endl;
    }
    for (auto it = ages.begin(); it != ages.end(); ++it) {
        std::cout << *it << std::endl;
    }
    for (const auto& age: ages) {
        std::cout << age << std::endl;
    }
    return 0;
}