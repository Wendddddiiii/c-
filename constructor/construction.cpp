#include <iostream>
#include <list>

struct object {
    object() {
        std::cout << "ctor ";
    }

    object(const object &) {
        std::cout << "copy-ctor ";
    }

    ~object() {
        std::cout << "dtor ";
    }
};

int main() {
    // prints ctor dtor
    //
    {
        std::cout << "Pointer: ";
        std::list<object *> l;// Create a std::list of object pointers:
        object x; // Create an object named x
        l.push_back(&x); // This line adds the address of x to the list.
    }
    //When the scope of the block ends here, the destructor for x is called.
    
    
    {
        std::cout << "\nValue: ";
        std::list<object> l;//This creates an empty list of object
        object x;//The default constructor (object()) is called, which outputs "ctor 
        l.push_back(x);//Since std::list stores elements by value, it will call the copy constructor of object to copy x into the list. This outputs "copy-ctor
    }
    //The first dtor output is for the destruction of the object in the list.
    //The second dtor output is for the destruction of x.
    return 0;

}
