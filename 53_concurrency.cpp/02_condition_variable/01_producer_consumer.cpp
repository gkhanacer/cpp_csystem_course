#include <thread>
#include <mutex>
#include <iostream>
#include <vector>


int shared_variable {};
std::mutex mtx;

using namespace std::literals;

void producer()
{
    std::this_thread::sleep_for(100ms);
    std::lock_guard guard{mtx};
    //production
    shared_variable = 999;
}

void consumer()
{
    std::unique_lock ulock{mtx};

    while(shared_variable == 0) // this conditon will be checked much more!
    {
        ulock.unlock(); // processor is working resource!!
        std::this_thread::yield();
        std::this_thread::sleep_for(100ms); // Is 100ms enought? Maybe it will be sleep more? or 100 can be shorter? we dont know! NOT OPTIMIE
        ulock.lock();
    }

    //consumption

    std::cout << "the value is : " << shared_variable;
}

int main(int argc, char const *argv[])
{
    std::thread t1{producer};
    std::thread t2{consumer};
    t1.join();
    t2.join();

    return 0;
}
