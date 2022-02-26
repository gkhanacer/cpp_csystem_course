#include <iostream>

class B {
    int x, y;
};

class A {
    B bx;
    int a, b;
};

class C {
public:
    class D {
        int x, y;
    };
    int a, b;
};

class Base {
    int x, y;
};

class Der : Base {
    int a, b;
};

int main(int argc, char const *argv[])
{
    std::cout << "sizeof(B) = " << sizeof(B) << '\n';
    std::cout << "sizeof(A) = " << sizeof(A) << '\n';
    std::cout << "sizeof(C) = " << sizeof(C) << '\n';
    std::cout << "sizeof(D) = " << sizeof(C::D) << '\n';
    std::cout << "sizeof(Base) = " << sizeof(Base) << '\n';
    std::cout << "sizeof(Der) = " << sizeof(Der) << '\n';
    return 0;
}
