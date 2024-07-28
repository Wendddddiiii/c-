//Value Classes:primitive data types, passed to and returned from functions, have overloaded operators
//can be converted to and from other types

//user-defined type conversions
//an object of one class into 1.object of another class 2. a built-in type
//compilers perform implicit conversions using:single argument constructors, implicit type conversion operators

//single argument constructors

// class PathName {
//     string name;

// public:
//     //multi-argument with defaults
//     PathName(const string&);
//     ~ PathName();
// };

// string abc("abc");
// PathName xyz(abc); //Ok!
// xyz = abc; //Ok! abc=> PathName


//Why Use explicit?
//Without the explicit keyword, constructors and conversion operators can be used for implicit type conversions, which can sometimes lead to unexpected behavior or bugs.
//avoid  implicit conversions or copy-initialization, so the constructor can only be used with direct initilaization
