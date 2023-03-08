#include <thread>
#include <iostream>
#include <vector>

using namespace std;

class  Myclass {
public:
    Myclass() = default;
    Myclass(const Myclass&) 
    {
        std::cout << "copy ctor\n";
    }
    void func(int x, int y) 
    {
        std::cout << x << " " << y << "\n";
    }
};

int main(int argc, char const *argv[])
{ 
    Myclass myobj;
    thread tx {&Myclass::func, myobj, 21, 32}; // There is copy semantic
    tx.join();

    thread ty {&Myclass::func, ref(myobj), 21, 32}; // There is not copy semantic
    ty.join();

    return 0;
}
