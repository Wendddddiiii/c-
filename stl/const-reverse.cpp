#include <iostream>
#include <vector>

int main() {
    std::vector<int> ages;
    ages.push_back(18);
    ages.push_back(10);
    ages.push_back(20);

    //std::vector<int>::iterator
    for(auto iter = ages.begin(); iter != ages.end(); ++iter) {
        (*iter)++;
        std::cout << *iter << "\n";

    }

    //std::vector<int>::const_iterator
    for(auto iter = ages.cbegin(); iter != ages.end(); ++iter) {
        //cannot modify
    }

    //std::vector<int>::reverse_iterator
    for(auto iter = ages.rbegin(); iter != ages.rend(); ++iter) {
        std::cout << *iter << "\n";
    }

    //std::vector<int>::const_reverse_iterator
    for(auto iter = ages.crbegin(); iter != ages.crend(); ++iter) {
        //cannot modified
    }
}