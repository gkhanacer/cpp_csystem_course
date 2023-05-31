#include<vector>
#include<iostream>
#include <algorithm>
#include <ranges>
#include <string>
#include <set>
#include <fstream>
#include <list>
#include <tuple>
#include "../nutility.h"
#include <functional>
#include <iterator>

using namespace std;


// 11 44 3 7 2 8 6 9 12 elements
// 2 3 6 7 8 9 11 12 44 sorted normally
// 

// 11 44 3 7 2 8 6 9 12 elements
//           |  -> n. element location  and a number (e.g. 9)
// smaller than 9, 9, bigger than 9

int main(int argc, char const *argv[])
{   
    vector<int> ivec;
    rfill(ivec, 10000, Irand{0, 10000});
    print(ivec);

    int index = 5;

    nth_element(ivec.begin(), ivec.begin() + index, ivec.end());

    ofstream ofs {"list.txt"};
	if (!ofs) {
		cerr << "list.txt dosyasi olusturulamadi\n";
		exit(EXIT_FAILURE);
	}
    print(ivec, "\n", ofs);
}
