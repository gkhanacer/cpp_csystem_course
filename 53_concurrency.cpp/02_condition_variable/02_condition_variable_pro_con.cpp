#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

#include <condition_variable> //Not COPYABLE NOT MOVEABLE

using namespace std::literals;

int data {};
int ready_flag {};
std::mutex mtx;
std::condition_variable cv;

// 1 conditon variable is related to 1 event

// producer -> lock_guard or scope_guard
// consumer -> unique_lock MUST


void producer()
{
    std::cout << "producer is producing the data\n";
    {
        std::lock_guard guard{mtx};
        data = 4545;
        ready_flag = true;
    }
    cv.notify_one();
}

void consumer()
{
    {
        std::unique_lock ulock{mtx};
        cv.wait(ulock, []{ return ready_flag; });
    }
    std::cout << "the data is : " << data;
}

int main(int argc, char const *argv[])
{
    std::thread t1{producer};
    std::thread t2{consumer};
    t1.join();
    t2.join();

    return 0;
}
