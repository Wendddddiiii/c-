//Friends: grant access to a function that is not a member of the structure
// the class itself controls which code has access to its members
//can declare a global function as a friend, can be a member function of another class, or even an entire class. As a friend


struct X; //first declares X, then can declare Y
struct Y {
    void f(X*);
};

struct X {
private:
    int i;
public: 
    void initialize();
    friend void g(X*, int); // global friend
    friend void Y::f(X*); //struct member friend
    friend struct Z; //Entire struct is a friend
    friend void h();
};

void X::initialize() {
    i = 0;
}

void g(X* x, int i) {
    x-> i = i;
}

void Y::f(X* x) {
    x -> i = 47;
};

struct Z {
private:
    int j; 
};


//class v.s. struct
//class defaults to private
//struct defaults to public
//一般首选class
