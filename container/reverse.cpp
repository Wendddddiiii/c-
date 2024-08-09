

#include <iostream>
#include <iterator>
using namespace std;
template <typename T>
class Container {
public: 
    Container(T* data, std::size_t size) 
    : data_(new T[size]), size_(size) {
        std::copy(data, data+size, data_);
    }

    ~Container() {
        delete[] data_;
    }
    class Iterator {
    public: 
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;

        Iterator(pointer ptr) : ptr_{ptr} {}
        reference operator*() const {return *ptr_;}
        pointer operator->() const {return ptr_;}

        //prefix increment
        Iterator& operator++() {
            ++ptr_;
            return *this;
        }

        //postfix increment
        Iterator operator++(int) {
            Iterator copy = *this;
            ++(*this);
            return copy;
        }

        //prefix decrement
        Iterator& operator--() {
            --ptr_;
            return *this;
        }

        //postfix decrement
        Iterator operator--(int) {
            Iterator copy = *this;
            --(*this);
            return *this;
        }

        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return lhs.ptr_ == rhs.ptr_;
        }

        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return !(lhs == rhs);
        };
    private:
        pointer ptr_;
    };
    using reverse_iterator = std::reverse_iterator<Iterator>;
    using const_iterator = const Iterator;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    Iterator begin() {return Iterator{data_};}
    Iterator end() {return Iterator{data_ + size_};}
    const_iterator begin() const {return const_iterator{data_};}
    const_iterator end() const {return const_iterator{data_ + size_};}
    const_iterator cbegin() const {return const_iterator{data_};}
    const_iterator cend() const {return const_iterator{data_ + size_};}
    reverse_iterator rbegin() { return reverse_iterator{end()}; }
    reverse_iterator rend() { return reverse_iterator{begin()}; }
    const_reverse_iterator rbegin() const { return const_reverse_iterator{end()}; }
    const_reverse_iterator rend() const { return const_reverse_iterator{begin()}; }
    const_reverse_iterator crbegin() const { return const_reverse_iterator{cend()}; }
    const_reverse_iterator crend() const { return const_reverse_iterator{cbegin()}; }

    
private:
    T* data_;
    std::size_t size_;
};


int main() {
    int data[] = {1, 2, 3, 4, 5};
    Container<int> container{data, 5};

    std::cout << "Forward iteration: ";
    for (const auto& item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse iteration: ";
    for (auto it = container.rbegin(); it != container.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}