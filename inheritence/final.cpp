// add final for never gets overriden

#include <iostream>

using namespace std;

class Foo {
public:
    //virtual indicates a method can be overridden in a derived class
    virtual void print() final {cout << "Hello!";}
    virtual void foo(int x) {
        cout << x << endl;
    }
};


class Bar : public Foo {
public:
    void foo(int x) override {
        cout << x * x << endl;
    }
};



int main() {

    Bar b;
    b.foo(3); 
    return 0; 
}