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

// we just sort partial of data structure, not all of them.

// example: get smallest n name
int main(int argc, char const *argv[])
{   
    vector<string> svec;
    rfill(svec, 2000, []{return rname() + ' ' + rfname();});

    ofstream ofs {"list.txt"};
	if (!ofs) {
		cerr << "list.txt dosyasi olusturulamadi\n";
		exit(EXIT_FAILURE);
	}

    // sort(begin(svec), end(svec)); // sorts all elements. we dont want to do it.
    int n;
    std::cout << "first n: ";
    cin >> n;
    partial_sort(svec.begin(), svec.begin() + n, svec.end()); // it will sorts only for top 10 elements
    print(svec, "\n", ofs);


    // partial_sort_copy: copies first n sorted elementes into another structure 
    vector<string> best(20);
    partial_sort_copy(svec.begin(), svec.end(), best.begin(), best.end());
    print(best, "\n", std::cout);
}
