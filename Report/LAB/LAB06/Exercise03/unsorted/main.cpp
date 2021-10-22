#include <iostream>
#include "UnsortedType.h"
//#include "SortedType.h"

using namespace std;

// C. Client함수로 작성(UnsortedList)
template<class ItemType>
void MergeLists(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result);

int main()
{
    UnsortedType<int> us_list_1;
    UnsortedType<int> us_list_2;
    UnsortedType<int> result;

    us_list_1.InsertItem(1);
    us_list_1.InsertItem(3);
    us_list_1.InsertItem(5);
    us_list_1.InsertItem(7);
    us_list_1.InsertItem(9);

    us_list_2.InsertItem(2);
    us_list_2.InsertItem(4);
    us_list_2.InsertItem(6);
    us_list_2.InsertItem(8);
    us_list_2.InsertItem(10);

    us_list_1.MergeLists(us_list_2, result);
//    MergeLists(us_list_1, us_list_2, result);


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
void MergeLists(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result){
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

