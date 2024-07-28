
#include <cstdint>
#include <iostream>
class i32 {
public:
    i32(int32_t i = 0): i_(i) {}


    //conversion to bool for logical operations
    operator bool() const {
        return i_!=0;
    }
    //Overloaded logical AND operator
    friend i32 operator&&(const i32 &lhs, const i32 &rhs) {
        return i32(lhs.i_ && rhs.i_);
    }

    //Overloaded logical OR operator
    friend i32 operator||(const i32 &lhs, const i32 &rhs) {
        return i32(lhs.i_ || rhs.i_);
    }


private:
    int32_t i_;
};

int main() {
    i32 a(1);//non-zero value, cosnidered true
    i32 b(0); // Zero value, considered false
    i32 c(2); // Non-zero value, considered true

    bool result_and = a && b; // Expected to be false
    bool result_or = a || b;  // Expected to be true
    bool result_combined = (a && b) || c; // Expected to be true
    // Output results
    // Set boolalpha flag to output true/false instead of 1/0
    std::cout << std::boolalpha;
    std::cout << "a && b: " << result_and << std::endl;
    std::cout << "a || b: " << result_or << std::endl;
    std::cout << "(a && b) || c: " << result_combined << std::endl;

    return 0;
}
