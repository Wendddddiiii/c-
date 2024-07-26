#include <vector>
#include <iostream>
#include <numeric>

template <typename T>
class stack{
public:
    auto push(T t) -> void {stack_.push_back(t);}
    auto top() -> T& {return stack_.back();}
    auto pop() -> void {stack_.pop_back();}
    auto size() const ->  std::size_t { return stack_.size();}
    auto sum() -> int {return std::accumulate(stack_.begin(), stack_.end(), 0);}
private:
    std::vector<T> stack_;
};

int main() {
    int i1 = 6771;
    int i2 = 9313;

    stack<int> s1;
    s1.push(i1);
    s1.push(i2);
    std::cout << s1.size() << std::endl;
    std::cout << s1.top() << " ";
    std::cout << s1.sum() << "\n";
}
