class MyClass {
public:
    // Setter (Non-const version)
    auto operator[](char c) -> int& {
        return c == '^' ? numerator_ : denominator_;
    }

    // Getter (Const version)
    auto operator[](char c) const -> const int& {
        return c == '^' ? numerator_ : denominator_;
    }

private:
    int numerator_ = 0;
    int denominator_ = 1;
};

int main() {
    MyClass obj;

    // Using the setter to modify values
    obj['^'] = 10; // Modifies numerator_
    obj['*'] = 20; // Modifies denominator_

    // Using the getter to read values
    const MyClass constObj;
    int num = constObj['^']; // Reads numerator_
    int den = constObj['*']; // Reads denominator_

    // constObj['^'] = 10; // Error: cannot modify as constObj is const

    return 0;
}
