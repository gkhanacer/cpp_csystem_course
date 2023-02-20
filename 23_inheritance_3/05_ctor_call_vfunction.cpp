#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;
// non virtual interface - NVI COK SIK KULLANILIR
class Base {
public:
    Base() {
         vfunc(); // D'kkat! Taban sinifin ctor'u icinde yapilan sanal fonksiyon cagirlari varliginda virtual dispatch uygulanmaz. 
    }
    virtual void vfunc(){ 
        cout << "base " <<  "\n";
    }
};

class Der: public Base {
public:
    void vfunc() override{ 
        cout << "der " << "\n";
    }
};

int main(int argc, char const *argv[])
{
    Der der; // Der nesnesi olusturulmadan Base nesnesi olusur.
    return 0;
}
