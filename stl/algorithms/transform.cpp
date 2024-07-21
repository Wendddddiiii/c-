#include <iostream>
#include <vector>
#include <algorithm> // for std::transform
#include <cctype>    // for std::toupper
char to_upper(unsigned char value) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(value)));
}

//startofInput, endofInput, startofDes, UnaryOperation:apply to each element in the input range
template< class InputIt, class OutputIt, class UnaryOperation >
OutputIt transform( InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op );


int main() {
    std::string s = "Hello world!";
    //algorithm transform uses the other iterator as an output
    auto upper = std::string(s.size(), '\0');//create an output same size as s, initialized with null characters \0.
    std::cout << "init upper: " << upper << std::endl;

    std::transform(s.begin(), s.end(), upper.begin(), to_upper);
    std::cout << upper << std::endl;

    return 0;
}

//unsigned int:non-negative int: 0 ~ 2^32 - 1 unsigned char: 0~255
//use static_cast is because std::toupper is designed to take an int but within range of unsigned char or EOF
