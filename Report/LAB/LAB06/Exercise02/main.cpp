#include <iostream>
#include <random>
#include "QueType.h"

using namespace std;

// A. Client함수로 작성
template<class ItemType>
void ReplaceItem(QueType<ItemType>& queueLL, ItemType oldItem, ItemType newItem);


int main()
{
    QueType<int> queueLL;
    
    // 난수 생성
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 10);
    
    // Enqueue
    for(int i = 0; i < 10; i++){
        int rand_num = dis(gen);
        cout << rand_num << "\t";
        queueLL.Enqueue(rand_num);
    }
    cout << endl;
    
//    A. Client함수로 작성
//    ReplaceItem(queueLL, 5, 99);
//
//    for(int i = 0; i < 10; i++){
//        int item;
//        queueLL.Dequeue(item);
//        cout << item << "\t";
//    }
//    cout << endl;
    
//    B. Member함수로 작성
    queueLL.ReplaceItem(5, 99);
    for(int i = 0; i < 10; i++){
        int item;
        queueLL.Dequeue(item);
        cout << item << "\t";
    }
    cout << endl;
    
    
    return 0;
}


// A. Client함수로 작성
template<class ItemType>
void ReplaceItem(QueType<ItemType>& queueLL, ItemType oldItem, ItemType newItem){
    QueType<int> temp;
    int item;
    while(!queueLL.IsEmpty()){
        queueLL.Dequeue(item);
        if(oldItem == item)
            temp.Enqueue(newItem);
        else
            temp.Enqueue(item);
    }
    
    while(!temp.IsEmpty()){
        // 매개변수값을 !queue.IsFull()로 하면 에러. why?
        int item;
        temp.Dequeue(item);
        queueLL.Enqueue(item);
    }
}
