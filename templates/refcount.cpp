#include <iostream>
#include <vector>

template<typename T>
class stack {
private:
    struct Data {
        std::vector<T> elements;
        int refCount;
        Data() : refCount(1) {}
    };

    Data* data;

    void release() {
        if (--data->refCount == 0) {
            delete data;
        }
    }

public:
    stack() : data(new Data()) {}

    stack(const stack& other) : data(other.data) {
        ++data->refCount;
    }

    ~stack() {
        release();
    }

    stack& operator=(const stack& other) {
        if (this != &other) {
            release();
            data = other.data;
            ++data->refCount;
        }
        return *this;
    }

    friend auto operator<<(std::ostream& os, const stack& s) -> std::ostream& {
        for (const auto& i : s.data->elements) {
            os << i << " ";
        }
        return os;
    }

    auto push(T const& item) -> void {
        data->elements.push_back(item);
    }

    auto pop() -> void {
        if (!data->elements.empty()) {
            data->elements.pop_back();
        }
    }

    auto top() -> T& {
        return data->elements.back();
    }

    auto empty() const -> bool {
        return data->elements.empty();
    }
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