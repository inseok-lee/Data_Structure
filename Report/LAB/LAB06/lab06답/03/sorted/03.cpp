#include <iostream>
using namespace std;
//#include "UnsortedType.h"
#include "SortedType.h"

template <class ItemType>
void MergeLists(SortedType<ItemType>& l_a, SortedType<ItemType>& l_b, SortedType<ItemType>& result) {

	l_a.ResetList();
	ItemType temp_item;
	int length = 0;
	while (l_a.LengthIs() != length) {

		l_a.GetNextItem(temp_item);
		result.InsertItem(temp_item);
		length++;
	}

	l_b.ResetList();
	length = 0;
	while (l_b.LengthIs() != length) {

		l_b.GetNextItem(temp_item);
		result.InsertItem(temp_item);
		length++;
	}
	
}

int main() {

	SortedType<int> s_list_1;
	SortedType<int> s_list_2;
	SortedType<int> result;
	
	s_list_1.InsertItem(1);
	s_list_1.InsertItem(3);
	s_list_1.InsertItem(5);
	s_list_1.InsertItem(7);
	s_list_1.InsertItem(9);

	s_list_2.InsertItem(2);
	s_list_2.InsertItem(4);
	s_list_2.InsertItem(6);
	s_list_2.InsertItem(8);
	s_list_2.InsertItem(10);

	//MergeLists(s_list_1, s_list_2, result);
	s_list_1.MergeLists( s_list_2, result);

	int item;
	result.ResetList();
	int length = 0;
	while (length != result.LengthIs()) {

		result.GetNextItem(item);
		cout << item << endl;
		length++;
	}

	
	return 0;

}
