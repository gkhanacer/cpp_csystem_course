#include <iostream>

class Base {
private: // 2. Default ctor private. Base class'ın default ctor'u deleted edilir. Base() = delete;
    Base() 
    {
        std::cout << "Base() ctor\n";
    }

public:    
    ~Base() 
    {
        std::cout << "~Base() dtor\n";
    }
};

class Der : public Base // 1. Default ctor implicitly declared. Base class'ın default ctor'u çağrılır. Ama erişemiyor.
{

};

int main(int argc, char const *argv[])
{
    // Der myder; // Syntax Error!

    return 0;
}
