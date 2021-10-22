#include "StackType.h"
#include <iostream>
using namespace std;


void copy(StackType& temp, int item) {				// Exercise04 A¹ø.
	if (!temp.IsFull()) {
		temp.Push(item);
	}
}



void ReplaceItem(StackType& temp,StackType& original,int olditem, int newitem) {	// Exercise04 A¹ø.
	int item;
	while (!temp.IsEmpty()) {
		item = temp.Top();
		temp.Pop();
		if (item == olditem) {
			item = newitem;
		}
		copy(original, item);
		
	}
}



int main() {
	int item;
	StackType stack;
	StackType temp;

	stack.Push(8);
	stack.Push(3);
	stack.Push(9);
	stack.Push(8);
	stack.Push(3);
	stack.Push(7);
	stack.Push(5);
	stack.Push(3);
	
	while (!stack.IsEmpty()) {
		item = stack.Top();
		stack.Pop();
		copy(temp, item);
		cout << "Item: " << item << endl;
	}

	cout << endl;


	ReplaceItem(temp, stack, 3, 5);

	while (!stack.IsEmpty()) {
		item = stack.Top();
		stack.Pop();
		cout << "Item: " << item << endl;
	}


	return 0;
}
