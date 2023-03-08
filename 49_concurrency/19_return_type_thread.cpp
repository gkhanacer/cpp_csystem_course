#include <thread>
#include <iostream>
#include <vector>

using namespace std;

// There is not Return Value Optimization (RVO), but move semantic works.
std::thread make_thread() {
    std::thread t {[](){
        std::cout << "make_thread()\n";
    }};
    return t;
}

void workload() {}

int main(int argc, char const *argv[])
{ 
    thread t;

    t = make_thread();
    t.join();

    return 0;
}
