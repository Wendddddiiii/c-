#include <iostream>
class stringptr {
public:
    explicit stringptr(std::string const& s) 
        :ptr_{new std::string(s)}
    {
    }

    ~stringptr() {
        delete ptr_;
    }

    std::string* operator->() const {
        return ptr_;
    }

    std::string& operator*() const {
        return *ptr_;
    }
private:
    std::string* ptr_;
};

int main() {
    auto p = stringptr("smartpointer");
    std::cout << *p << std::endl;
    std::cout << p->size() << std::endl;
};
