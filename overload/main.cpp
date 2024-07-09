#include <iostream>
#include <istream>


//need  to overload an operator for a const and non-const version
// class MyContainer {
// private: 
//     int data[10];
// public: 
//     //getter version(const)
//     const int& operator[](int index) const {
//         return data[index];
//     }

//     //setter version(non-const)
//     int& operator[](int index){
//         return data[index];
//     }
// };

class vec3 {
public:
    //overloaded subscript operator
    //operator[] allows objects of vec3 to be indexed like arrays, like v[1]
    // elems_ is an array fo double elements
    // elems_[n] accesses the n-th element of the elems array
    //returns reference to an element, which is double&(can both read and modify)
    auto operator[](int n) const -> const double& { return elems_[n]; }

    //friend function declaration for the input stream extraction operator
    //the function has access to the private members of the vec3 class
    friend auto operator>>(std::istream &is, vec3 &v) -> std::istream&;

private:
    double elems_[3] = {0, 0, 0}; //any instance of vec3 will have an array of three doubles, all initially set to 0
};

auto operator>>(std::istream &is, vec3 &v) -> std::istream& {
    for (int i = 0; i < 3; ++i) {
        is >> v.elems_[i];
    }
    return is;
}

// fill the 3 elems of v via a standard algorithm.
// return "is" for chaining.
auto operator>>(std::istream &is, vec3 &v) -> std::istream& {
    //std::istream_iterator<double>(is): Creates an input iterator that reads double values from the input stream is
    //std::istream_iterator<double>{} default-constructed input iterator for reading double values from an input stream
    //v.elems_: The destination array where the values are to be copied.
    std::copy(std::istream_iterator<double>{is}, std::istream_iterator<double>{}, v.elems_);
    return is;
}



int main() {
    vec3 v;
    std::cout << "Enter three numbers: ";
    std::cin >> v;
    std::cout << "You entered: " << v[0] << ", " << v[1] << ", " << v[2] << std::endl;
    return 0;
}

//const-correct: indicate which data should not be modified after initialization
//e.g. constant pointers and pointers to constants
//pointer to constant: const int* ptr; value pointed to by ptr cannot be modified
//constant pointer: int* const ptr; the pointer ptr cannot point to a different address

