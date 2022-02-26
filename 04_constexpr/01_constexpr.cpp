#include <iostream>

using namespace std;

int foo() {
    return 5;
}

int g = 10;
int main(int argc, char const *argv[])
{
    // int y = 10;

    // const int z = 10;
    // auto e = z;

    // constexpr int x = y;
    
    // const int x = 10;

    // constexpr int x = foo();

    // constexpr int x = 10;

    // constexpr int y = x + 20;
    // //decltype(x) y = x + 20;

    // const int x = foo();
    // int a[x];

    constexpr int m = 10;
    // m = 20; // sytntax error

    int ival = 100;
    const int* p = &g; // low level const: read only value
    p = &ival;
    // *p = 20; // Read only

    constexpr const int* q = &g; // top & low lever const
    // q = &ival;
    // *q = 90;

    constexpr int* w = &g;
    *w = 10;


    return 0;
}