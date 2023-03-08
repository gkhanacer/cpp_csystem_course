#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std::literals;

int main(int argc, char const *argv[])
{
    auto tp_start =  std::chrono::system_clock::now();

    auto layz_async = std::async(std::launch::deferred, [] { return std::chrono::system_clock::now();});
    auto eager_async = std::async(std::launch::async, [] { return std::chrono::system_clock::now();});

    std::this_thread::sleep_for(std::chrono::seconds(1));

    using dsec = std::chrono::duration<double>;
    auto lazy_sec = static_cast<dsec>(layz_async.get() - tp_start).count();
    auto eager_sec = static_cast<dsec>(eager_async.get() - tp_start).count();

    std::cout << "duration for deferred in sec : " << lazy_sec << "\n";
    std::cout << "duration for async in sec : " << eager_sec << "\n";

    return 0;
}
