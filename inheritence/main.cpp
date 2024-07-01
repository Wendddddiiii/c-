#include <iostream>

using namespace std;
class A {
public: 
    A(int ii): i(ii) {cout << "A:A()" << endl; }
    ~A() {cout << "A::~A()" << endl; }
    void print() {cout << "A::print()" << i << endl; }
    void print(int i) {cout << i; print(); }
    void set(int ii) {i = ii; }
private:
    int i; 
};

class B: public A {
public:
    B(): A(15) {
        cout << "B::B()" << endl;
    } //initializer list 
    ~B() {cout << "B::~B()" << endl;}
    void print() {cout << "B::print()" << endl; }

    void f() { set(20); print(); }
};

int main() {
    B b;
    b.set(10);
    b.print();
    b.f();
    return 0;
}