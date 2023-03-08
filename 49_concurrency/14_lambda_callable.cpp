#include <thread>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{ 
    int x = 31;
    thread tx {[](int& x) {
        ++x;
    }, ref(x)};
    tx.join();
    std::cout << x << '\n';


    int y = 1;
    thread ty {[](int y) {
        ++y;
    }, y};
    ty.join();
    std::cout << y << '\n';

    return 0;
}
