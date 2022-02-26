#include <iostream>

class Base {
public:
    Base()
    {
        std::cout << "Base default ctor called" << "\n";
    }  

    Base(const Base& other) 
    {
        std::cout << "Base copy ctor called" << "\n";
    }

    Base(Base&& other) 
    {
        std::cout << "Base move ctor called" << "\n";
    }
};

class Der : public Base  
{
public:
    Der() = default;

    // Der sınıfının move-ctor'u derleyici tarafından implicitly declared yazılmış.
};

int main(int argc, char const *argv[])
{
    Der x;

    Der y = std::move(x); 

    return 0;
}
