#include <iostream>
using namespace std;
#include "QueType.h"

template <class ItemType>
void ReplaceItem(QueType<ItemType> &queue, ItemType oldItem, ItemType newItem) {

	QueType<ItemType> temp_queue;
	ItemType temp_item;

	while (!queue.IsEmpty()) {
		queue.Dequeue(temp_item);

		if (temp_item == oldItem) {
			temp_queue.Enqueue(newItem);
		}
		else {
			temp_queue.Enqueue(temp_item);
		}

	}
	while (!temp_queue.IsEmpty()) {

		temp_queue.Dequeue(temp_item);
		queue.Enqueue(temp_item);

	}
}

int main() {

	QueType<int> queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Enqueue(5);

	ReplaceItem(queue, 1, 0);
	queue.ReplaceItem(0, 1);

	while (!queue.IsEmpty()) {

		int temp_item;
		queue.Dequeue(temp_item);

		cout << temp_item << endl;
		
	}

	return 0;
}