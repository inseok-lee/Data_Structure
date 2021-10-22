#include <iostream>
//#include "UnsortedType.h"
#include "SortedType.h"

using namespace std;

// C. Client함수로 작성(UnsortedList)
template<class ItemType>
void MergeLists(SortedType<ItemType>& l_a, SortedType<ItemType>& l_b, SortedType<ItemType>& result);


int main()
{
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

//    MergeLists(s_list_1, s_list_2, result);
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



// C. Client함수로 작성(UnSortedList)
template<class ItemType>
void MergeLists(SortedType<ItemType>& l_a, SortedType<ItemType>& l_b, SortedType<ItemType>& result){
    l_a.ResetList();
    l_b.ResetList();
    result.ResetList();
    
    
    int lenA = l_a.LengthIs();
    int lenB = l_b.LengthIs();
    ItemType item;

    while (0 < lenA){
        l_a.GetNextItem(item);
        result.InsertItem(item);
        lenA--;
    }
    while (0 < lenB){
        l_b.GetNextItem(item);
        result.InsertItem(item);
        lenB--;
    }
}

