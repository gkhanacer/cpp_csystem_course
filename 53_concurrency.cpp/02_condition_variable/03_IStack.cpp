#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

#include <condition_variable> //Not COPYABLE NOT MOVEABLE


class IStack {
public:
    IStack() {};
    IStack(const IStack&) = delete;
    IStack& operator=(const IStack&) = delete;

    int pop()
    {
        std::unique_lock lock{m_};
        m_cv.wait(lock, [this](){
            return !m_vec.empty();
        });
        int val = m_vec.back();
        m_vec.pop_back();
        return val;
    }

    void push(int n)
    {
        {
            std::scoped_lock lock{m_};
            m_vec.push_back(n);
        }
        m_cv.notify_one();
    }


private:
    std::vector<int> m_vec;
    mutable std::mutex m_;
    mutable std::condition_variable m_cv;
};

constexpr int n = 10;
IStack s;

void producer()
{
    for (size_t i = 0; i < n; i++)
    {
        s.push(i);
    }   
}

void consumer()
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << s.pop() << '\n';
    }
}

int main(int argc, char const *argv[])
{
    std::thread th1 {producer};
    std::thread th2 {consumer};
    th1.join();
    th2.join();

    return 0;
}
