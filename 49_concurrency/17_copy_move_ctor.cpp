#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void func() {}

int main(int argc, char const *argv[])
{ 
    thread tx;
    // thread ty(tx); // Syntax Error! The copy ctor/assignment is deleted for thread class.
    // thread ty = tx;

    std::cout << std::boolalpha;

    // There is no problem for move semantic
    thread ta {func};
    thread tb{ std::move(ta)}; 
    std::cout << ta.joinable() << '\n';
    std::cout << tb.joinable() << '\n';
    tb.join();

    return 0;
}
