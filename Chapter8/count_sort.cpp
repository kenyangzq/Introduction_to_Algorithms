
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <map>

void count_sort(std::vector<int> & vec) {
	std::map<int, int, std::greater<int>> m;

	std::for_each(vec.begin(), vec.end(), 
		[&m](const int & a) {
			if (m.find(a) != m.end())
				m[a]++;
			else
				m[a] = 1;
		});
	int index = 0;

	std::for_each(m.begin(), m.end(),
		[&vec, &m, &index](const std::pair<int, int> a) {
			std::cout << a.first << " " << a.second << std::endl;

			for (int i = 0; i < a.second; i++)
				vec[index++] = a.first;
		});
}


void count_sort2(std::vector<int> & vec, int k) {
	std::vector<int> mark(k, 0);
	std::for_each(vec.begin(), vec.end(), 
		[&mark](const int & a) {
			mark[a]++;
		});
	int index = 0, val = 0;

	std::for_each(mark.begin(), mark.end(), 
		[&vec, &index, &val](const int &a) {
			for (int i = 0; i < a; i++) 
				vec[index++] = val;
			val++;
		});
}


int main() {
	std::ostream_iterator<int> iter(std::cout, " ");
	int arr[12] = {3,2,1,3,4,15,32,6,3,31,34,8};
	std::vector<int> tmp(arr, arr+12);

	// count_sort(tmp);
	count_sort2(tmp, 36);

	std::copy(tmp.begin(),tmp.end(), iter);
	std::cout << std::endl;
}

