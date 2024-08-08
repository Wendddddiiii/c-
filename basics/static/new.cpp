#include <iostream>

using namespace std;

class A {
public:
    A(){i = 0;}
    void print() {cout << i << endl;}
    void set(int ii){i=ii;}//can also be {this-> i = i;}
    static void say(int ii){cout << ii  << endl;}
private:
    int k;
    static int i;//静态本地变量实际在全局, class里写的所有东西都是declaration, not definition
};

//静态的函数只能调静态的函数，访问静态成员变量。因为静态函数没有this->,因为希望静态函数在没有this的时候就能被调用。
//this是hidden parameter, this is unavailable for static member func

int A::i;
//只能在这里定义，不能在上面initializer list A():i(0){}定义。initializer list只能对非静态成员做初始化
//全局变量
//静态成员变量必须找一个cpp放这个成员变量
//class的静态成员可能在外部被访问，所以这里不能加static

int main() {
    A a, b;
    a.set(10);
    b.print();
    a.say(0);
    A::say(0);

    return 0;
}

