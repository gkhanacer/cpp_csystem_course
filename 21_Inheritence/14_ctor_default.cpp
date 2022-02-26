#include <iostream>

class Base {
public:

    Base() 
    {
        std::cout << "Base() ctor\n";
    }
    
    ~Base() 
    {
        std::cout << "~Base() dtor\n";
    }
};

class Der : public Base 
{

};

int main(int argc, char const *argv[])
{
    Der myder;

    return 0;
}
