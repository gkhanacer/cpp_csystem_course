#include <iostream>

class Base {
public:
    Base& operator=(const Base& other)
    {
        std::cout << "Base copy assignment called" << "\n";
        return *this;
    }
};

class Der : public Base  
{
public:
    Der() = default;

    // Yanlış yöntem! Der'in içindeki Base nesnesi için copy-assignment çağrılmaz!
    // Der& operator=(const Der& other)
    // {
    //     std::cout << "Der copy assignment called" << "\n";
    //     return *this;
    // }

    Der& operator=(const Der& other)
    {
        std::cout << "Der copy assignment called" << "\n";
        
        Base::operator=(other); // boyle yazin.

        static_cast<Base&>(*this) = other; 
        static_cast<Base*>(this)->operator=(other);

        // Aşağıdaki iki çağrı da aynı, recursive çağrıdır.
        // operator=(other); // Yanlış;
        // *this = other; // Yanış 

        return *this;
    }
};

int main(int argc, char const *argv[])
{
    Der x, y;

    x = y;

    return 0;
}
