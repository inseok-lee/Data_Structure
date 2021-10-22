#include <iostream>
#include <random>
#include "QueType.h"

using namespace std;

// A. Client함수로 작성
void ReplaceItem(QueType& queue, int oldItem, int newItem);


int main()
{
    QueType myfirst_queue;
    
    // 난수 생성
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 10);
    
    // Enqueue
    for(int i = 0; i < 10; i++){
        int rand_num = dis(gen);
        cout << rand_num << "\t";
        myfirst_queue.Enqueue(rand_num);
    }
    cout << endl;
    
//    A. Client함수로 작성
//    ReplaceItem(myfirst_queue, 5, 99);
//
//    for(int i = 0; i < 10; i++){
//        int item;
//        myfirst_queue.Dequeue(item);
//        cout << item << "\t";
//    }
//    cout << endl;
    
//    B. Member함수로 작성
    myfirst_queue.ReplaceItem(5, 99);
    for(int i = 0; i < 10; i++){
        int item;
        myfirst_queue.Dequeue(item);
        cout << item << "\t";
    }
    cout << endl;
    
    
    return 0;
}


void ReplaceItem(QueType& queue, int oldItem, int newItem){
    QueType temp;
    int item;
    while(!queue.IsEmpty()){
        queue.Dequeue(item);
        if(oldItem == item)
            temp.Enqueue(newItem);
        else
            temp.Enqueue(item);
    }
    
    while(!temp.IsEmpty()){
        // 매개변수값을 !queue.IsFull()로 하면 에러. why?
        int item;
        temp.Dequeue(item);
        queue.Enqueue(item);
    }
}
