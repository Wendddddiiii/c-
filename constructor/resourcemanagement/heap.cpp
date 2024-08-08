//heap object outlives the scope it was created in
//heap is useful for explicit control of ongoing memory size (e.g. vector as a dynamically sized array)
//stack has limited space on it for storage, heap is larger

#include <iostream>
#include <vector>

int* newInt(int i) {
    int* a = new int{i};//variable a is local to newInt func, the memory that a points to (allocated with new) continues to exist even after the function returns.
    return a;
}

int main() {
    int* myInt = newInt(5);//finished here
    std::cout << *myInt << "\n"; // a was defined in a scope that no longer exists, but the memory a pointed to still valid and accessible through myInt
    delete myInt;
    return 0;
}