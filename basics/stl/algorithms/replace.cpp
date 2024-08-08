#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 2, 5, 2, 6};
    
    // Replace all 2's with 9
    std::replace(numbers.begin(), numbers.end(), 2, 9);
    
    // Print the result
    for (int num : numbers) {
        std::cout << num << " ";
    }
    // Output: 1 9 3 9 5 9 6
    
    return 0;
}