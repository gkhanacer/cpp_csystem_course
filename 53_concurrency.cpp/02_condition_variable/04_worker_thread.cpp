#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

#include <condition_variable> //Not COPYABLE NOT MOVEABLE

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
    //Wait until main() sends data
    std::unique_lock lock(m);
    cv.wait(lock, []{return ready;});

    // after wait, we own the lock
    std::cout << "Worker thread is processing data\n";
    data += " after processing";

    // Send data back to main
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";

    // Manual unlocking is done before notifyying, to avoid waking up
    // the waiting thread only to clock again (see notify_one for details)
    lock.unlock();
    cv.notify_one();
}

int main(int argc, char const *argv[])
{
    std::thread worker{worker_thread};

    data = "Example data";

    // send data to worker thread
    {
        std::lock_guard lock{m};
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_all();

    // wait for the worker
    {
        std::unique_lock lock{m};
        cv.wait(lock, []{ return processed;});
    }
    std::cout << "Back in main(), data = " << data << '\n';

    worker.join();
    
    return 0;
}
