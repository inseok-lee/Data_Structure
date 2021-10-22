#include <iostream>
#include "StackType.h"

using namespace std;

int main()
{
	StackType left_stack;
	StackType right_stack;

	char* input = new char[100];
	cin >> input;

	for (int i = 0; i < 100; i++) {
		char c = input[i];
		if (c == NULL)
			break;
		switch (c) {
		case '<':
			if (!left_stack.IsEmpty()) {
				char ch = left_stack.Top();
				left_stack.Pop();
				right_stack.Push(ch);
			}
			break;

		case '>':
			if (!right_stack.IsEmpty()) {
				char ch = right_stack.Top();
				right_stack.Pop();
				left_stack.Push(ch);
			}
			break;

		case '-':
			if (!left_stack.IsEmpty()) {
				left_stack.Pop();
			}
			break;
		default:
			left_stack.Push(c);
			break;
		}
	}

	while (!left_stack.IsEmpty()) {
		char c = left_stack.Top();
		left_stack.Pop();
		right_stack.Push(c);
	}

	while (!right_stack.IsEmpty()) {
		char c = right_stack.Top();
		right_stack.Pop();
		cout << c;
	}
	cout << endl;

	return 0;
}
