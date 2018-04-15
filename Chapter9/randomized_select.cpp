#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>



int randomized_partition(std::vector<int> & vec, int l, int r) {
	srand(0);
	// int i = std::rand() % (r - l + 1) + l;
	int i = r;
	std::swap(vec[r], vec[i]);

	i = l;
	for (int j = l; j < r; j++) {
		if (vec[j] < vec[r]) 
			std::swap(vec[j], vec[i++]);
	}
	std::swap(vec[i], vec[r]);
	return i;
}

int randomized_select_impl(std::vector<int> & vec, int l, int r, int k) {
	if (l == r) return vec[l];
	int pivot = randomized_partition(vec, l, r); // the partition index
	int dis = pivot - l + 1; // distance between pivot and left 

	if (dis == k) return vec[pivot];
	else if (dis < k) return randomized_select_impl(vec, pivot + 1, r, k - dis);
	else return randomized_select_impl(vec, l, pivot - 1, k);
}


int randomized_select(std::vector<int> & vec, int k) {
	return randomized_select_impl(vec, 0, vec.size() - 1, k);
}


int main() {
	std::ostream_iterator<int> iter(std::cout, " ");
	int arr[10] = {2,1,4,15,32,6,3,31,34,8};
	std::vector<int> tmp(arr, arr+10);

	// quick_sort(tmp);
	for (int i = 10; i > 0; i--) {
		std::vector<int> tmp2(tmp.begin(), tmp.end());
		std::cout << randomized_select(tmp2, i) << " " << i << std::endl;
	}
	std::cout << std::endl;

	// std::copy(tmp.begin(),tmp.end(), iter);
	// std::cout << std::endl;

}





