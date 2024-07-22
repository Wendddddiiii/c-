#include <iostream>

class Cache {
private:
    int data;
    mutable int accessCount;

public:
    Cache(int d) : data(d), accessCount(0) {}

    int getData() const {
        accessCount++;  // Modifying mutable member in const function, wont change state
        return data; //data cannot be modified as it will change the object's state(logic)
    }

    int getAccessCount() const {
        return accessCount;
    }
};

int main() {
    const Cache cache(42);
    
    std::cout << "Data: " << cache.getData() << std::endl;
    std::cout << "Access count: " << cache.getAccessCount() << std::endl;
    
    std::cout << "Data: " << cache.getData() << std::endl;
    std::cout << "Access count: " << cache.getAccessCount() << std::endl;
    
    return 0;
}
