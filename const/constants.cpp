
#include <iostream>
using namespace std;

class A {
    const int i;
public:
    A(): i(0) {}
    void f() { cout << "f()" << endl; }

    void f() const { cout << "f() const" << endl; }
    //不会构成overload
};

int main() {
    const A a;
    a.f();

    return 0; 
}
//no pointer to references
//illegal int&* p;
//-reference to pointer is ok
void f(int*& p);

//Polymorphism
