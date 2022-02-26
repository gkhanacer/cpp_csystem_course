#include <iostream>

class Base {
protected:
    void func(int) {

    }
};

class Der : public Base {
private:
};

int main(int argc, char const *argv[])
{
    Der myder;

    // myder.func(2); // Client kodlar protected alana erişemez.


    return 0;
}
