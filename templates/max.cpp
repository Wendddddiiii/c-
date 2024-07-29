#include <iostream>

// int max(int x, int y) {
//     return (x > y) ? x : y;
// }

// double max(double x, double y) {
//     return (x > y) ? x : y;
// }

// char max(char x, char y) {
//     return (x > y) ? x : y;
// }

template<typename T, typename U>
auto max(T x, U y) {
    return (x > y) ? x : y;
}


int main() {
    std::cout << max(1, 2.3) << std::endl;
    return 0;
}