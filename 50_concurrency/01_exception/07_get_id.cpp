#include <iostream>
#include <thread>
#include <stdexcept>
#include <vector>
#include <mutex>


std::thread::id main_thread_id;
void func()
{
    if (std::this_thread::get_id() == main_thread_id)
        std::cout << "call from main thread\n";
    else
        std::cout << "call from other thread\n";
}
int main()
{
    main_thread_id = std::this_thread::get_id();

    func();

    std::thread t {func};
    t.join();
    
}