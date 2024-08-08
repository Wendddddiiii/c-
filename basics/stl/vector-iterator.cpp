#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names = {"Hello", "world"};

    for(auto iter = names.begin(); iter != names.end(); ++iter) {
        std::cout << *iter << std::endl;
    }

    for (std::vector<std::string>::iterator it = names.begin(); it != names.end(); ++it ) {
        std::cout << *it << std::endl;
    }
    
}