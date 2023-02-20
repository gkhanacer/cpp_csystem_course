#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void foo(std::vector<int>&& ivec) {
    for (const auto a: ivec) 
        std::cout << a << " ";
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{ 
    vector ivec {4, 10, 30};
    std::thread tx {foo, std::move(ivec)}; // burada ivec nesnesi Rval olarak gonderiliyor. fonsiyon da Rval bekliyor sorun yok!
    tx.join(); 

    cout << ivec.size() << '\n';

    return 0;
}
