#include <ostream>

// counter.h

namespace std {
    
}

class Counter {
public:
    explicit Counter(int val = 0): mc{val} {};
    friend std::ostream& operator<<(std::ostream& os, const Counter& c)
    {
        return os << "|" << c.mc << "|";
    }
    Counter& operator++()
    {
        ++mc;
        return *this;
    }
    Counter operator++(int)
    {
        Counter ret {*this};
        ++*this;
        return ret;
    }
    Counter& operator--()
    {
        --mc;
        return *this;
    }
    Counter operator--(int)
    {
        Counter ret{ *this };
        --*this;
        return ret;
    }

    explicit operator int()const
    {
        return mc;
    }
private:
    int mc;
};

#include <iostream>
int main(int argc, char const *argv[])
{
    Counter c;

    for (int i = 0; i < 10; i++)
    {
        std::cout << c++ << "\n";
    }

    int ival = static_cast<int>(c);
    std::cout << "ival: " << ival << "\n";
    
    return 0;
}
