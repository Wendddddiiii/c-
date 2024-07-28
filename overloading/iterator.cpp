#include <vector>

//cannot modify a vector while iterate through it 
//cannot erase elements from a vector while iterating through it
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v {1, 2, 3, 4, 5};

    // Collect elements to add
    std::vector<int> to_add;
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (*it == 2) {
            to_add.push_back(11);
        }
    }
    // Add elements after the iteration
    v.insert(v.end(), to_add.begin(), to_add.end());

    // Print vector before removal
    std::cout << "Vector before removal: ";
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Use erase-remove idiom to safely remove elements
    v.erase(std::remove(v.begin(), v.end(), 2), v.end());

    // Print vector after removal
    std::cout << "Vector after removal: ";
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
