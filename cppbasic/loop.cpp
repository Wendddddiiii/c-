#include <iostream>
#include <string>
#include <vector>

auto all_comp(std::vector<std::string> const& names) -> bool {
    auto const famous_pyh = std::string("John");
    auto const famous_math = std::string("Holland");

    for(auto const& name : names) {
        if (name == famous_math or name == famous_pyh) {
            return false;
        }
    }
    return true;
}

auto square(int n) {
    return n * n;
}

auto cube(int n) {
    return n * n * n;
} 

auto square_vs_cube(int n) -> bool {
    //0 and 1 are special cases, since they are actually equal.
    if (square(0) != cube(0) or square(1) != cube(1)) {
        return false;
    }

    for (auto i = 2; i < 100; ++i) {
        if (square(i) == cube(i)) {
            return false;
        }
    }
    return true;
}


int main() {
    // Test all_comp function
    std::vector<std::string> names1 = {"Alice", "Bob", "Charlie"};
    std::vector<std::string> names2 = {"Alice", "John", "Charlie"};
    std::vector<std::string> names3 = {"Alice", "Bob", "Holland"};

    std::cout << "All comp test 1: " << (all_comp(names1) ? "true" : "false") << std::endl;
    std::cout << "All comp test 2: " << (all_comp(names2) ? "true" : "false") << std::endl;
    std::cout << "All comp test 3: " << (all_comp(names3) ? "true" : "false") << std::endl;

    // Test square and cube functions
    int num = 3;
    std::cout << num << " squared: " << square(num) << std::endl;
    std::cout << num << " cubed: " << cube(num) << std::endl;

    // Test square_vs_cube function
    bool result = square_vs_cube(num);
    std::cout << "Square vs Cube test for " << num << ": " << (result ? "true" : "false") << std::endl;

    // Additional tests for square_vs_cube
    std::cout << "Square vs Cube test for 0: " << (square_vs_cube(0) ? "true" : "false") << std::endl;
    std::cout << "Square vs Cube test for 1: " << (square_vs_cube(1) ? "true" : "false") << std::endl;
    std::cout << "Square vs Cube test for 5: " << (square_vs_cube(5) ? "true" : "false") << std::endl;

    return 0;
}