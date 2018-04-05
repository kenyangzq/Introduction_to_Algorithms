
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

// define the Heap class
template <typename T>
class Heap {
public:

	Heap(const T arr[], uint32_t size, bool min_heap = false) : vec(size), heap_size(size) { 
 
		for (uint32_t i = 0; i < size; ++i) 
			vec[i] = arr[i];

		for (int i = size / 2; i >= 0; i--) {
			if (min_heap) 
				min_heapify(i);
			else
				max_heapify(i);
		}
	}

	Heap(const std::vector<T> & v, bool min_heap = false) : vec(v), heap_size(v.size()) {
		for (int i = heap_size / 2; i >= 0; i--) {
			if (min_heap) 
				min_heapify(i);
			else
				max_heapify(i);
		}
	}

	inline uint32_t left(uint32_t index) { return 2*index; }
	
	inline uint32_t right(uint32_t index) { return 2*index + 1; }

	inline uint32_t parent(uint32_t index) { return index / 2; }

	inline void printHeap() {
		if (heap_size == 0) {
			std::cout << "Heap is empty\n";
			return;
		}
		std::ostream_iterator<T> iter(std::cout, " ");
		std::copy(vec.begin(), vec.begin()+heap_size, iter);
		std::cout << std::endl;
	}

	void max_heapify(uint32_t i) {
		auto l = left(i);
		auto r = right(i);
		
		T largest = vec[i]; 
		uint32_t ind = i;
		if (l < heap_size && vec[i] < vec[l]) {
			largest = vec[l];
			ind = l;
		}
		if (r < heap_size && largest < vec[r]) {
			largest = vec[r];
			ind = r;
		}
		if (ind != i) {
			std::swap(vec[i], vec[ind]);
			max_heapify(ind);
		}
	}

	void min_heapify(uint32_t i) {
		auto l = left(i);
		auto r = right(i);
		
		T smallest = vec[i]; 
		uint32_t ind = i;
		if (l < heap_size && vec[i] > vec[l]) {
			smallest = vec[l];
			ind = l;
		}
		if (r < heap_size && smallest > vec[r]) {
			smallest = vec[r];
			ind = r;
		}
		if (ind != i) {
			std::swap(vec[i], vec[ind]);
			min_heapify(ind);
		}
	}

	T & operator[](uint32_t index) {
		return vec[index];
	}





protected:
	Heap() = default;
	friend void heap_sort(std::vector<int> & vec);

	std::vector<T> vec;
	uint32_t heap_size;
};




template <typename T>
class Pqueue : public Heap<T> {
public:

	Pqueue() = default;

	Pqueue(const T arr[], uint32_t size, bool min_heap = false) 
		: Heap<T>(arr, size, min_heap), maxOrMin(min_heap) {}

	Pqueue(const std::vector<T> & v, bool min_heap = false) 
		: Heap<T>(v, min_heap), maxOrMin(min_heap) {}


	inline T & maximum() { this->vec[0]; }

	T extract_maximum() {
		if (this->heap_size == 0) 
			throw std::underflow_error("");
		T maximum = this->vec[0];
		this->vec[0] = this->vec[--this->heap_size];
		this->max_heapify(0);
		return maximum;
	}

	void increase_key(uint32_t i, T key) {
		if (key < this->vec[i]) 
			throw std::domain_error("Value less than key");
		this->vec[i] = key;
		while (i > 0 && this->vec[this->parent(i)] < this->vec[i]) {
			std::swap(this->vec[this->parent(i)], this->vec[i]);
			i = this->parent(i);
		}
	}

	void insert(T val) {
		this->vec.push_back(val - 1);
		this->heap_size++;
		increase_key(this->heap_size-1, val);
	}

private: 

	// 0 for max priority queue
	// 1 for min priority queue
	int maxOrMin;

};








