#include<memory>
#include<iostream>


int main() {
    auto up1 = std::unique_ptr<int>{new int{15}};
    *up1 = 21;
    std::cout<< *up1 << std::endl;
    auto op1 = up1.get();
    *op1 = 66;
    std::cout << *op1 << std::endl;
    up1.reset(); // up1 reset leads to op1 becomes a dangling pointer, the pointer it points to has been freed
    std::cout << *op1 << std::endl;
}