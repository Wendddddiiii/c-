#include <fstream>
#include <iostream>
#include <iterator>

int main() {
    std::ifstream in("data.in");
    std::istream_iterator<int> begin(in);
    std::istream_iterator<int> end;
    std::cout << *begin++ << std::endl; //read first int

    ++begin; // skip 2nd int
    while(begin != end) {  
        std::cout << *begin++ << std::endl;
    }
}