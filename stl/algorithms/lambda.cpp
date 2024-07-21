#include <iostream>
#include <vector>

void add_n(std::vector<int>& v, int n) {
    std::for_each(v.begin(), v.end(), [n](int& val) {val = val + n;});

}

int main() {
    std::vector<int> v{1, 2, 3};
    add_n(v, 3);
    for (int& num : v){
        std::cout << num << std::endl;
    }
    return 0;
}