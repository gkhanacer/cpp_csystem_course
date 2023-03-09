#include <future>
#include <iostream>
#include <thread>
#include <utility>
#include <syncstream>

struct SumSquare
{
    void operator()(std::promise<int>&& prom, int a, int b)
    {
        prom.set_value(a*a + b*b);
    }
};

void func(std::shared_future<int> sftr)
{
    std::osyncstream os{std::cout};
    os << "threadId()" << std::this_thread::get_id() << "): ";
    os << "result = " << sftr.get() << std::endl;
}

int main(int argc, char const *argv[])
{
    std::promise<int> prom;
    // std::shared_future<int> sftr = prom.get_future();
    auto ftr = prom.get_future(); // WARNING! The auto detect only future, not shared_future

    std::cout << "ftr is " << (ftr.valid() ? "valid" : "invalid") << '\n';

    std::thread th{SumSquare{}, std::move(prom), 5, 9};
    std::cout << "ftr is " << (ftr.valid() ? "valid" : "invalid") << '\n';

    std::shared_future<int> sftr = ftr.share(); // after calling share() function, future object will be invalid.
    std::cout << "ftr is " << (ftr.valid() ? "valid" : "invalid") << '\n';

    // different threads can use shared_future object, and all of them can call get() function.
    std::thread t1 {func, sftr};
    std::thread t2 {func, sftr};
    std::thread t3 {func, sftr};
    std::thread t4 {func, sftr};
    std::thread t5 {func, sftr};

    th.join();

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}
