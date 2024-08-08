//copy:Creates a new, independent copy of the resource.
//move: Transfers ownership of the resource from one object to another.


//other.data = nullptr; other.size = 0;
//Leaving a Valid State: Setting data to nullptr and size to 0 leaves the moved-from object in a known, valid state. This is important because:
// It prevents double deletion of the same memory when the moved-from object is destroyed.
// It ensures that any subsequent use of the moved-from object (while not recommended) doesn't lead to undefined behavior or accessing freed memory.

#include <iostream>
#include <cstring>
#include <utility>

class MyString {
private:
    char* data;
    size_t size;

public:
    // Constructor
    MyString(const char* str = "") {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Copy constructor
    MyString(const MyString& other) : size(other.size) {
        std::cout << "Copy constructor called" << std::endl;
        data = new char[size + 1];
        strcpy(data, other.data);
    }

    // Move constructor
    MyString(MyString&& other) noexcept : data(other.data), size(other.size) {
        std::cout << "Move constructor called" << std::endl;
        other.data = nullptr;
        other.size = 0;
    }

    // Copy assignment operator
    MyString& operator=(const MyString& other) {
        std::cout << "Copy assignment called" << std::endl;
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new char[size + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Move assignment operator
    MyString& operator=(MyString&& other) noexcept {
        std::cout << "Move assignment called" << std::endl;
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // Function to display string
    void display() const {
        std::cout << "String: " << (data ? data : "null") << ", Size: " << size << std::endl;
    }
};

// Function to return a MyString object
MyString createString(const char* str) {
    return MyString(str);
}

int main() {
    // Copy examples
    std::cout << "Copy examples:" << std::endl;
    MyString s1("Hello");
    MyString s2 = s1;  // Copy constructor
    s1.display();
    s2.display();

    MyString s3;
    s3 = s1;  // Copy assignment
    s3.display();

    std::cout << "\nMove examples:" << std::endl;
    // Move examples
    MyString s4 = std::move(s1);  // Move constructor
    s1.display();  // s1 is now in a moved-from state
    s4.display();

    MyString s5;
    s5 = createString("World");  // Move assignment
    s5.display();

    return 0;
}