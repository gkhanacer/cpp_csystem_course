#include <thread>
#include <iostream>


void func() {
    std::cout << "func\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha;
    
    std::thread t {func};
    std::cout << t.joinable() << "\n";
    t.join();
    std::cout << t.joinable() << "\n";
 
    return 0;
}
