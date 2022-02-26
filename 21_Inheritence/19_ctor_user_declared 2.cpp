#include <iostream>

class Base {
public:
    Base() 
    {
        std::cout << "Base() ctor" << "\n";
    }   
};

class Der : public Base
{
public:
    Der ()  
    {
        // Bu kodlar çalışıyorsa Base nesnesi oluşmuştur!
        std::cout << "ctor icindeki kodlar." << "\n";
    }    
};

int main(int argc, char const *argv[])
{
    Der myder;
    return 0;
}
