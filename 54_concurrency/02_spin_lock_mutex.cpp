#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

class SpinlockMutex {
public:
    SpinlockMutex()
    {
        m_f.clear();
    }

    void lock()
    {
        while(m_f.test_and_set()) // if m_f is true wait.
            ; //null statement
    }

    void unlock()
    {
        m_f.clear();
    }

private:
    std::atomic_flag m_f;
};

SpinlockMutex mtx;
unsigned long long counter {};

void func()
{
    for (size_t i = 0; i < 1'000'000; ++i)
    {
        // mtx.lock();
        std::lock_guard guard {mtx};
        ++counter;
        // mtx.unlock();
    }
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> tvec;

    for (size_t i = 0; i < 10; ++i)
    {
        tvec.emplace_back(func);
    }
    
    for (auto &th : tvec)
    {
        th.join();
    }
    
    std::cout << counter;

    return 0;
}
