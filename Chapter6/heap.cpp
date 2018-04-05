
#include "priority_queue.hpp"

void heap_sort(std::vector<int> & vec) {
	Heap<int> h(vec);
	for (int s = vec.size()-1; s > 0; s--) {
		std::swap(h[s], h[0]);
		h.heap_size--;
		h.max_heapify(0);
	}
	vec = h.vec;
}

int main() {
	std::cout << "hello world." << std::endl;
	std::ostream_iterator<int> iter(std::cout, " ");

	int arr[9] = {3,2,1,3,4,15,32,6,3};
	std::vector<int> tmp(arr, arr+9);
	
	Heap<int> h(tmp, true);
	h.printHeap();


	heap_sort(tmp);	
	std::copy(tmp.begin(),tmp.end(), iter);
	std::cout << std::endl;

	Pqueue<int> a(tmp);
	a.printHeap();

	for (int i = 0; i < tmp.size(); i++) 
		std::cout << a.extract_maximum() << " ";
	std::cout << std::endl;

	a.printHeap();

	Pqueue<int> b(tmp);
	b.printHeap();
	b.insert(13);
	b.printHeap();
}


