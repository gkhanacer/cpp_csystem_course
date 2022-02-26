#include <iostream>

class Base {
public:
    Base() = default;  

    Base(const Base& other) // 4. Taban sınıfın da cc'si çağrılıyor. 
    {
        std::cout << "Base copy ctor called" << "\n";
    }
};

class Der : public Base  // 1. Türemiş sınıfın cc'si implicitly declared.
{
    // 3. Derleyicinin Der sınıfı için yazdığı cc, taban sınıfın cc'sini çağırır.
    // Eğer Taban sınıfın cc'si private veya delete edilmiş olsaydı, derleyici Der için yazacağı cc'yi delete ederdi.
};

int main(int argc, char const *argv[])
{
    Der x;

    Der y = x; // 2. copy init ile y oluşturuluyor.

    return 0;
}
