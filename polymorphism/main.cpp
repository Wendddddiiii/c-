//任何一个class如果有virtual func，这个class就会比正常的更大

//polymorphism: 通过指针调用virtual函数才会是动态绑定
//所有oop语言默认virtual,
#include <iostream>
using namespace std;

class A {
public: 
    A(): i(10) {}
    virtual void f() {cout << "A:A()" << i << endl;} 
    int i;   
};

int main () {
    A a, b;
    a.f();
    cout << sizeof(a) << endl;
    int *p = (int*)&a;
    int *q = (int*)&b;

    int *x = (int*)*p;
    p++;
    cout << *x << endl << *p << endl << *q << endl;
    return 0;
}


//another example
class Expr {
public:
    virtual Expr* newExpr();
    virtual Expr& clone();
    virtual Expr self();
};

class BinaryExpr: public Expr {
public: 
    virtual BinaryExpr* newExpr(); // ok
    virtual BinaryExpr& clone(); //ok
    // virtual BinaryExpr self(); //Error!
    //不能返回子类对象本身，只有指针和引用构成upcast => 才能构成polymorphsim
};

