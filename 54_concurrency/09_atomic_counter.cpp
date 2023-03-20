#include <iostream>
#include <atomic>
#include <concepts>
#include <thread>

class AtomicCounter{
public:
    AtomicCounter() : m_c{0} {};
    AtomicCounter(int x) : m_c{ x } {};

    int operator++() {return ++m_c;};
    int operator++(int) {return m_c++;};
    int operator--() {return --m_c;};
    int operator--(int) {return m_c--;};

    int get() const {return m_c.load();};
    operator int()const{return m_c.load();};

private:
    std::atomic<int> m_c;
};

AtomicCounter cnt;

void foo()
{
    for (size_t i = 0; i < 1'000'000; ++i)      
    {
        ++cnt;
    }
    
}
int main(int argc, char const *argv[])
{
    std::thread ta[10];

    for (auto &th : ta)
    {
        th = std::thread(foo);
    }

    for (auto &th : ta)
    {
        th.join();
    }
    
    std::cout << cnt;
    
    return 0;
}
