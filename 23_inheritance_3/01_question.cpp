#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;
// erisim kontrolu statik ture iliskin. virtual dispatch / runtime polymorphosm ile hic bir ilgisi yok
class Base {
public:
    virtual void func(int x = 99){ 
        cout << "base " << x << "\n";
    }
};

class Der: public Base {
private:
    void func(int x = 11){
        cout << "der " << x << "\n";
    }
};

void foo(Base& baseref) {
    baseref.func();
}

int main(int argc, char const *argv[])
{
    Der der;
    foo(der);
    return 0;
}
