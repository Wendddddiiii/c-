#include <iostream>
using namespace std;
#include <algorithm> // for std::copy

class my_vec {
public:
    //Constructor
    my_vec(int size):
    data_{new int[size]},
    size_{size},
    capacity_{size}{}


    // Copy constructor
    my_vec(my_vec const& orig)
    : data_{new int[orig.size_]},
        size_{orig.size_},
        capacity_{orig.capacity_} {
        std::copy(orig.data_, orig.data_ + orig.size_, data_);
    }

     // Destructor
    ~my_vec() {
        delete[] data_; 
    }
private:
    int* data_;
    int size_;
    int capacity_;
};

int main() {
    my_vec vec1(10);         // Create an instance of my_vec
    my_vec vec2 = vec1;      // Use copy constructor

    // Your code here to test the functionality

    return 0;
}
