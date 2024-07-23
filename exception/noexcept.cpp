#include <iostream>

class SafeString {
private:
    char* data;
    size_t length;

public:
    //copy constructor with noexcept
    //intializer list
    SafeString(const SafeString& other) noexcept
        :data(nullptr), length(0)
    {
        if(other.length > 0) {
            //this returns nullptr on failure instead of throwing
            data = new(std::nothrow) char[other.length + 1];
            if (data) {
                std::memcpy(data, other.data, other.length + 1);
                length = other.length;
            }
        }
    }
    //Copy Assignment with noexcept (using copy-and-swap idiom) 
    // Swap function (noexcept)
    void swap(SafeString& other) noexcept {
        std::swap(data, other.data);
        std::swap(length, other.length);
    }

    // Copy assignment operator using copy-and-swap
    SafeString& operator=(const SafeString& other) noexcept {
        SafeString temp(other);  // Copy constructor is noexcept
        swap(temp);              // swap is noexcept
        return *this;
    }

};