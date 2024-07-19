#include <iostream>
#include <memory>

//std::unique_ptr manage single object and ensure sole ownership
//when goes out of scope, deletes the managed object
//cannot be copied but moved


//std::shared_ptr manage a shared ownership of an object
//multiple shared_ptr can point to same object
//object is deleted when the last shared_ptr pointing to it is destroyed

//std::weak_ptr: non-owning reference to an object managed by std::shared_ptr
//Used to break circular references that can occur with shared_ptr

class MyClass {
public:
    MyClass() { std::cout << "MyClass Constructor\n"; }
    ~MyClass() { std::cout << "MyClass Destructor\n"; }
};

int main() {
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();
    // std::unique_ptr<MyClass> ptr2 = ptr1; // Error: cannot copy unique_ptr
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1); // Valid: transfers ownership

    std::shared_ptr<MyClass> ptr3 = std::make_shared<MyClass>();
    {
        std::shared_ptr<MyClass> ptr4 = ptr3;
        std::cout << "Inside block\n";
    } // ptr2 goes out of scope, but ptr1 still owns the object
    std::cout << "Outside block\n";


    std::shared_ptr<MyClass> ptr5 = std::make_shared<MyClass>();
    std::weak_ptr<MyClass> weakPtr = ptr5;
    if (auto sharedPtr = weakPtr.lock()) {
        std::cout << "Object is still alive\n";
    } else {
        std::cout << "Object has been destroyed\n";
    }


    return 0;
}
