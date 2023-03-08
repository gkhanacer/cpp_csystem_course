#include <initializer_list>
#include <iostream>
#include <functional>


class Test {
public:
    Test(int a, std::function<void()> f) : m_func{f}
    {}

    std::function<void()>   m_func;

    void operator()() { m_func(); };
};

int func(int &result, int x, double y, std::string s)
{
    std::cout << "func..." << "x = " << x << ", y = " << y << ", s = " << s << "\n";
    result = 555;
}

int main()
{
    std::string s{"gokhan"};
    int result = 0;
	Test t{1, std::bind(func, result, 1, 1.1, s)};
    t();
    std::cout << result;
}