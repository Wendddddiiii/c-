#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

int main() {
    std::vector<int> nums { 1, 2, 3, 4, 5 };
    auto it = std::find(nums.begin(), nums.end(), 1);
    if (it != nums.end()) {
        std::cout << "find it: " << *it << std::endl;
    } else {
        std::cout << "No " << *it << " in the vector" << std::endl;
    }
    auto midpoint = nums.begin() + static_cast<int>(nums.size() / 2);
    std::cout << "mid point: " << *midpoint << std::endl;

    int sum2 = std::accumulate(nums.begin(), midpoint, 0);
    std::cout << "Sum2 : " << sum2 << "\n";
    int sum3 = std::accumulate(midpoint, nums.end(), 0);
    std::cout << "Sum3 : " << sum3 << "\n";

    int sum1 = std::accumulate(nums.begin(), nums.end(), 0); // 0 is the initial value
    int product = std::accumulate(nums.begin(), nums.end(), 3, std::multiplies<int>()); // 1 is the initial value, std::multiplies<int>() is the operation
    std::vector<std::string> words { "Hello", "world", "this", "is", "C++" };   
    std::string sentence = std::accumulate(words.begin(), words.end(), std::string(),
                                           [](const std::string& a, const std::string& b) {
                                               return a.empty() ? b : a + " " + b;
                                           });

    std::cout << "Sum: " << sum1 << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Sentence: " << sentence << std::endl;
    return 0;
}
