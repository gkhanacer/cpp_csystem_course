#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void func(const std::ostream& os) {

}

int main(int argc, char const *argv[])
{ 
    // thread tx {func, std::cout}; // Syntax Error! ostream is closed to copy.
    thread tx {func, ref(std::cout)}; // OKAY
    tx.join();

    return 0;
}
