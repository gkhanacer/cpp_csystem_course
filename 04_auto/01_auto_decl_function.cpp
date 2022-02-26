#include <iostream>

using namespace std;

void foo(int);

int main(int argc, char const *argv[])
{
    auto f1 = foo;
    auto &f2 = foo;
    
    return 0;
}
