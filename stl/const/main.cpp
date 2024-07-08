



const int x = 123;

x = 27;
x++;

int y = x;
y = x;

const int z = y; 

// 加extern 是说明是定义在某处的全局变量 声明
// extern const int bufsize和 bufsize本身是否是const无关
// a Pointer may be a const 
char * const q = "abc"; // q is a const
*q = 'c'; //ok 
q++; // error

const char *p = "ABCD"; // (*p) is a const char； // p所指向的内存是const
//(*p) is a const char
*p = 'b'; //error! 
p++; //ok
//不能通过p修改指向的内存单元，并不是指向哪里 哪里就变成const
Person p1("Fred", 200);
const Person* p = &p1;//对象是const
Person const* p = &p1;//对象是const//same as above, p is a pointer to const Person.
//This means cannot modify the Person objects through p, but can change pointer p to point to a different Person object.

Person *const p = &p1;//指针是const
//* 在前 指针是const *在后 对象是const
//p is a const pointer to a Person.
//This means cannot change the pointer p to point to a different Person object



