#include <iostream>

class Myclass {
public:
    Myclass(size_t size)
    : size_(size) {
        std::cout << "constructor called" << std::endl;
    }

    ~Myclass() {
        std::cout << "destructor called" << std::endl;
    }

    //copy constructor
    Myclass(const Myclass& other)
    : size_(other.size_) {
        std::cout << "copy constructor called" << std::endl;
    }

    //copy assignmnet 
    Myclass& operator=(const Myclass& other) {
        std::cout << "copy assignmnet operator" << std::endl;
        if(this != &other) {
            size_ = other.size_;
        }
        return *this;
    }

    //move constructor
    Myclass(Myclass&& other) noexcept 
    : size_(other.size_) {
        std::cout << "move constructor called" << std::endl;
        other.size_ = 0; //set moved_from object to a valid state
    }
    //move assignment
    Myclass& operator=(Myclass&& other) noexcept {
        std::cout << "move assignment called" << std::endl;
        if(this != &other) {
            other.size_ = 0;
        }
        return *this;
    }

    //bool
    bool operator==(const Myclass& other) const {
        return size_ == other.size_;
    }

    bool operator!=(const Myclass& other) const {
            return !(*this == other);
        }

    //swap 
    void swap(Myclass& other) noexcept {
        std::swap(size_, other.size_);
    }
private:
    std::size_t size_;
};

int main() {
    Myclass class1(5);
    Myclass class2(6);
    Myclass class3 = class1; // copy con
    Myclass class4 = std::move(class1); // move constructor
    class3 = class2; // copy ass
    class4 = std::move(class3); // move class3 move assign

}