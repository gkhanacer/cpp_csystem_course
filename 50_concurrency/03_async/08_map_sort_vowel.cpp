#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iomanip>

using namespace std;

std::map<char, size_t> histogram(const std::string& s)
{
    std::map<char, size_t> cmap;

    for (char c : s)
        ++cmap[c];

    return cmap;
}

std::string get_sorted(std::string str)
{
    sort(begin(str), end(str));
    erase_if(str, [](char c) {return isspace(c);});
    return str;
}

bool is_vowel(char c)
{
    static const char vowels[]{"AEIOUaeiou"};
    return find(begin(vowels), end(vowels), c) != end(vowels);
}

size_t count_vowels(const string& s)
{
    return count_if(begin(s), end(s), is_vowel);
}

int main(int argc, char const *argv[])
{
    std::string sline;
    std::cout << "enter a string : ";

    std::getline(std::cin, sline);

    auto hist         = async(launch::async, histogram, sline);
    auto sorted_str   = async(launch::async, get_sorted, sline);
    auto vowel_count  = async(launch::async, count_vowels, sline);

    for (const auto&[c, val] : hist.get())
        cout << c << " : " << val << '\n';

    cout << "sorted string : " << quoted(sorted_str.get()) << '\n' << "total vowels : " << vowel_count.get() << '\n';

    
    

    return 0;
}
