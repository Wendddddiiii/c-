#include <iostream>

using namespace std;

// void printNumber(int* numberPtr) {
//     cout << *numberPtr << endl;
// }

// void printLetter(char* charPtr) {
//     cout << *charPtr << endl;
// }

void print(void* ptr, char type) {
    switch(type) {
        case 'i':
            cout << *((int*)ptr) << endl; //handle int*
            break;
        case 'c':
            cout << *((char*)ptr) << endl;//handle char*
            break;

    }
}

int main() {
    int number = 5;
    char letter = 'f';
    print(&number, 'i');
    print(&letter, 'c');

    return 0;
}