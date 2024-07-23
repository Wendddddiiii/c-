#include <iostream>
#include <vector>
//multiple options are possible for a single catch
//throw by value, catch by const reference
int main() {
    std::cout << "Enter -1 to quit\n";
    std::vector<int> items{11,23,10,89};
    std::cout << "Enter an index: ";
    for(int print_index; std::cin >> print_index;) {
        if(print_index == -1) {
            break;
        }
        try {
            //std::vector::at() throws std::out_of_range by value
            std::cout << items.at(static_cast<unsigned int>(print_index)) << "\n";
            //std::vector::resize() can throw std::length_error by value 
            //it can also throw std::bad_alloc by value if memory allocation fails
            items.resize(items.size() + 10);
        } catch (const std::out_of_range& e) { //catch by const reference 
            std::cout << "Index out of range \n";
        } catch(...) {
            std::cout << "Something else happened";
        }
        std::cout << "Enter an index: ";
    }
}