#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

class Base {
public:
    void func(){
        cout << "base\n";
    }
};

class Der: public Base {
public:
    
    void func(){
        cout << "der\n";
    }
};

int main(int argc, char const *argv[])
{
    Der der;

    //Base::func();
    der.Base::func();
    //Der::func();

    Base * base = new Der;
    Der *d;

    // d = base;
    d = static_cast<Der*>(base);
    // d = dynamic_cast<Der*>(base); // not polymorphic class 

    return 0;
}
