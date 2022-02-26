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

    // Der sınıfının copy-assignment fonksiyonu derleyici tarafından implicitly declared yazılmış.
};

int main(int argc, char const *argv[])
{
    Der x, y;

    x = y;

    return 0;
}
