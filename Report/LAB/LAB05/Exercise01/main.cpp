#include <iostream>
#include <random>
#include "QueType.h"

using namespace std;

int main()
{
    QueType myfirst_queue;
    int num_list[10] = {0x00, };
    int item;
    
    // 난수 생성
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 99);
    
    for(int i = 0; i < 10; i++){
        num_list[i] = dis(gen);
    }
    
    // 큐에 저장
    for(int i = 0; i < 10; i++){
        cout << num_list[i] << "\t";
        myfirst_queue.Enqueue(num_list[i]);
    }
    cout << endl;
    
    // 삭제
    for(int i = 0; i < 10; i++){
        myfirst_queue.Dequeue(item);
        cout << item << "\t";
    }
    cout << endl;
    
    return 0;
}
