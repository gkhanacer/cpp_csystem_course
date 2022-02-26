#include <iostream>

class Base {
public:
    Base() 
    {
        std::cout << "Base ctor called" << "\n";
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
    Nec ()
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

    return 0;
}
