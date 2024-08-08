#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {4,3,9,10, 11};
    //sort in ascending order
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });

    std::cout << "Ascending order: ";

    for (int num : numbers) {
        std::cout << num << std::endl;

    }

    //sort in descending order
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });

    std::cout << "Descending order: ";

    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}   