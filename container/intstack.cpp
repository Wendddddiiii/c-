/*
The iterator traits
The overloaded operators (*, ->)
The equality operators
The constructor (default to nullptr)
The private data
The iterator is defined inside the class, so gets access to private data
Iterator defines the container as a friend class for the constructors
Key points in the List Class:
begin() – returns an Iterator object
end() – returns an Iterator object (with nullptr as private data)
Note: The Iterator Class does not modify the List/Node data except through returning references.
*/

#include<iostream>
#include<algorithm>
#include <iterator>
#include<memory>
#include<utility>

using namespace std;

class IntStack{
private:
    struct Node {
        Node(int value, std::unique_ptr<Node>&& next)
        : value{value}
        , next{std::move(next)}{}
        int value;
        std::unique_ptr<Node> next;
    };
    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = int;
        using reference = int&;
        using pointer = int*;
        using difference_type = std::ptrdiff_t;

        reference operator*() const {
            return node_-> value;
        }

        pointer operator->() const {
            return &(operator*());
        }

        Iterator operator++() {
            node_ = node_->next.get();
            return *this;
        }

        Iterator operator++(int) {
            auto copy{*this};
            ++(*this);
            return copy;
        }

        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return lhs.node_ == rhs.node_;
        }

        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return !(lhs == rhs);
        }
    private:
        explicit Iterator(Node* node)
        : node_{node} {}
        Node* node_;
        friend class IntStack;
    };
public:
    using iterator = Iterator;
    using const_iterator = const Iterator;
    iterator begin() {
        return iterator{head_.get()};
    }
    const_iterator begin() const {
        return cbegin();
    }

    const_iterator cbegin() const {
        return const_iterator{head_.get()};
    }

    iterator end() {
        return iterator{nullptr};
    }

    const_iterator end() const {
        return cend();
    }

    const_iterator cend() const {
        return const_iterator{nullptr};
    }

    void push(int value) {
        head_ = std::make_unique<Node>(value, std::move(head_));
    }

    void pop() {
        if(head_) {
            head_ = std::move(head_->next);
        }
    }

    const int& top() const {
        if(!head_) {
            throw std::out_of_range("Stack is empty");
        }
        return head_->value;
    }

    int& top() {
        if(!head_) {
            throw std::out_of_range("Stack is empty");
        }
        return head_->value;
    }

    bool empty() const {
        return head_ == nullptr;
    }

private: 
    std::unique_ptr<Node> head_;

};

int main() {}