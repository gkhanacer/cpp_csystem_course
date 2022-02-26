#include <iostream>

class Base {
protected:
    void func(int) {

    }
};

class Der : public Base {
public:
    void func(int x) { // Forwarder function
        Base::func(x);
    }
};

int main(int argc, char const *argv[])
{
    Der myder;

    myder.func(2); 

    return 0;
}
