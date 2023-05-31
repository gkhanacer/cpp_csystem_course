#include <string>
#include <iostream>

using namespace std;

void print(const std::string& str)
{
	std::cout << "[" << str << "] [" << str.size() << "/" << str.capacity() << "]\n";
}

void simplfy_string(string& s) 
{
    int N = s.length();
    auto it = s.begin();
    while(it != s.end()) {
        if (*it == '#' && s.length() > 0) {
            if (it == s.end())
                s.erase(it-1, s.end());
            else if (it-1 != --s.begin()){
                s.erase(it-1, it+1);
                --it;
            }
            else {
                ++it;
            }
        } else {
            ++it;
        }
    }
}

int main()
{
	char buffer[] = { "#a#c" };

	std::string s1(buffer); //c-string ctor
    simplfy_string(s1);
	print(s1);

}

