#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

template <uint32_t DIM>
class Queue {
public:
	Queue() : array(), head(0), tail(0) {}

	Queue(const Queue<DIM> & rhs) : head(rhs.head), tail(rhs.tail) {
		for (uint32_t i = 0; i < DIM; i++) 
			array[i] = rhs[i];
	}

	Queue<DIM> & operator=(const Queue<DIM> & rhs) {
		if (&rhs != this) {
			Queue<DIM> tmp(rhs);
			swap(rhs);
		}
		return *this;
	}


	const int operator[](uint32_t index) const { return array[index]; }

	int operator[](uint32_t index) { return static_cast<const Queue<DIM>*>(this)->operator[](index); }

	inline bool isEmpty() { return head == tail; }

	inline bool isFull() { return tail + 1 == head || (head == 0 && tail == DIM); }

	void enqueue(int val) {
		if (isFull()) {
			cout << "The queue is full.\n";
			return;
		}
		array[tail++] = val;
		tail = tail == DIM + 1 ? 0 : tail;
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "The queue is empty.\n";
			return -1;
		}
		int res = array[head++];
		head = head == DIM + 1 ? 0 : head;
		return res;
	}


private:

	void swap(Queue<DIM> & rhs) {
		swap(array, rhs.array);
		swap(head, rhs.head);
		swap(tail, rhs.tail);
	}


	int array[DIM+1];
	uint32_t head;
	uint32_t tail;
};

int main() {
	Queue<3> a;
	for (int i = 0; i < 3; i++) {
		a.enqueue(i);
	}

	for (int i = 0; i < 3; i++) {
		cout << a.dequeue() << endl;
	}
	

}