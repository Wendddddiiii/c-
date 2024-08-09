#include <iostream>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <stdexcept>

template <typename T>

class Vector {
private:
    T* data_;
    std::size_t size_;
    std::size_t capacity_;

    void reallocate(std::size_t new_capacity) {
        T* new_data = new T[new_capacity];
        std::copy(data_, data_ + size_, new_data);
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }
public: 
    class Iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        //Iterator(pointer ptr) : ptr_(ptr) {}
        explicit Iterator(T* ptr) : ptr_(ptr) {}
        reference operator*() const { return *ptr_; }
        pointer operator->() const {return ptr_; }
        Iterator& operator++() {
            ++ptr_; 
            return *this;
        }
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }
        Iterator& operator--() {
            --ptr_;
            return *this;
        }
        Iterator operator--(int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        Iterator& operator+=(difference_type n) {
            ptr_ += n;
            return *this;
        }

        Iterator& operator-=(difference_type n) {
            ptr_ -= n;
            return *this;
        }


        Iterator& operator+(difference_type n) const {
            return Iterator{ptr_ + n};
        }


        Iterator& operator-(difference_type n) {
            return Iterator{ptr_ - n};
        }

        difference_type operator-(const Iterator& other) const {
            return ptr_ - other.ptr_;
        }

        reference operator[] (difference_type n ) {
            return ptr_[n];
        }

        friend bool operator==(const Iterator& lhs, const Iterator& rhs) { return lhs.ptr_ == rhs.ptr_; }
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return lhs.ptr_ != rhs.ptr_; }
        friend bool operator<(const Iterator& lhs, const Iterator& rhs) { return lhs.ptr_ < rhs.ptr_; }
        friend bool operator>(const Iterator& lhs, const Iterator& rhs) { return lhs.ptr_ > rhs.ptr_; }
        friend bool operator<=(const Iterator& lhs, const Iterator& rhs) { return lhs.ptr_ <= rhs.ptr_; }
        friend bool operator>=(const Iterator& lhs, const Iterator& rhs) { return lhs.ptr_ >= rhs.ptr_; }

        friend Iterator operator+(difference_type n, const Iterator& it) {
            return Iterator(it.ptr_ + n); 
        }
    private:
        pointer ptr_;
    };

    Vector() : data_(nullptr), size_(0), capacity_(0) {}
    explicit Vector(std::size_t size) 
    : data_(new T[size]), size_(size), capacity_(size) {
        std::fill(data_, data_+size_, T());
    }

    ~Vector() {delete[] data_;}

    Vector(const Vector& other) 
    : data_(new T[other.size]), size_(other.size_), capacity_(other.size_){
        std::copy(other.data_, other.data_+size_, data_);
    }

    Vector& operator=(const Vector& other) {
        if(this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.size_;
            data_ = new T[size_];
            std::copy(other.data_, other.data_ + size_, data_);
        }
        return *this;
    }

    void push_back(const T& value) {
        if(size_ == capacity_) {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    void pop_back() {
        if(size_ > 0) {
            --size_;
        }
    }

    T& operator[](std::size_t index) {
        if(index >= size_) {
            throw std::out_of_range("Index is out of range.");
        }
        return data_[index];
    }

    const T& operator[](std::size_t index) const {
        if(index >= size_) {
            throw std::out_of_range("Index is out of range.");
        }
        return data_[index];
    }

    std::size_t size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

    Iterator begin() {
        return Iterator(data_);
    }

    Iterator end() {
        return Iterator(data_ + size_);
    }

    const Iterator begin() const {
        return Iterator(data_);
    }

    const Iterator end() const {
        return Iterator(data_ + size_);
    }
};

int main() {
    Vector<int> vec;
    for(int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    std::cout << "Random access: ";
    for (std::size_t i = 0; i < vec.size(); i += 2) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
