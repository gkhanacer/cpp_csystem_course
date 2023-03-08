#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void foo(int& r) {
    ++r;
    std::cout << r << '\n';
}

int main(int argc, char const *argv[])
{ 
    auto fp = foo;

    int x {43};
    thread tx {fp, ref(x)};

    tx.join();
    std::cout << x << '\n';

    return 0;
}
