#include <iostream>

class Base {
private: 
    void func(int a) {
        std::cout << "Base::foo(int)\n";
    }
    int mx;

protected:
    void f() {
        std::cout << "Base::f()\n";
    }
};

class Der : public Base {
public:
    void foo() {
        // auto val = mx; // Syntax Error! mx türemiş sınıfta bulunamaz. Base sınıfta bulunur. namelookup biter. context kontolü geçer. Ama access kontrole takılır. 
        f();
    }
};

int main(int argc, char const *argv[])
{
    Der myder;
    myder.foo(); 

    Base mybase;
    // mybase.f(); // Syntax Error! Inaccessible.
    return 0;
}
