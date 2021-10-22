#include <iostream>
#include "StackType.h"

using namespace std;


// A. ReplaceItem함수를 클라이언트로 작성.
void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem);


int main()
{
    StackType stackLL;
    StackType temp;
    int item;

    stackLL.Push(8);
    stackLL.Push(3);
    stackLL.Push(9);
    stackLL.Push(8);
    stackLL.Push(3);
    stackLL.Push(7);
    stackLL.Push(5);
    stackLL.Push(3);
    
    stackLL.ReplaceItem(3, 10);

    cout << "Item: ";
    while (!stackLL.IsEmpty()) {
        item = stackLL.Top();
        stackLL.Pop();
        cout << item << ", ";
    }
    cout << endl;
    
    return 0;
}


void ReplaceItem(StackType& stackLL, ItemType oldItem, ItemType newItem){
    StackType temp_stackLL;
    ItemType item;
    
    while(!stackLL.IsEmpty()){
        item = stackLL.Top();
        stackLL.Pop();
        if(item == oldItem){
            item = newItem;
        }
        temp_stackLL.Push(item);
    }
    
    while(!temp_stackLL.IsEmpty()){
        item = temp_stackLL.Top();
        temp_stackLL.Pop();
        stackLL.Push(item);
    }
}
