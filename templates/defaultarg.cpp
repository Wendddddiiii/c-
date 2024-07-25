//template arguments with default arguments
#include <iostream>
#include <vector>
#include <list>
#include <deque>

// T is for type of elements in the stack, CONT is for container type, here default container is std::vector<T>
template<typename T, typename CONT = std::vector<T>>
class stack {
public:
    stack();
    ~stack();
    auto push(const T& value) -> void;  // Changed to const reference
    auto pop() -> void;
    auto top() -> T&;
    auto top() const -> T const&;
    static int num_stacks_;
private:
    CONT stack_;
};

template<typename T, typename CONT>
auto stack<T, CONT>::push(const T& value) -> void {
    stack_.push_back(value);
}

template<typename T, typename CONT>
auto stack<T, CONT>::pop() -> void {
    if (!stack_.empty()) {
        stack_.pop_back();
    }
}

template<typename T, typename CONT>
auto stack<T, CONT>::top() -> T& {
    return stack_.back();
}

template<typename T, typename CONT>
auto stack<T, CONT>::top() const -> T const& {
    return stack_.back();
}

template<typename T, typename CONT>
int stack<T, CONT>::num_stacks_ = 0;

template<typename T, typename CONT>
stack<T, CONT>::stack() {
    num_stacks_++;
}

template<typename T, typename CONT>
stack<T, CONT>::~stack() {
    num_stacks_--;
}

int main() {
    // Uses std::vector<int>
    stack<int> vector_stack;
    vector_stack.push(1);
    vector_stack.push(2);
    vector_stack.push(3);

    // Using list as container
    stack<int, std::list<int>> list_stack;
    list_stack.push(10);
    list_stack.push(20);
    list_stack.push(30);

    // Using deque as container
    stack<float, std::deque<float>> deque_stack;
    deque_stack.push(1.1f);
    deque_stack.push(2.2f);
    deque_stack.push(3.3f);

    // Print the number of stacks for each type
    std::cout << "Number of int stacks (vector): " << stack<int>::num_stacks_ << "\n";
    std::cout << "Number of int stacks (list): " << stack<int, std::list<int>>::num_stacks_ << "\n";
    std::cout << "Number of float stacks (deque): " << stack<float, std::deque<float>>::num_stacks_ << "\n";

    // Demonstrate usage
    std::cout << "Top of vector_stack: " << vector_stack.top() << "\n";
    vector_stack.pop();
    std::cout << "New top of vector_stack after pop: " << vector_stack.top() << "\n";

    std::cout << "Top of list_stack: " << list_stack.top() << "\n";
    list_stack.pop();
    std::cout << "New top of list_stack after pop: " << list_stack.top() << "\n";

    std::cout << "Top of deque_stack: " << deque_stack.top() << "\n";
    deque_stack.pop();
    std::cout << "New top of deque_stack after pop: " << deque_stack.top() << "\n";

    return 0;
}