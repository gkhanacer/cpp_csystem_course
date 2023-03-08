#include <thread>
#include <iostream>
#include <vector>

using namespace std;

class  Functor {
public:
    void operator()(int x) 
    {
        std::cout << x << "\n";
    }
};

int main(int argc, char const *argv[])
{ 
    Functor ftor;

    thread tx {ftor, 21};

    tx.join();

    return 0;
}
