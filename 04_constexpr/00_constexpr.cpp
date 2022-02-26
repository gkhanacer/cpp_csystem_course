#include <iostream>

int foo() {
    return 10;
}

int main(int argc, char const *argv[]) {

    const int x = foo();
    // constexpr int x = foo();
    int a[x] = {0};

    return 0;
}