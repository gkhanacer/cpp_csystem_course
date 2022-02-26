#include <iostream>

// Dilin kuralları net!
// Önce taban sınıfın ctor'u çağrılır, sonra memberların, sonra türemiş sınıfın ctor'u çağrılır.
// Dolayısıyla önce türemiş sınıfın dtor'u, sonra member'ların, sonra base sınıfın dtor'u çağrılır.
// Base ctor
//      Member ctor
//              Der ctor
//              Der dtor
//      Member dtor
// Base ctor

//

class Base {
public:
    Base() 
    {
        std::cout << "Base ctor called" << "\n";
    } 

    ~Base() 
    {
        std::cout << "Base dtor called" << "\n";
    }   
};


class Member {
public:
    Member() 
    {
        std::cout << "Member ctor called" << "\n";
    } 

    ~Member() 
    {
        std::cout << "Member dtor called" << "\n";
    } 
};

class Der : public Base
{
public:
    Der ()  // Önce Base'in default ctor'u çağrılır.
    {
        std::cout << "Der ctor called." << "\n";
    }

    ~Der ()   
    { 
        std::cout << "Der dtor called." << "\n";


        // Derleyici; Base class'ın dtor'unu, Der destructor'un sonuna ekler!
    }  
private:
    Member m;
    // Neco nec; // Birden fazla member varsa, member'ların bildirim sırasına göre nesneler oluşturulur. Tam tersi sırayla yok edilir.
};

int main(int argc, char const *argv[])
{
    Der myder;

    return 0;
}
