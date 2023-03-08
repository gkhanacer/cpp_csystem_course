#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void func() {
    std::cout << std::this_thread::get_id() << '\n';
}


int main(int argc, char const *argv[])
{ 
    thread tx {func};
    
    auto id = tx.get_id();
    func();
    std::cout << typeid(id).name() << '\n';
    std::cout << "thread_id : " << id << '\n';
    tx.join();
    return 0;
}
