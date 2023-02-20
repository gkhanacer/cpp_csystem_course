#include <string>
#include <iostream>

void print(const std::string& str)
{
	std::cout << "[" << str << "] [" << str.size() << "/" << str.capacity() << "]\n";
}

int main()
{
	std::string s1{ "life is very short and there's no thime for fussing and fighting my friend" }; //cstring ctor
	print(s1);

    std::string s2 {s1, 5}; // sub-string ctor. 5. inddexten basla sona kadar
    print(s2);

    std::string s3 {s1, 5, 10}; // sub-string ctor. 5. indexten basla 10 eleman al.
    print(s3);

}