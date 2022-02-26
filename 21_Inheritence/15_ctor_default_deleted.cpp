#include <iostream>

class Base {
public:

    // 2. Base class'ın default ctor'u deleted edilmiş. Base() = delete;
    Base(int) 
    {
        std::cout << "Base(int) ctor\n";
    }

    ~Base() 
    {
        std::cout << "~Base() dtor\n";
    }
};

class Der : public Base  // 1. Default ctor implicitly declared. Base class'ın default ctor'u çağrılır.
{

};

int main(int argc, char const *argv[])
{
    // Der myder; // 3. Yeni nesne oluşturulursa HATA! Oluşturulmazsa hata yok. 
    
    return 0;
}
