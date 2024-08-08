#include <iostream>
#include <vector>
#include <algorithm> // for std::transform
#include <cctype>    // for std::toupper
char to_upper(unsigned char value) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(value)));
}



int main() {
    std::string s = "hello world!";
    std::for_each(s.begin(), s.end(), toupper);

    std::string upper;
    std::transform(s.begin(), s.end(), std::back_inserter(upper), to_upper);

    return 0;
}

