#include <iostream>
#include "StackType.h"
using namespace std;

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem)
{
	StackType temp_stack;
	ItemType temp_item;
	while (!stack.IsEmpty()) {

	
		temp_item = stack.Top();
		

		if (temp_item == oldItem) {

			temp_stack.Push(newItem);
		}
		else {
			temp_stack.Push(temp_item);
		}
		stack.Pop();
	}

	while (!temp_stack.IsEmpty()) {

		
		temp_item = temp_stack.Top();
		stack.Push(temp_item);
		temp_stack.Pop();
	}

}

int main() {


	StackType stack;

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);

	ReplaceItem(stack, 1, 0);
	stack.ReplaceItem(0, 1);

	while (!stack.IsEmpty()) {

		ItemType temp_item;
		temp_item = stack.Top();

		cout << temp_item << endl;
		stack.Pop();
	}

	return 0;
}