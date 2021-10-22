#include <iostream>
using namespace std;
#include "SortedType.h"

int main() {

	SortedType<int> us_list;

	us_list.InsertItem(1);
	us_list.InsertItem(2);
	us_list.InsertItem(1);
	us_list.InsertItem(2);
	us_list.InsertItem(3);
	us_list.InsertItem(4);
	us_list.InsertItem(1);
	us_list.InsertItem(2);

	us_list.DeleteItem(5);

	int length = 0;
	int item;
	us_list.ResetList();
	while (length != us_list.LengthIs()) {

		us_list.GetNextItem(item);

		cout << item << endl;
		length++;
	}

	return 0;
}