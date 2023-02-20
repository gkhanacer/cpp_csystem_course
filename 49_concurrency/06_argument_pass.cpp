#include <thread>
#include <iostream>

void foo(int x, int y, int z) {
    std::cout << x << " " << y << " " << z << '\n';
}

int main(int argc, char const *argv[])
{
    std::thread tx {foo, 4, 10, 30}; // first element: function, remaining part variadic arguments
    tx.join(); 

    return 0;
}
