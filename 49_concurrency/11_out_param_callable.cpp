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
    int x {43};
    thread tx {foo, ref(x)};

    tx.join();
    std::cout << x << '\n';

    return 0;
}
