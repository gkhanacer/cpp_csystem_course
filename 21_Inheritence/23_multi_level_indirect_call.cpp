#include <iostream>

class Base {
public:
    Base() 
    {
        std::cout << "Base ctor called" << "\n";
    }  

    Base(int) // 1. Böyle bir ctor daha eklendi.
    {
        std::cout << "Base(int)  ctor called" << "\n";
    }  

    ~Base() 
    {
        std::cout << "Base dtor called" << "\n";
    }
};

class Der : public Base
{
public:
    Der ()
    {
        std::cout << "Der ctor called." << "\n";
    }

    ~Der() 
    {
        std::cout << "Der dtor called" << "\n";
    }
};

class Nec : public Der 
{
public:
    Nec () : Base(12) // 2. Böyle bir bildirim olabilir mi? HAYIR Syntax Error! c.i.l ile Inirect olarak taban sınıf çağrılamaz, sadece direct olarak çağrılır.
    {
        std::cout << "Nec ctor called." << "\n";
    }

    ~Nec() 
    {
        std::cout << "Nec dtor called" << "\n";
    }
};

int main(int argc, char const *argv[])
{
    Nec nec;

    Base* p = &nec; // Nec is a Base. Yazılabilir. Base sınıfı, Nec sınıfının taban sınıfıdır (indirect base class)

    Base mybase;
    //Nec* p = &mybase; // Syntax Error! Her Base bir Nec değildir.

    return 0;
}
