#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>
#include <iostream>

class my_vec {
public:
    //default constructor
    my_vec() : data_(nullptr), size_(0), capacity_(0) {}

    //constructor with size 
    explicit my_vec(std::size_t size) : data_(new int[size]), size_(size), capacity_(size) {
        std::fill_n(data_, size_, 0);
    } 

    //constructor with initializer list
    my_vec(std::initializer_list<int> init) 
        :data_(new int[init.size()]), size_(init.size()), capacity_(init.size()) {
            std::copy(init.begin(), init.end(), data_);
        }
    //destructor 
    ~my_vec() {
        delete[] data_;
    }


    //disable copy constructor and assignment operator
    my_vec(const my_vec&) = delete;
    my_vec& operator = (const my_vec&) = delete;

    //move constructor
    my_vec(my_vec&& other) noexcept
        :data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
    
    //move assignment operator
    my_vec& operator=(my_vec&& other) noexcept {
        if (this != &other) {
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

    //element access
    int& at(std::size_t pos) {
        if (pos >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[pos];
    }

    const int& at(std::size_t pos) const {
        if(pos >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[pos];
    }

    int& operator[](std::size_t pos) {return data_[pos];}
    const int& operator[](std::size_t pos) const {return data_[pos];}

    //capacity
    bool empty() const { return size_ == 0;}
    std::size_t size() const { return size_; }
    std::size_t capacity() const { return capacity_; }
    

    //modifier
    void push_back(int value) {
        if(size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    void pop_back() {
        if(empty()) {
            throw std::out_of_range("Vector is empty");
        }
        --size_;
    }

    void clear() {size_ = 0;}
    
    void reserve(std::size_t new_capacity) {
        if(new_capacity > capacity_) {
            int* new_data = new int[new_capacity];
            std::copy(data_, data_ + size_, new_data);
            delete[] data_;
            data_  = new_data;
            capacity_ = new_capacity;
        }
    }

    void resize(std::size_t new_size) {
        if(new_size > capacity_) {
            reserve(new_size);
        }
        if(new_size > size_) {
            std::fill(data_ + size_, data_ + new_size, 0);
        }
        size_ = new_size;
    }

private:
    int* data_;
    std::size_t size_;
    std::size_t capacity_;
};



int main() {
    my_vec v = {1, 2, 3, 4, 5};
    
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << std::endl;
    
    v.push_back(6);
    std::cout << "After push_back: Size: " << v.size() << ", Capacity: " << v.capacity() << std::endl;
    
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    
    v.pop_back();
    std::cout << "After pop_back: Size: " << v.size() << std::endl;
    
    try {
        std::cout << "Element at index 2: " << v.at(2) << std::endl;
        std::cout << "Element at index 10: " << v.at(10) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}