#include <iostream>
#include <vector>

int main() {
    // Create a vector of integers
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using iterator to print all elements
    std::cout << "Printing using iterator:" << std::endl;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using iterator to modify elements
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        *it *= 2; // Double each element
    }

    // Print modified vector using range-based for loop (which uses iterators behind the scenes)
    std::cout << "Modified vector:" << std::endl;
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}