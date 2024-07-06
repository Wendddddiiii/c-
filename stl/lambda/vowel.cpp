//to sort a vector of strings by the number os vowels in each string 
//if there is a tie, lexicographically, use a lambda function as a custom comparator

//count vowels 


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype> //for std::tolower

//lambda functions as a helper 
auto count_vowels(const std::string &str) -> int {
    int count = 0;
    for(char ch: str) {
        ch = std::tolower(ch); // convert to lower case
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ++count;
        }
    }
    return count;
}

int main() {
    std::vector<std::string> words = {"banana", "apple", "cherry", "blueberry", "grape"};
    //sort the vector with custom lambda function
    std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
        int vowels_a = count_vowels(a);
        int vowels_b = count_vowels(b);

        if (vowels_a == vowels_b) {
            return a < b; //lexicographical comparison if vowel counts are equal 
        }

        return vowels_a < vowels_b;
    });

    for (const auto &word : words){
        std::cout << word << " ";
    }

    std::cout << std::endl;

    return 0;
}   