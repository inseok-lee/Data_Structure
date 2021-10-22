#include <iostream>
#include "ItemType.h"
#include "unsorted.h"
#include "sorted.h"

using namespace std;

void sum_sortedL(UnsortedType& list_A, UnsortedType& list_B, SortedType& list_C);

int main()
{
    UnsortedType list_A, list_B;
    SortedType list_C;
    
    cout << "리스트 A, B에 들어갈 원소 갯수를 입력하세요: ";
    int num;
    cin >> num;
    
    cout << "리스트 A에 들어갈 숫자 N개를 입력하세요: ";
    for(int i = 0; i < num; i++){
        int num_input;
        ItemType item_input;
        cin >> num_input;
        item_input.Initialize(num_input);
        list_A.InsertItem(item_input);
    }
    
    cout << "리스트 B에 들어갈 숫자 N개를 입력하세요: ";
    for(int i = 0; i < num; i++){
        int num_input;
        ItemType item_input;
        cin >> num_input;
        item_input.Initialize(num_input);
        list_B.InsertItem(item_input);
    }

    sum_sortedL(list_A, list_B, list_C);

    ItemType temp_input;
    list_C.ResetList();
    for(int i = 0; i < num; i++){
        list_C.GetNextItem(temp_input);
        temp_input.Print(cout);
    }
    cout << endl;

    
    return 0;
}


void sum_sortedL(UnsortedType& list_A, UnsortedType& list_B, SortedType& list_C){
    list_A.ResetList();
    list_B.ResetList();
    list_C.ResetList();
    int len = list_A.LengthIs();

    for(int i = 0; i < len; i++){
        ItemType temp_A, temp_B, temp_C;
        list_A.GetNextItem(temp_A);
        list_B.GetNextItem(temp_B);
        temp_C.Initialize(temp_A.GetItem() + temp_B.GetItem());
        list_C.InsertItem(temp_C);
    }
}