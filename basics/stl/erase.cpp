//v.erase(pos) v.clear() v.find(first, last, item)
// #include <iostream>
// #include <vector>
// #include <algorithm> // For std::find

// int main() {
//     std::vector<int> v = {1, 2, 3, 4, 5};

//     // Erase a single element
//     v.erase(v.begin() + 2); // Removes the element at index 2 (the number 3)
//     // v now contains: 1, 2, 4, 5
//     std::cout << "Elements in the vector: ";
//     for (int elem : v) {
//         std::cout << elem << " ";
//     }
//     std::cout << std::endl;

//     // Erase a range of elements
//     v.erase(v.begin() + 1, v.begin() + 3); // Removes elements from index 1 to 2 (the numbers 2 and 4)
//     // v now contains: 1, 5

//     std::cout << "Elements in the vector: ";
//     for (int elem : v) {
//         std::cout << elem << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm> // For std::find

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Find an element
    auto it = std::find(v.begin(), v.end(), 3);

    if (it != v.end()) {
        std::cout << "Element found at index: " << std::distance(v.begin(), it) << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
