#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

typedef int T;

vector<vector<T>> partition_5(vector<T> nums) {
	int s = nums.size(), i = 0;
	vector<vector<T>> res;
	for (; i + 5 < s; i += 5) {
		res.push_back(vector<T>(nums.begin()+i, nums.begin()+i+5));
	}
	res.push_back(vector<T>(nums.begin()+i, nums.end()));
	return res;
}

// assume nums has size 5 or less
T getMedian(vector<T> & nums) {
	if (nums.size() > 5) {
		cout << "Error"; 
		exit(1);
	}

	vector<T> tmp(nums.begin(), nums.end());
	sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() / 2];
}

int partition(vector<T> & nums, T pivot, int l, int r) {
	cout << pivot << " ";
	int i = l; 
	int pivot_index = 0;
	for (int j = l; j <= r; j++) {
		if (nums[j] < pivot) 
			swap(nums[j], nums[i++]);
		if (nums[j] == pivot)
			pivot_index = j;
	}
	return pivot_index;
}


T select(vector<T> & nums, int k) {

	auto vecs = partition_5(nums);
	vector<T> next;
	for_each(vecs.begin(), vecs.end(), 
		[&next](vector<T> & vec) {
			next.push_back(getMedian(vec));
		});
	
	T med = next.size() > 5 ? select(next, next.size()/2) : getMedian(next);
	int pivot_index = partition(nums, med, 0, nums.size()-1);

	vector<T> upper(nums.begin()+pivot_index+1, nums.end());
	vector<T> lower(nums.begin(),nums.begin()+pivot_index);

	cout << pivot_index << " " <<  k << endl; 
	
	if (pivot_index == k) return nums[pivot_index];
	else if (pivot_index < k) return select(upper, k-pivot_index);
	else return select(lower, k);
}





int main() {

	int arr[10] = {2,1,4,15,32,6,3,31,34,8};
	vector<int> tmp(arr, arr+10);

	auto vec = partition_5(tmp);

	ostream_iterator<int> iter(cout, " ");
	copy(vec[0].begin(), vec[0].end(), iter);
	cout << endl;


	for (int i = 0; i < 10; i++) {
		cout << select(tmp, i) << endl;
	}

}






