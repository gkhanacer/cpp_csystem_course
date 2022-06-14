#include <iostream>

template <int x>
class Myclass {

};

int main(int argc, char const *argv[])
{
    Myclass<10> a;
    Myclass<20> b;

    //  a = b; // syntax error
    return 0;
}
