#include <iostream>
#include <thread>
#include <atomic>
#include <syncstream>
#include <vector>

void foo (){}

int main()
{
    // std::thread t1;
    // std::thread t2;
    // std::thread t3;

    // // If threads are not joinable, they have same id.
    // std::cout << t1.get_id() << '\n';
    // std::cout << t2.get_id() << '\n';
    // std::cout << t3.get_id() << '\n';

    std::thread t1 {foo};
    std::thread t2{foo};
    std::thread t3{foo};

    // If threads are not joinable, they have same id.
    std::cout << t1.get_id() << '\n';
    std::cout << t2.get_id() << '\n';
    std::cout << t3.get_id() << '\n';

    t1.join();
    t2.join();
    t3.join();


}