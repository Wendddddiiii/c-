#include <iostream>
#include <string>

class person {
public:
    person(std::string const& name, int const age);
    auto get_name() -> std::string const&;
    auto get_age() -> int const&;
private:
    std::string name_;
    int age_;
};

person::person(std::string const& name, int const age) {
    name_ = name;
    age_ = age;
}

auto person::get_name() -> std::string const& {
    return name_;
}

auto person::get_age() -> int const& {
    return age_;
}

int main() {
    auto p = person {"Poppi", 11};
    std::cout << p.get_name() << "\n";
}