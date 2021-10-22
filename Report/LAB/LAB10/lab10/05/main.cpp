#include <iostream>
#include "TreeType.h"
#include "SortedType.h"
using namespace std;

void AddElement(TreeType& tree, int Array[], int from, int to);
void MakeTree(TreeType& tree, SortedType<int>& list);

void AddElement(TreeType& tree, int Array[], int from, int to) {
	int mid;
	if (from <= to) {
		mid = (from + to) / 2;
		tree.InsertItem(Array[mid]);
		cout << Array[mid] << endl;
		AddElement(tree, Array, mid + 1, to);
		AddElement(tree, Array, from, mid - 1);
	}
}
void MakeTree(TreeType& tree, SortedType<int>& list) {

	int length = list.LengthIs();
	int* array = new int[length];
	int item_info;
	int i;

	list.ResetList();

	for (i = 0; i < length; i++) {
		list.GetNextItem(item_info);
		array[i] = item_info;
	}

	AddElement(tree, array, 0, length - 1);

	delete[] array;
}


int main() {

	SortedType<int> sl;
	TreeType tree;

	sl.InsertItem(1);
	sl.InsertItem(2);
	sl.InsertItem(3);
	sl.InsertItem(4);
	sl.InsertItem(5);
	sl.InsertItem(6);
	sl.InsertItem(7);

	MakeTree(tree, sl);

	return 0;
}