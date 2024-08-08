// Use Case
// cbegin is particularly useful when:

// You want to ensure that the container's elements are not modified during iteration.
// You are working in a context where read-only access is required or preferred.
// You are passing containers to functions that should not modify their elements.


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


auto vsort(std::vector<std::string> &vs) -> void {
    std::sort(vs.begin(), vs.end(), [](const std::string &a, const std::string &b) {
    const auto vowels = [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    auto acount = std::count_if(a.cbegin(), a.cend(), vowels);
    auto bcount = std::count_if(b.cbegin(), b.cend(), vowels);
    return acount == bcount ? a < b : acount < bcount;
    });
}


int main() {
    std::vector<std::string> words = {"banana", "apple", "cherry", "blueberry", "grape"};
    vsort(words);

    for (const auto &word : words){
        std::cout << word << std::endl;
    }

    return 0;
}
