#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 33, 24, 4, 6};

    //sort the vector in descending order using a lambda function
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });

    //print sorted numbers
    for (int num : numbers) {
        std::cout << num << " " << std::endl;

    }
    return 0;
}