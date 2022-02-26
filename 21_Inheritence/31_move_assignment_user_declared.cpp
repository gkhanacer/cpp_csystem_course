#include <iostream>

class Base {
public:
    Base& operator=(const Base& other)
    {
        std::cout << "Base copy assignment called" << "\n";
        return *this;
    }


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

    // Yanlış! Burada Base'in move-assignment fonksiynunun çağrılmasından user sorumludur. Ama çağırlmamış.
    // Der& operator=(Base&& other) 
    // {
    //     std::cout << "Der move assignment called" << "\n";
    //     return *this;
    // }


    // Yanlış! Burada Base'in move-assignment fonksiynunun çağrılmasından user sorumludur. Ama burada copy-assignmet çağrılmıl.
    // Der& operator=(Base&& other) 
    // {
    //     std::cout << "Der move assignment called" << "\n";
    //     Base::operator=(other);
    //     return *this;
    // }

    // Doğru yöntem
    Der& operator=(Base&& other) 
    {
        std::cout << "Der move assignment called" << "\n";
        Base::operator=(std::move(other));
        return *this;
    }
};

int main(int argc, char const *argv[])
{
    Der x, y;

    x = std::move(y); // move-assignment çağrılır

    return 0;
}
