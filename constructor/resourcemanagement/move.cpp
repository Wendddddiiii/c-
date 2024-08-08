#include <iostream>

class my_vec{
public:
    //constructor
    my_vec(int size): data_(new int[size]), size_(size), capacity_(size) {}
    
    //destructor
    ~my_vec() {
        delete[] data_; // properly deallocate the array
    }

    //disable copy constructor and assignment operator
    my_vec(const my_vec&) = delete;
    my_vec& operator=(const my_vec&) = delete;

    //move constructor
    my_vec(my_vec&& other) noexcept
        :data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        }


    //move assignment operator
    my_vec& operator=(my_vec&& other) noexcept {
        if(this != &other) {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

private:
    int* data_;
    int size_;
    int capacity_;
};