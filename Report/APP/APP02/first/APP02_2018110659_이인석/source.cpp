#include <iostream>
#include "ItemType.h"
#include "unsorted.h"
#include "sorted.h"

using namespace std;

int main()
{
    int count, num;
    ItemType item, item_A, item_B, item_C;
    UnsortedType list_A;
    UnsortedType list_B;
    SortedType list_C;
    
    cout << "리스트 A, B에 들어갈 원소 갯수를 입력하세요: ";
    cin >> count;
    
    cout << "리스트 A에 들어갈 숫자 N개를 입력하세요: ";
    for(int i = 0; i < count; i++){
        cin >> num;
        item.Initialize(num);
        list_A.InsertItem(item);
    }
    
    cout << "리스트 B에 들어갈 숫자 N개를 입력하세요: ";
    for(int i = 0; i < count; i++){
        cin >> num;
        item.Initialize(num);
        list_B.InsertItem(item);
    }
    
    list_A.ResetList();
    list_B.ResetList();
    for(int i = 0; i < count; i++){
        list_A.GetNextItem(item_A);
        list_B.GetNextItem(item_B);
        item_C.Initialize(item_A.GetItem() + item_B.GetItem());
        list_C.InsertItem(item_C);
    }
    
    list_C.ResetList();
    for(int i = 0; i < count; i++){
        list_C.GetNextItem(item_C);
        cout << item_C.GetItem() << " ";
    }
    cout << endl;
    
    return 0;
}

