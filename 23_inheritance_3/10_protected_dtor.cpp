#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

class Base {
protected:
    ~Base() { // Protected dtor. Non-virtual
        cout << "base dtor" <<  "\n";
    }

public:
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
    Base* p = new Der; // Kullaniciyi Der* p = new Der; seklinde kullanmaya zorladik.
    p->vfunc();
    delete p; // SYNTAX ERROR
 
    // Der* p = new Der; // Kullaniciyi Der* p = new Der; seklinde kullanmaya zorladik.
    // p->vfunc();
    // delete p; // NO PROBLEM

    return 0;
}
   