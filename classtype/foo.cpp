#include <iostream>
#include <string>

class Foo {
public:
    //public constructor
    Foo() : private_data_member_(0), protected_data_member_("five") {
        std::cout << "Default constructor called" << std::endl;
    }

    // Parameterized constructor
    Foo(int value, const std::string& str) 
        : private_data_member_(value), protected_data_member_(str) {
        std::cout << "Parameterized constructor called" << std::endl;
    }

    void public_function() {
        std::cout << "Public function called" << std::endl;
        private_member_function();
    }

    // Public getter for private member
    int get_private_data() const {
        return private_data_member_;
    }

protected:
    // Protected member, accessible by this class and its subclasses
    std::string protected_data_member_;

private:
    //private member function
    void private_member_function() {
        std::cout << "private function called, private data:" << private_data_member_ << std::endl;
    }
    //private data member
    int private_data_member_;

public:
    // Another public section (demonstrating multiple sections of the same name)
    void another_public_function() {
        std::cout << "Another public function called. Protected data: " 
                  << protected_data_member_ << std::endl;
    }
};



// A subclass to demonstrate protected member access
class SubFoo : public Foo {
public: 
    void display_protected_data() {
        std::cout << "protected data in subfoo: " << protected_data_member_ << std::endl;
    }
};

int main() {
    // Using the default constructor
    Foo foo1;
    foo1.public_function();

    //Using the paramaterized constructor
    Foo foo2(42, "Hello");
    foo2.another_public_function();

    std::cout << "private data for foo2: " << foo2.get_private_data() << std::endl;


    SubFoo sub_foo;
    sub_foo.display_protected_data();

    return 0;
}