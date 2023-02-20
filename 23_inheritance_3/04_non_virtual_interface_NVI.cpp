#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;
// non virtual interface - NVI COK SIK KULLANILIR
class Base {
public:
    void callFunc() { // non virtual interface - NVI
        //code: preprocess  / pre conditions / multithead lock
        vfunc();
        //code: post process / post conditions / class invariants (tum nesneler icin degismez kurallar)
    }
private:
    virtual void vfunc(){ 
        cout << "base " <<  "\n";
    }
};

class Der: public Base {
public:
    void vfunc() override{ // base sinifin private methodu override edilebilir
        cout << "der " << "\n";
    }
};

void foo(Base& baseref) {
    baseref.callFunc();
}

int main(int argc, char const *argv[])
{
    Der der;
    foo(der);
    return 0;
}
