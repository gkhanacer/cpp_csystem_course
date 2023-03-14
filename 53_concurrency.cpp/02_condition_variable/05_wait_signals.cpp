#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <chrono>
#include <condition_variable>

std::condition_variable cv;
std::mutex cv_m;

int i = 0;

void waits()
{
    std::unique_lock lock{cv_m};
    std::cerr << "Waiting...\n";
    cv.wait(lock, []{ return i==1;});
    std::cerr << "... finished waiting. i == 1\n";
}

void signals()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard lock(cv_m);
        std::cerr << "Notifying... \n";
    }
    cv.notify_all();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard lock(cv_m);
        i = 1;
        std::cerr << "Notifying again....\n";
    }
    cv.notify_all();
}

int main(int argc, char const *argv[])
{
    std::thread t1{waits}, t2{waits}, t3{waits}, t4{signals};
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
