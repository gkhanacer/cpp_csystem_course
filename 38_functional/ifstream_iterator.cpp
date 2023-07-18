#include <istream>
#include <list>
#include <iterator>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Solution {

public:
    Solution(std::istream& is) : ms{is} {}
	struct iterator {
        
        iterator(std::istream &is) : m_is {is} {}
        bool operator==(const iterator& other)const
        {
            return other.m_is.eof();
        }

        bool operator!=(const iterator& other)const
        {
            return !(*this == other);
        }

        int operator*()
        {
            int x;
            m_is >> x;
            return x;
        }

        iterator& operator++()
        {
            return *this;
        }

        iterator& operator++(int)
        {
            return *this;
        }

        std::istream& m_is;
	};

    iterator begin()
    {
        return iterator{ ms };
    }

    iterator end()
    {
        return iterator{ ms };
    }

private:
    std::istream& ms;
};



using namespace std;

int main() 
{
    ifstream ifs{ "test.txt" };
    if (!ifs) {
        cerr << "Dosya acilamadi.\n";
        return 1;
    }
    Solution sol(ifs);
    for (Solution::iterator it = sol.begin(); it != sol.end(); ++it) {
        int x = *it;
        cout << x << endl;
    }
    return 0;
}