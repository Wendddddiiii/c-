//name of constructor is the name of the class
//no return type;
//destructor cannot have parameters
//default constructor: without arguments
//new, delete if new with [], delete has to be delete[]

// #include <iostream>

// using namespace std;

// class A {
// private:
//     int i;
//     int *p;
//     A() {
//         i = 0;
//         cout << "A:A()" << endl;
//     }
//     ~A() {
//         if (p) {
//             delete p;
//             cout << "A:~A(), i = " << i << endl;
//         }
//     }

// public: 
//     void set(int i ) {this->i = i; }
//     void f() {
//         cout << "Hello" << endl;
//     }

//     static A* createArray(int size) {
//         return new A[size];
//     }

//     static void deleteArray(A* p) {
//         delete[] p;
//     }
// };

// int main () {
//     A* p = A::createArray(10);
//     for (int i = 0; i < 10; i++) {
//         p[i].set(i);
//     }
//     A::deleteArray(p);
//     return 0;

// }

#include <iostream>

using namespace std;

class A {
private:
    int i;
    int *p;
    

public: 
    A() {
            p = 0;
            i = 0;
            cout << "A:A()" << endl;
        }
    ~A() {
        if (p) {
            delete p;
        }
        cout << "A:~A(), i = " << i << endl;
    }
    //void set(int i ) {this->i = i; }
    void set(int ii) {i = ii; }
    void f() {
        cout << "Hello" << endl;
    }
    void get(A* q) {cout << q->i; }//can get the private i
};

int main () {
    A* p = new A[10];
    for (int i = 0; i < 10; i++) {
        p[i].set(i);
    }
    A b;
    b.set(100);
    p[0].get(&b);
    delete[] p;
    return 0;

}
// members of a class: private, public, protected
//Private: all members within the class(function of that type)
//Priavte is for a type, not for object 
//同一个类的对象是可以互相访问私有成员变量， 这个限制仅限于编译时刻
//c++的oop特性仅在源代码存在


