#include <iostream>


// Eğer türemiş sınıfın cc'si user-declared olursa, Base sınıfın kopyalanmasından programcı sorumlu olur.
// Eğer taban sınıfın cc'si çağrılmazsa, taban sınıfın default ctor'u çağrılır!
class Base {
public:
    Base() 
    {
        std::cout << "Base default ctor called" << "\n";
    };  

    Base(const Base& other) 
    {
        std::cout << "Base copy ctor called" << "\n";
    }
};

class Der : public Base  
{
public:
    Der() = default;
    
    // Eksik yöntem:
    // Der(const Der& other) // DİKKAT! Burada taban sınıfın copy ctor'u çağrılmamış. Öyleyse taban sınıfın default ctor'u çağrılacak.
    // {
    //     std::cout << "Der copy ctor called" << "\n";
    // }

    // Doğru yöntem:
    Der(const Der& other) : Base(other)
    {
        std::cout << "Der copy ctor called" << "\n";
    }
};

int main(int argc, char const *argv[])
{
    Der x;

    Der y = x;

    return 0;
}
