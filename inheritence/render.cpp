//inheritance 

//resize and destruct have 'virtual'


//define shape
class XYPos{
public: 
    int x, y;
}; // x, y point
class Shape{
public:
    Shape();
    virtual ~Shape();
    virtual void render();//通常用于面向对象编程中的基类（父类）。它声明了一个虚函数（virtual function），表示在子类（派生类）中可以重写这个函数来提供特定的实现。
    void move(const XYPos&);//move 不是virtual的，就只是Shape的函数，不会是Ellipse/Circle的函数
    virtual void resize();

protected:
    XYPos center;
};


//add new shapes
#include <iostream>

class Ellipse: public Shape {
public: 
    Ellipse(float maj, float minr);
    virtual void render();//own protected
protected:
    float major_axis, minor_axis;

};

class Circle: public Ellipse {
public: 
    Circle(float radius): Ellipse(radius, radius) {}
    virtual void render();// 重写基类的render函数
protected:
    float major_axios, minor_axis; // new parameter
};

// 基类 Shape 的构造函数和析构函数实现
Shape::Shape() {}
Shape::~Shape() {}

// polymorphism多态性
// 1. upcast: Ellipse和Circle被当成Shape看待
// 2. Dynamic binding: static binding: call function as the code 
// dynamic binding: call the function of the object运行的时候才知道调用哪个函数，根据指针决定
void render(Shape* p) {
    p->render(); // calls correct render for given Shape
}
// Ellipse 类的 render 函数实现
void Ellipse::render() {
    std::cout << "Rendering Ellipse with major axis: " << major_axis << " and minor axis: " << minor_axis << std::endl;
}

// Circle 类的 render 函数实现
void Circle::render() {
    std::cout << "Rendering Circle with radius: " << major_axis << std::endl; // 对于圆，major_axis 和 minor_axis 是相等的
}

void func(){
    Ellipse ell(10, 20);
    ell.render();
    Circle circ(40);
    circ.render();
    render(&ell);//多态调用
    render(&circ);//多态调用

}


int main() {
    func();
    return 0;
}

