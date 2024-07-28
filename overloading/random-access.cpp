#include <iostream>


template <typename T>

class Iterator {
public:
    using reference = T&;
    using difference_type = int;

    Iterator(T* ptr): ptr_(ptr){}

    Iterator& operator+=(difference_type rhs){
        ptr_ += rhs;
        return *this;
    }

    Iterator& operator-=(difference_type rhs){
        ptr_ -= rhs;
        return *this;
    }

    reference operator[](difference_type index) {
        return *(*this + index);
    }

    friend Iterator operator+(const Iterator& lhs, difference_type rhs) {
        Iterator copy { lhs };
        return copy += rhs;
    }

    friend Iterator operator+(difference_type lhs, const Iterator& rhs) {
        return rhs + lhs;
    }

    friend Iterator operator-(const Iterator& lhs, difference_type rhs) {
        return lhs + (-rhs);
    }
    friend difference_type operator-(const Iterator& lhs, const Iterator& rhs) {
        return lhs.ptr_ - rhs.ptr_;
    }

    friend bool operator<(Iterator lhs, Iterator rhs) {
        return lhs.ptr_ < rhs.ptr_;
    }

    friend bool operator>(Iterator lhs, Iterator rhs) {
        return rhs < lhs;
    }

    friend bool operator<=(Iterator lhs, Iterator rhs) {
        return !(lhs > rhs);
    }

    friend bool operator>=(Iterator lhs, Iterator rhs) {
        return !(lhs < rhs);
    }
    reference operator*() {
        return *ptr_;
    }

    Iterator& operator++() {
        ++ptr_;
        return *this;
    }

    Iterator operator++(int) {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

    //pre decrement
    Iterator& operator--() {
        --ptr_;
        return *this;//after it was decremented
    }

    //post decrement
    Iterator operator--(int) {
        Iterator temp = *this;
        --(*this);
        return temp; //before it was decremented
    }
private:
    T* ptr_;

};


int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Iterator<int> it(arr);

    std::cout << "Initial element: " << *it << '\n'; // 1

    it += 2;
    std::cout << "Element at position 2: " << *it << '\n'; // 3

    it -= 1;
    std::cout << "Element at position 1: " << *it << '\n'; // 2

    Iterator<int> it2(arr + 4);
    std::cout << "Distance between it and it2: " << it2 - it << '\n'; 
    std::cout << "Element at position 3 using operator[]: " << it[2] << '\n'; 

    return 0;
}