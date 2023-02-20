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
         vfunc();
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
    Der myder; // Der nesnesi olusmadan Base nesnesi olusur.
    Base& rbase = myder; 
    rbase.vfunc(); // der nesnesi olusmustur. RunTime poly.
    return 0;
}
