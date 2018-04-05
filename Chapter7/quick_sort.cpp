
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

int partition(std::vector<int> & vec, int l, int r) {
	int x = vec[r];
	int i = l;
	for (int j = l; j < r; j++) {
		if (vec[j] <= x) 
			std::swap(vec[i++], vec[j]);
	}
	std::swap(vec[i], vec[r]);
	return i;
}

void quick_sort_help(std::vector<int> & vec, int l, int r) {
	if (l < r) {
		int q = partition(vec, l, r);
		quick_sort_help(vec,l,q-1);
		quick_sort_help(vec,q+1,r);
	}
}

void quick_sort(std::vector<int> & vec) {
	quick_sort_help(vec, 0, vec.size()-1);
}


int main() {
	std::ostream_iterator<int> iter(std::cout, " ");
	int arr[12] = {3,2,1,3,4,15,32,6,3,31,34,8};
	std::vector<int> tmp(arr, arr+12);

	quick_sort(tmp);

	std::copy(tmp.begin(),tmp.end(), iter);
	std::cout << std::endl;

}









