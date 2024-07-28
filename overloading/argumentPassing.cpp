#include <iostream>

// *this is used within a member function to refer to the object for which the member function is called
// *this: dereference this pointer, and point to the object

class Integer {
private:
    int i;

public:
    Integer(int value) : i(value) {}

    // Prefix increment operator
    const Integer& operator++() {
        *this += 1;
        return *this;
    }

    // Postfix increment operator
    // int argument not used so leave unnamed to avoid compiler warnings
    const Integer operator++(int) {
        Integer old(*this); // fetch
        ++(*this);          // increment   
        return old;         // return
    }

    // Equality operator
    bool operator==(const Integer& rhs) const {
        return i == rhs.i;
    }

    // Implement lhs != rhs in terms of !(lhs == rhs)
    bool operator!=(const Integer& rhs) const {
        return !(*this == rhs);
    }

    // Less than operator
    bool operator<(const Integer& rhs) const {
        return i < rhs.i;
    }

    // Implement lhs > rhs in terms of lhs < rhs
    bool operator>(const Integer& rhs) const {
        return rhs < *this;
    }

    // Less than or equal to operator
    bool operator<=(const Integer& rhs) const {
        return !(rhs < *this);
    }

    // Greater than or equal to operator
    bool operator>=(const Integer& rhs) const {
        return !(*this < rhs);
    }
};

int main() {
    Integer lhs(5);
    Integer rhs(10);

    if (lhs != rhs) {
        std::cout << "lhs and rhs are not equal." << std::endl;
    } else {
        std::cout << "lhs and rhs are equal." << std::endl;
    }

    return 0;
}

/* 
Calling the != Operator: 
Integer lhs, rhs;
bool result = lhs != rhs;

*this dereferences the pointer, providing a reference to the lhs object itself

Why *this Can Represent lhs:
this is a pointer to the object for which the member function is called (in this case, lhs).
Dereferencing this with *this gives you the object itself (i.e., lhs).
*/
