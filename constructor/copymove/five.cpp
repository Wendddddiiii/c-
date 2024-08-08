#include <iostream>
#include <cstring>
#include <utility>

class StringWrapper {
private:
    char* data;

public:
    // Constructor
    StringWrapper(const char* str = nullptr) {
        if (str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = new char[1];
            *data = '\0';
        }
    }

    // Destructor
    ~StringWrapper() {
        delete[] data;
    }

    // Copy constructor
    StringWrapper(const StringWrapper& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy assignment operator
    StringWrapper& operator=(const StringWrapper& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Move constructor
    StringWrapper(StringWrapper&& other) noexcept
        : data(other.data) {
        other.data = nullptr;
    }

    // Move assignment operator
    StringWrapper& operator=(StringWrapper&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // Utility function to print the string
    void print() const {
        std::cout << (data ? data : "null") << std::endl;
    }
};

int main() {
    StringWrapper s1("Hello");
    StringWrapper s2 = s1;  // Copy constructor
    StringWrapper s3;
    s3 = s1;  // Copy assignment
    
    StringWrapper s4 = std::move(s1);  // Move constructor
    StringWrapper s5;
    s5 = std::move(s2);  // Move assignment
    
    s1.print();  // Should print "null" as it was moved from
    s2.print();  // Should print "null" as it was moved from
    s3.print();
    s4.print();
    s5.print();

    return 0;
}