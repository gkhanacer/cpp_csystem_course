#include <iostream>

class Base {
public:
    Base& operator=(const Base& other)
    {
        std::cout << "Base copy assignment called" << "\n";
        return *this;
    }

    // 3. Base move-assignment 
    Base& operator=(Base&& other)
    {
        std::cout << "Base move assignment called" << "\n";
        return *this;
    }
};

class Der : public Base  
{
public:
    Der() = default;

    // 1. Der sınıfının move-assignment fonksiyonu derleyici tarafından implicitly declared yazılmış.
    // 2. Base sınıfın move-assignment fonksyionu çağrılır.
};

int main(int argc, char const *argv[])
{
    Der x, y;

    x = y; // copy-assignment çağrılır.
    x = std::move(y); // move-assignment çağrılır

    return 0;
}
