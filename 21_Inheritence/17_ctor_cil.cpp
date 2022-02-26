#include <iostream>

class Base {
public:
    Base(int x) 
    {
        std::cout << "Base(int) ctor x: " << x << "\n";
    }

    Base(double a) 
    {
        std::cout << "Base(double) ctor a: " << a << "\n";
    }

    Base(int a, int b) 
    {
        std::cout << "Base(int, int) ctor a: " << a << " b: << " << b << "\n";
    }
};

class Der : public Base
{
public:
    // Der() : Base(12) {} // c.i.l. ile parametreli ctor çağrılır. Önce Base ctor çalışır.
    // Der() : Base{3.4} {}
    Der() : Base{10, 20} {}

    Der(int x) : Base {x, x} {}
};

int main(int argc, char const *argv[])
{
    Der myder; 

    Der myder2(12.5);
    
    return 0;
}
