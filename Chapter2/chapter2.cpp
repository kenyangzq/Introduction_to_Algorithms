#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

void insertion_sort(std::vector<int> & nums);
void insertion_sort_reverse(std::vector<int> & nums);
void merge_sort(std::vector<int> & nums, int l, int r);
void merge(std::vector<int> & nums, int l, int m, int r);

int main() {

	// std::cout << "hello world" << std::endl;
	std::ostream_iterator<int> iter(std::cout, " ");

	int array[] = {31,42,23,43,32};
	std::vector<int> tmp1(array, array+5);
	
	insertion_sort(tmp1);
	std::copy(tmp1.begin(), tmp1.end(), iter);
	std::cout << std::endl;

	insertion_sort_reverse(tmp1);
	std::copy(tmp1.begin(), tmp1.end(), iter);
	std::cout << std::endl;

	merge_sort(tmp1, 0, tmp1.size());
	// std::copy(tmp1.begin(), tmp1.end(), iter);
	for (auto i : tmp1) {
		std::cout << i << " ";
	}
	std::cout << std::endl;		
}

void insertion_sort(std::vector<int> & nums) {
	for (int j = 1; j < nums.size(); j++) {
		int key = nums[j];
		int i = j - 1;
		while (i >= 0 && nums[i] > key) {
			nums[i+1] = nums[i];
			i -= 1;
		}
		nums[i+1] = key;
	}
}

void insertion_sort_reverse(std::vector<int> & nums) {
	for (int j = 1; j < nums.size(); ++j) {
		int key = nums[j];
		int i = j - 1;
		while (i >= 0 && nums[i] < key) {
			nums[i+1] = nums[i];
			i--;
		}
		nums[i+1] = key;
	}
}

void merge_sort(std::vector<int> & nums, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		merge_sort(nums, l, m);
		merge_sort(nums, m+1, r);
		merge(nums,l,m,r);
	}
}


// include the last index 
void merge(std::vector<int> & nums, int l, int m, int r) {

	int n1 = m - l + 1, n2 = r - m;
	std::vector<int> v1(n1), v2(n2);
	std::copy(nums.begin()+l, nums.begin()+m+1, v1.begin());
	std::copy(nums.begin()+m+1, nums.begin()+r+1, v2.begin());
	// for (int i = 0; i < n1; i++) {
	// 	v1[i] = nums[l + i];
	// }
	// for (int i = 0; i < n2; i++) {
	// 	v2[i] = nums[m + 1 + i];
	// }

	int ind1 = 0, ind2 = 0, j = l;
	// for (; j < r + 1 && ind1 < n1 && ind2 < n2; j++) {
	// 	nums[j] = v1[ind1] < v2[ind2] ? v1[ind1++] : v2[ind2++];
	// }
	// while (ind1 < n1) nums[j++] = v1[ind1++];
	// while (ind2 < n2) nums[j++] = v2[ind2++];

	std::transform(nums.begin()+l, nums.begin()+r+1, nums.begin()+l,
		[v1, v2, &ind1, &ind2, n1, n2](const int &) {
			return (ind2 >= n2 || (ind1 < n1 && v1[ind1] < v2[ind2])) ? v1[ind1++] : v2[ind2++];
		});
}
















