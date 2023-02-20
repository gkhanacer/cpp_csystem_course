#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

class Base {
public:
    ~Base() {
        cout << "base dtor" <<  "\n";
    }
    virtual void vfunc(){ 
        cout << "base vfunc" <<  "\n";
    }
};

class Der: public Base {
public:
    ~Der() {
        cout << "Der dtor" <<  "\n";
    }
    void vfunc() override{ 
        cout << "der vfunc" << "\n"; 
    }
};

int main(int argc, char const *argv[])
{
    // With new operator & base class pointer PROBLEM!!!!
    Base* p = new Der;
    p->vfunc();
    delete p;  // delete operator calls the dtor of Base (not Der), then uses "operator delete"

    // With new operator & Der class pointer NO PROBLEM
    // Der* p = new Der;
    // p->vfunc();
    // delete p; // delete operator calls the dtor of Der and Base consequently, then uses "operator delete"

    // Taban siniflarin dtor'lari ya public virtual olsun, ya da protected non-virtual olsun (boylelikle nesne Der ila olusturulur)
    
    return 0;
}
   