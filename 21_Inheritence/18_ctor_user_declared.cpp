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
    // Base class'ın hangi ctor'unun çağrılacağı belirtilmemiş: default ctor Base() çağrılır! 
    // Ama default ctor yoksa, private ise, delete edilmişse SYNTAX ERROR!
    Der ()  
    {

    }

    // Base class'ın hangi ctor'unun çağrılacağı belirtilmemiş: default ctor Base() çağrılır! 
    // Ama default ctor yoksa, private ise, delete edilmişse SYNTAX ERROR!
    Der (int)  
    {

    }
};
