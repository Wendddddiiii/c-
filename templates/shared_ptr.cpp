#include <iostream>
#include <vector>
#include <memory>



template<typename T>
class stack {
public:
    // s1 and s2 will share the same underlying data because they share the same std::shared_ptr to the vector 
    stack() : data(std::make_shared<std::vector<T>>()) {}

    friend auto operator<<(std::ostream& os, const stack& s) -> std::ostream& {
        for (const auto& i : *(s.data)) {
            os << i << " ";
        }
        return os;
    }

    auto push(T const& item) -> void {
        data->push_back(item);
    }

    auto pop() -> void {
        if (!data->empty()) {
            data->pop_back();
        }
    }

    auto top() -> T& {
        return data->back();
    }

    auto empty() const -> bool {
        return data->empty();
    }

private:
    std::shared_ptr<std::vector<T>> data;
};

int main() {
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    stack<int> s2 = s1;
    std::cout << "s1: " << s1 << "s2: " << s2 << std::endl;
    s1.pop();
    s1.push(3);
    std::cout << "s1: " << s1 << "s2: " << s2 << std::endl;
}