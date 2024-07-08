//difference between member function and virtual function
//1.polymorphsim: virtual function enable runtime polymorphism, while regular member functions do not
//2. override behavior: derived classes can override virtual functions to provide specific implementations
//3. performance: virtual function has overhead
//4. Use virtual functions when you want derived classes to provide their own implementations of a function.

struct vec3 {
    vec3() : vec3(0, 0, 0) {}
    // The explicit keyword is used to prevent implicit conversions.
    // can't implicitly convert a double to a vec3.must explicitly create a vec3 using this constructor.
    // With explicit, you must do: vec3 v(5.0); or vec3 v = vec3(5.0); NOT vec3 v=5.0
    explicit vec3(double c) : vec3(c, c, c) {}
    vec3(double a, double b, double c) : x{a}, y{b}, z{c} {}


    //union is a special class type where all members share the same memory location
    union {
        double x;
        double r;
        double s;
    }; 
    union {
        double y;
        double g;
        double t;
    };
    union {
        double z;
        double b;
        double p;
    };
};
