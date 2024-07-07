#include <iostream>
#include <vector>
#include <algorithm>
#include <span>
#include <float>


//std::rotate
auto second(std::vector<int> &v, std::vector<int>::iterator new_first) {
    auto copy = std::vector<int>(v.begin(), new_first);
    v.erase(v.begin(), new_first);
    return v.insert(v.end(), copy.begin(), copy.end());//(insertion point, start of range to insert, end of range)
}
// iterators are objects that point to elements in a container, like a vector, similar to pointer
// std::vector<int>(v.begin(), new_first) both inputs are iterators
// they represent a range, The range is defined as [v.begin(), new_first), and this constructor creates a new vector by copying elements from this range. 
// new_first is an iterator pointing to some element in v (passed as an argument to the function).


// Helper function to print vectors
void printVector(const std::vector<int>& v) {
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}



int main() {
    // Example 1: Rotate by 2 positions
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::cout << "Example 1 - Before: ";
    printVector(v1);
    
    auto it1 = v1.begin() + 2;  // Points to the element 3
    second(v1, it1);
    
    std::cout << "Example 1 - After:  ";
    printVector(v1);

    // Example 2: Rotate by 3 positions
    std::vector<int> v2 = {10, 20, 30, 40, 50, 60};
    std::cout << "\nExample 2 - Before: ";
    printVector(v2);
    
    auto it2 = v2.begin() + 3;  // Points to the element 40
    second(v2, it2);
    
    std::cout << "Example 2 - After:  ";
    printVector(v2);

    // Example 3: Rotate by 1 position
    std::vector<int> v3 = {100, 200, 300};
    std::cout << "\nExample 3 - Before: ";
    printVector(v3);
    
    auto it3 = v3.begin() + 1;  // Points to the element 200
    second(v3, it3);
    
    std::cout << "Example 3 - After:  ";
    printVector(v3);

    return 0;
}


auto third(std::span<float> floats) {
    auto v = std::vector<float>{};
    for (auto f : floats) {
        v.push_back(f);
    }
    //can be replaced by 
    auto v - std::vector<float>{};
    std::copy(floats.begin(), floats.end(), std::back_inserter(v));

    auto m = std::numeric_limits<float>::max();
    for (auto f : v) {
        if (f < m) m = f;
    }

    auto M = std::numeric_limits<float>::min();
    for (auto f : v) {
        if (M < f) M = f;
    }

    return std::make_pair(m, M);

    //can be replaced by 
    auto [min_it, max_it] = std::minmax_element(v.begin(), v.end());
    return std::make_pair(*min_it, *max_it);
}
