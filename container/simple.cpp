#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
class SimpleContainer {
public:
    SimpleContainer(T* data, std::size_t size)
    : data_(data), size_(size) {}

    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;

        Iterator(pointer ptr): ptr_{ptr} {} 

        reference operator*() const {return *ptr_;}
        pointer operator->() const {return ptr_;}

        //prefix increment
        Iterator& operator++(){
            ++ptr_;
            return *this;
        }

        //postfix increment
        Iterator operator++(int) {
            Iterator temp = *this;
            //this->++ptr_;
            ++(*this); // call the prefix increment operator
            return temp;
        }
        friend bool operator==(const Iterator&lhs, const Iterator&rhs) {
            return lhs.ptr_ == rhs.ptr_;
        }
        friend bool operator!=(const Iterator&lhs, const Iterator&rhs) {
            return !(lhs == rhs);
        }
    private:
        pointer ptr_;
    };
    // Reverse Iterator class
    class ReverseIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;

        ReverseIterator(pointer ptr) : ptr_{ptr} {}

        reference operator*() const { return *ptr_; }
        pointer operator->() const { return ptr_; }

        // Prefix decrement
        ReverseIterator& operator++() {
            --ptr_;
            return *this;
        }

        // Postfix decrement
        ReverseIterator operator++(int) {
            ReverseIterator copy = *this;
            --(*this);  // Calls the prefix decrement operator
            return copy;
        }

        friend bool operator==(const ReverseIterator& lhs, const ReverseIterator& rhs) {
            return lhs.ptr_ == rhs.ptr_;
        }

        friend bool operator!=(const ReverseIterator& lhs, const ReverseIterator& rhs) {
            return !(lhs == rhs);
        }

    private:
        pointer ptr_;
    };

    Iterator begin() {return Iterator{data_};}
    Iterator end() {return Iterator{data_ + size_};}

    ReverseIterator rbegin() { return ReverseIterator{data_ + size_ - 1}; }
    ReverseIterator rend() { return ReverseIterator{data_ - 1}; }
private:
    T* data_;
    std::size_t size_;
};

int main() {
    auto vs = std::vector<int> {1, 2, 3, 4, 5};
    SimpleContainer<int> container{vs.data(), vs.size()};
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " " << std::endl;
    }
    for (auto& value : container) {
        std::cout << value << std::endl;
    }

    // Reverse iteration
    std::cout << "Reverse iteration: ";
    for (auto it = container.rbegin(); it != container.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}