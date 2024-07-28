//MyType b;拷贝构造 Copying
//MyType a=b; //赋值
//a=b;
#include<iostream>
using namespace std;
class Fi {
public:
    Fi() {}
};

class Fee {
public:
    Fee(int) {}
    Fee(const Fi&){}
};

int main() {
    Fee fee = 1; //Fee(int)
    Fi fi;
    Fee fum = fi; //Fee(Fi)
    fum = fi;
}

//Memberwise Assignment: When an object is assigned to another object of the same type, each member of the object on the left-hand side of the assignment is assigned the value of the corresponding member of the object on the right-hand side. 
//also called default assignment operator
class MyClass {
public:
    int a;
    double b;

    MyClass(int x, double y) : a(x), b(y) {}
};

int main2() {
    MyClass obj1(5, 3.14);
    MyClass obj2(0, 0);
    obj2 = obj1; // Memberwise assignment
    // obj2.a is 5 and obj2.b is 3.14
    return 0;
}

//Assignment Operator
//for classes wuth dynamically allocated memory decalre an assignmnet opeartor (and a copy constructor)
//To prevent assignment, explicitly decalre operator= as private


