#include <thread>
#include <iostream>


void func() {
    std::cout << "func\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha;
    
    std::thread t;
    std::cout << t.joinable() << '\n';

    std::thread t2 { func };
    std::cout << t2.joinable() << '\n';
 
    return 0;
}
