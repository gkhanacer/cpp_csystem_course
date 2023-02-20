#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void foo(const std::vector<int>& ivec) {
    for (const auto a: ivec) 
        std::cout << a << " ";
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    vector ivec {4, 10, 30};
    std::thread tx {foo, ref(ivec)}; // burada ivec nesnesinin kendisi referance_wrapper ile gonderilir
    tx.join(); 
    cout << ivec.size() << '\n';

    return 0;
}
