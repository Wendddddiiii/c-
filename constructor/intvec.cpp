#include <iostream>
#include <vector>

class intvec {
public:
    //constructor
    explicit intvec(std::vector<int>::size_type length)
    : vec_(length, 0) {
        std::cout << "Constructor called" << std::endl;
    }
    //destructor
    ~intvec() {
        std::cout << "destructor called" << std::endl;
    }
    //copy constructor
    intvec(const intvec& other)
    : vec_(other.vec_) {
        std::cout << "copy constructor called" << std::endl;
    } 

    //copy assignment
    // use const here to ensure Source object should not change
    intvec& operator=(const intvec& other) {
        std::cout << "copy assignmnet operator" << std::endl;
        if(this != &other) {
            vec_ = other.vec_;
        }
        return *this;
    }

    //move constructor 
    intvec(intvec&& other) noexcept
    : vec_(std::move(other.vec_)) {
        std::cout << "move constructor called" << std::endl;
    }

    //move assignment
    intvec& operator=(intvec&& other) noexcept{
        std::cout << "move assignment oeprator" << std::endl;
        if(this != &other) {
            vec_ = std::move(other.vec_);
        }
        return *this;
    }

    bool operator==(const intvec& other) const {
        return vec_ == other.vec_;
    }

    bool operator!=(const intvec& other) const {
        return !(*this == other);
    }
private:
    std::vector<int> vec_;
};

int main() {
    auto a = std::vector<int> {55, 11};
    auto b = intvec(a.size()); // constructor
    auto c = b; //copy constructor
    auto d = std::move(b); // move constructor
    c = d; // copy assignment
    d = std::move(c); // move assignment
    if (d != c) {               // Inequality operator
        std::cout << "d and c are not equal" << std::endl;
    } 
    return 0;
}
