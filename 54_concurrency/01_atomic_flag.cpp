#include <iostream>
#include <atomic>


int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha;

    std::atomic_flag flag_x {false};
    std::atomic_flag flag_y {true};
    std::atomic_flag flag_z;
    std::cout << "flag_x = " << flag_x.test() << '\n';
    std::cout << "flag_y = " << flag_y.test() << '\n';
    std::cout << "flag_z = " << flag_z.test() << '\n';

    std::atomic_flag flag = ATOMIC_FLAG_INIT;
    std::cout << "flag = " << flag.test() << '\n';

    auto b = flag.test_and_set();
    std::cout << "b = " << b << '\n';
    std::cout << "flag = " << flag.test() << '\n';

    flag.clear();
    std::cout << "cleared flag = " << flag.test() << '\n';

    b = flag.test_and_set();
    std::cout << "b = " << b << '\n';
    std::cout << "flag = " << flag.test() << '\n';
    
    return 0;
}
