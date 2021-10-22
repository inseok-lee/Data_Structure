#include "SortedType.h"
#include "UnsortedType.h"
#include "ItemType.h"
#include <iostream>

using namespace std;

void Sum_Sort_List(UnsortedType list1, UnsortedType list2, SortedType& result)
{
    list1.ResetList();
    list2.ResetList();
    result.ResetList();
    for (int i = 0; i < list1.LengthIs(); i++)
    {
        ItemType temp1, temp2, sum;
        list1.GetNextItem(temp1);
        list2.GetNextItem(temp2);
        sum.Initialize(temp1.GetValue()+temp2.GetValue());
        result.InsertItem(sum);
    }
}

int main()
{
    int N;
    cin >> N;
    UnsortedType list1, list2;
    SortedType list3;

    for (int i = 0; i < N; i++)
    {
        int temp_input;
        ItemType temp_item;
        cin >> temp_input;
        temp_item.Initialize(temp_input);
        list1.InsertItem(temp_item);
    }

    for (int i = 0; i < N; i++)
    {
        int temp_input;
        ItemType temp_item;
        cin >> temp_input;
        temp_item.Initialize(temp_input);
        list2.InsertItem(temp_item);
    }
    
    Sum_Sort_List(list1, list2, list3);

    ItemType temp;
	for (int i = 0; i < list3.LengthIs(); i++)
    {
		list3.GetNextItem(temp);
        temp.Print(cout);
    }	

    return 0;
}
