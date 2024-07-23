#include <iostream>
#include <vector>
#include <memory>

class base {
public:
    base(int i, std::string s) : int_member_(i), string_member_(s) {}
    virtual ~base() = default;
    int get_int_member() const { return int_member_; }
    virtual std::string get_class_name() const { 
        return "base";
    }
private:
    int int_member_;
    std::string string_member_;
};

class subclass : public base {  // Use public inheritance
public:
    subclass(int i, std::string s, std::vector<int> v, std::unique_ptr<int> p)
        : base(i, s), vector_member_(v), ptr_member_(std::move(p)) {}

    std::string get_class_name() const override {  // Override virtual function
        return "sub";
    }

    const std::vector<int>& get_vector_member() const {
        return vector_member_;
    }

    const int* get_ptr_member() const {
        return ptr_member_.get();
    }
private:
    std::vector<int> vector_member_;
    std::unique_ptr<int> ptr_member_;  // Fixed typo in variable name
};

void print(const base& b) {  // Pass by reference to avoid slicing and allow polymorphism
    std::cout << b.get_class_name() << " " << b.get_int_member();

    // Try to dynamically cast the base reference to a subclass reference
    if (b.get_class_name() == "sub") {
        const subclass& s = static_cast<const subclass&>(b);
        std::cout << " [Vector: ";
        for (const auto& elem : s.get_vector_member()) {
            std::cout << elem << " ";
        }
        std::cout << "]";
        if (s.get_ptr_member()) {
            std::cout << " [Pointer: " << *(s.get_ptr_member()) << "]";
        } else {
            std::cout << " [Pointer: null]";
        }
    }

    std::cout << std::endl;
}

int main() {
    base b(11, "eleven");
    auto ptr = std::make_unique<int>(42);  // Create a unique_ptr with an integer
    subclass s(22, "two", {1, 2, 3}, std::move(ptr));  // Initialize subclass with unique_ptr
    print(b);
    print(s);  // Passing subclass object to print function

    return 0;
}
