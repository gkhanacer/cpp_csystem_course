#include <iostream>

class Base {
public: 
    void foo();
    void func();
    int mx;
    static int s;

    class Nested {

    };
};

class Der : public Base {

};

int main(int argc, char const *argv[])
{
    Der myder;
    myder.foo();
    myder.func();
    myder.mx = 10;
    
    Der::s = 2;

    Der::Nested nes;
    return 0;
}
