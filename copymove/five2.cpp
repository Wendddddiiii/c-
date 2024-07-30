#include <iostream>

using namespace std;

class Foo {
private:
    int* array, size;
public:
    //constructor
    Foo(int s) {
        size = s;
        array = new int[size]{0};
    }

    //copy constructor 
    // Foo f(g); where  g is a Foo
    // Foo f = g;
    Foo (const Foo& rhs) {
        cout << "Copy constructor: " << endl;
        size = rhs.size;
        array = new int[size];

        for(int i = 0; i < size; i++) {
            array[i] = rhs.array[i];
        }
    }

    //move constructor
    //for dealing with rvalues
    //no const here becoz we will change current temp obj pointer to null
    //one & for copy constructor, two && for move constructor
    // Foo(Foo&& rhs) noexcept {
    //     cout << "move constructor" << endl;
    //     size = rhs.size;
    //     //assign to lvalue object memory address of temp object
    //     array = rhs.array;
    //     rhs.size = 0;
    //     rhs.array = nullptr;
    // }
    // Move constructor
    Foo(Foo&& rhs) noexcept : size(rhs.size), array(rhs.array) {
        cout << "Move constructor" << endl;
        rhs.array = nullptr;
        rhs.size = 0;
    }


    //destructor
    ~Foo() {
        if(array) {
            delete[] array;
        }
    }

    //concatenation f+g cause an r-value to be created
    Foo operator+(const Foo& rhs) {
        Foo temp(size + rhs.size);
        auto i = 0;

        // the first part of temp array contains everything in f
        for(; i < size; i++) {
            temp[i] = array[i];
        }

        // the second part of temp array contains everything in g
        //copy contents of g object into remaining portion of temp object array
        for(auto j = 0; j < rhs.size; i++, j++) {
            temp[i] = rhs.array[j];
        }
        return temp;
    }

    // copy assignment operator
    // f = g; replace f object array with a COPY of g object array
    Foo& operator=(const Foo& rhs) {
        // check if f == g 
        cout << "Copy assignment operator: " << endl;
        if(this == &rhs) {
            return *this; // do nothing
        } 
        if(array) {
            delete[] array;
        }
        // create a new one to allocate the g object array
        size = rhs.size;
        array = new int[size];

        // make sure size of g is correct 
        for(int i = 0; i < size; i++) {
            array[i] = rhs.array[i];
        }
        return *this;
    }

    //move assignment operator 
    Foo& operator=(Foo&& rhs) noexcept {
        cout << "move assignmnet operator" << endl;
        if (this != &rhs) {
            delete[] array;
            size = rhs.size;
            array = rhs.array;
            rhs.array = nullptr;
            rhs.size = 0;
        }

        return *this;
    }


    int& operator[](int i) {
        return array[i];
    }

    int length() const {
        return size;
    }

    friend ostream& operator<<(ostream& o, const Foo& rhs) {
        for(int i = 0; i < rhs.size; i++) {
            o << rhs.array[i] << endl;
        } 
        return o;
    }

    void printState() const {
        cout << "Size: " << size << ", Array: ";
        if (array) {
            for (int i = 0; i < size; i++) {
                cout << array[i] << " ";
            }
        } else {
            cout << "nullptr";
        }
        cout << endl;
    }
};



int main() {
    Foo f(5);
    for (int i = 0; i < f.length(); i++) {
        f[i] = 3 * i;
    }
    cout << "f: " << f << endl;

    Foo g(f);
    cout << "g: " << g << endl;

    Foo h(3);
    cout << "h (initial): " << h << endl;

    // Capture the temporary object
    Foo tempFromAddition = f + g;  // Capture the temporary object

    // Test move assignment
    h = std::move(tempFromAddition);  // Move-assign to h
    cout << "h state after move assignment: ";
    h.printState();

    // Since tempFromAddition has been moved from, it is in an unspecified state
    // Attempting to print its state directly is not meaningful. But for completeness:
    cout << "tempFromAddition state after move assignment: ";
    tempFromAddition.printState();

    // Test move constructor explicitly
    Foo temp = std::move(h); // Should invoke move constructor

    // Print state of h after move construction
    cout << "h state after move construction: ";
    h.printState();

    // Print state of temp after move construction
    cout << "temp state after move construction: ";
    temp.printState();

    return 0;
}



//move constructor is called when a new obj is created using an existing
//obj that is being moved from

//move assignment is used to assign the resource of an existing obj
//to another existing obj