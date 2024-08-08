#include <memory>
#include <iostream>

int main() {
    auto up1 = std::unique_ptr<int> {new int(10)};
    std::unique_ptr<int> up3;
    //up1 no longer owns memory after release() call
    up3.reset(up1.release());
    auto up4 = std::move(up3);
    std::cout << up4.get() << "\n";
    std::cout << *up4 << "\n";
    //std::cout << *up1 << "\n";

}