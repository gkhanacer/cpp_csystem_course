#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void foo(std::vector<int>& ivec) {
    for (const auto a: ivec) 
        std::cout << a << " ";
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    vector ivec {4, 10, 30};
    std::thread tx {foo, ivec}; // burada ivec nesnesi Rval olarak gonderiliyor. Ama fonksiyon Lval istiyor. SE
    tx.join(); 

    return 0;
}
