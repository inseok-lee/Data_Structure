#include "QueType.h"
#include <iostream>
using namespace std;

int main() {
	int item;
	QueType que;
	que.Enqueue(1);
	que.Enqueue(2);
	que.Enqueue(3);
	que.Enqueue(4);

	while (!que.IsEmpty()) {
		que.Dequeue(item);
		cout << item << endl;
	}
}