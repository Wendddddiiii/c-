//承载函数和默认函数
//to define a function with an argument list, defaults must be added from right to left

int harpo(int n, int m = 4, int j = 5);


//illegal
int harpo(int n, int m = 4, int j);


//default argument 
void f(int i, int j = 0);

inline int plusOne(int x);
inline int plusOne(int x) {return ++x;}

// 加了inline在.h file表示不是definition, 是declaration
