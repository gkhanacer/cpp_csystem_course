#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void func(std::thread t) {
    t.join();
}

void workload() {}

int main(int argc, char const *argv[])
{ 
    thread tx {workload};
    
    func(std::move(tx));

    func(thread{workload});

    return 0;
}
