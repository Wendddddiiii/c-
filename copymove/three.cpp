//rule of three:
//If a class requires a user-defined destructor, copy constructor, or copy assignment operator, it probably requires all three.


#include <iostream>
#include <cstring>

class StringWrapper {
private:
    char* data;

public:
    //Constructor
    StringWrapper(const char* str = nullptr) {
        if(str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = new char[1];
            *data = '\0';
        }
    }

    //~Destructor
    ~StringWrapper() {
        delete[] data;
    }

    //copy constructor: called when creating a new object 
    StringWrapper(const StringWrapper& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    //copy assignment operator: Called when assigning to an existing object.need to handle (delete) existing data
    StringWrapper& operator=(const StringWrapper& other) {
        if(this != &other) { // check for self-assignment
            delete[] data;// free existing memory before assigning new memory to avoid memory leaks
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this; // pointer to a current object, derefence gives object itself
    }

    //utility function to print the string
    void print() const {
        std::cout << data << std::endl;
    }
};

int main() {
    StringWrapper s1("Hello");
    StringWrapper s2 = s1; //copy constructor
    StringWrapper s3;
    s3 = s1; // copy assignment

    s1.print();
    s2.print();
    s3.print();
    return 0;
}