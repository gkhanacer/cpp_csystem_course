#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

class Base {
public:
    virtual ~Base() {
        cout << "base dtor" <<  "\n";
    }

    // virtual ~Base() = default; // Virtual dtor can be defaulted.

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
    //PROBLEM is solved base class' virtual dtor

    // Taban siniflarin dtor'lari ya public virtual olsun, ya da protected non-virtual olsun (boylelikle nesne Der ila olusturulur, 
    // kullaniciya sentax hatasi gorunur.)

    // With new operator & base class pointer
    Base* p = new Der;
    p->vfunc();
    delete p; // delete operator calls the dtor of Der and Base consequently, then uses "operator delete"

    // With new operator & base class pointer
    // Base* p = new Der;
    // p->vfunc();
    // delete p; // delete operator calls the dtor of Der and Base consequently, then uses "operator delete"

    // Without new operator
    // Der myder;
    // Base& base = myder;

    return 0;
}
   