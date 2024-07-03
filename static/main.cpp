//static in c++:1.static storage 2. visibility of a name 3.don't use static except inside functions and classes
//static means 1. hidden: a static member is a member obeys usual access rules
//and 2. persistent: independent of instances
//静态的成员函数只能访问静态的成员函数或静态的成员变量， 因为静态成员函数没有this


#include <iostream>
using namespace std;

class A {
public:
    A() {i = 0; }
    void print() { cout << i << endl; }    
    void set(int ii) { i = ii; }

private:
    static int i;
};

// Definition of the static member variable
int A::i = 0;

int main() {
    A a,b;
    a.set(10);
    b.print();// This will print 10 because i is shared among all instances

    return 0;
}
