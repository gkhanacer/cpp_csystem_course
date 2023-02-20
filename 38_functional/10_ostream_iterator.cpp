#include "../nutility.h" 
#include <vector>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
void print(T list) 
{
    auto iter = list.begin();
    while (iter != list.end()) 
    {
        cout << *iter++ << " ";
    }
    cout << "\n";
}

template <typename InIter, typename OutIter>
OutIter Copy(InIter beg, InIter end, OutIter destbeg)
{
    while (beg != end) {
        *destbeg++ = *beg++;
    }
    return destbeg;
}

template<typename T>
class OstreamIterator {
    std::ostream& m_os;
    const char* mpsep{};
public:
    OstreamIterator(std::ofstream& ofs, const char* p="") : m_os{ofs}, mpsep{p} {}

    OstreamIterator& operator*() {return *this;};
    OstreamIterator& operator++() {return *this;};
    OstreamIterator& operator++(int) {return *this;};
    OstreamIterator& operator=(const T& tval) {
        m_os << tval << mpsep;
        return *this;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> svec;
    rfill(svec, 5, rname);

    std::ofstream ofs {"out.txt"};
    if (!ofs) {
        std::cerr << "dosya olusturulamadi\n";
        exit(EXIT_FAILURE); 
    }

    // copy_if(svec.begin(), svec.end(), ostream_iterator<string>{ofs, "\n"}, [](const string& s) {return s.size() == 5;});
    // Copy(svec.begin(), svec.end(), ostream_iterator<string>{ofs, "\n"});
    Copy(svec.begin(), svec.end(), OstreamIterator<string>{ofs, "\n"});

    return 0;
}
