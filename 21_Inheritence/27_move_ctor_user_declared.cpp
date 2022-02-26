#include <iostream>

// Eğer türemiş sınıfın move ctor'u user-declared ise, taban sınıfın move ctor'unun çağrılmasından da user sorumludur.
// Eğer taban sınıfın move-ctor'u çağrılmazsa taşıma gerçekleşmez ve taban sınıfın default ctor'u çağrılır!
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

    // Eksik yöntem
    // Der(Der&&) 
    // {
    // }

    // Yanlış yöntem: copy ctor çağrılır (parametre L-val)
    // Der(Der&& other) : Base(other)
    // {
    // }

    // Doğru yöntem
    Der(Der&& other) : Base(std::move(other))
    {

    }
};

int main(int argc, char const *argv[])
{
    Der x;

    Der y = std::move(x); 

    return 0;
}
