#include <iostream>
#include <random>
#include "QueType.h"

using namespace std;

// A. Client함수로 작성
bool Identical(QueType& queue1, QueType& queue2);

void ReplaceItem(QueType& queue, int oldItem, int newItem);



int main()
{
    QueType myfirst_queue, second_queue;
    
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
    
    second_queue = myfirst_queue;
    ReplaceItem(second_queue, 3, 99);
    
    bool boolin = Identical(myfirst_queue, second_queue);
    cout << boolin << endl;
 
    return 0;
}


bool Identical(QueType& queue1, QueType& queue2){
    QueType temp1, temp2;
    temp1 = queue1;
    temp2 = queue2;
    while(!temp1.IsEmpty()){
        int item1, item2;
        temp1.Dequeue(item1);
        temp2.Dequeue(item2);
        if(item1 != item2)
            return false;
    }
    return true;
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
        int item;
        temp.Dequeue(item);
        queue.Enqueue(item);
    }
}
