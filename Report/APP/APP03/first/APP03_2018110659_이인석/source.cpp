#include <iostream>
#include "ItemType.h"
#include "sorted.h"

using namespace std;

int main()
{
    SortedType list1;
    
    int N;
    cout << "Input N: ";
    cin >> N;
    
    cout << "Input list Item: ";
    for(int i = 0; i < N; i++){
        // list1에 Item 삽입
        int x;
        cin >> x;
        ItemType num;
        num.Initialize(x);
        list1.InsertItem(num);
    }
    cout << endl;
    
    while(1){
        int X;
        cout << "Input X: ";
        cin >> X;
        
        if(X == 0){
            // list1의 모든 요소 출력
            ItemType temp_item;
            list1.ResetList();
            for(int i = 0; i < N; i++){
                list1.GetNextItem(temp_item);
                cout << num.GetItem() << " ";
//                temp_item.print(cout);
//                cout << " ";
            }
            cout << endl;
            break;
        }
        
        int Y;
        cout << "Input Y: ";
        cin >> Y;
        
        //list1에 X가 존재하는지 찾고 존재하면 Y로 바꾸기
        //위 연산이 실행된 뒤 list1은 정렬된 상태여야 함
        ItemType item_X;
        ItemType item_Y;
        bool found = false;
        
        item_X.Initialize(X);
        item_Y.Initialize(Y);
        
        list1.RetrieveItem(item_X, found);
        
        if(found == true){
            list1.DeleteItem(item_X);
            list1.InsertItem(item_Y);
        }
        
        
        cout << "Operation completed." << endl << endl;
        
    }
    
    return 0;
}

