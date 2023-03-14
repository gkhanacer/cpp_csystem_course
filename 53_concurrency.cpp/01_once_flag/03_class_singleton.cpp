#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <syncstream>
#include <fstream>

class Singleton{
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* get_instance()
    {
        std::call_once(m_init_flag, init);
        return m_instace;
    }

    static void init()
    {
        m_instace = new Singleton;
    }

private:
    inline static std::once_flag m_init_flag;
    inline static Singleton* m_instace;
    Singleton() = default;
};


void func()
{
    static std::ofstream ofs{"out.txt"};
    ///
    std::osyncstream{ofs} << Singleton::get_instance() << '\n';
}


int main(int argc, char const *argv[])
{
    std::vector<std::thread> tvec;

    for (size_t i = 0; i < 100; i++)
    {
        tvec.emplace_back(func);
    }

    for (auto &th : tvec)
    {
        th.join();
    }
    
    
    return 0;
}
