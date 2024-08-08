#include <iostream>
#include <vector>

int main(){
    std::vector v{1, 2, 3, 4, 5};
    // Erase all even numbers (C++11 and later)
    for (auto it = v.begin(); it != v.end(); ) {
    if (*it % 2 == 0) {
        it = v.erase(it);
    } else {
        ++it;
    }

    }
    for (auto it : v ) {
        std::cout << it << " ";
    }
    std::cout << "\n";
}


