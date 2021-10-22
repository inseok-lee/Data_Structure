#include "StackTType.h"
using namespace std;

class DoubleStack
{
private:
    int top_small;
    int top_big;
    int items[MAX_ITEMS];
    bool last_push; // private 맴버 추가
    
public:
    DoubleStack();
    bool IsFull() const;
    bool IsEmpty() const;
    void Push(int item);
    void Print();
    
};

DoubleStack::DoubleStack(){
    top_small = -1;
    top_big = 200;
}

bool DoubleStack::IsFull () const{
    return (top_big == top_small + 1);
}

bool DoubleStack::IsEmpty () const{
    return ((top_small == -1) && (top_big == 200));
}

void DoubleStack::Push(int item){
    if(IsFull()){
        cout << "FULL" << endl;;
    }
    else{
        if(item <= 1000){
            top_small++;
            items[top_small] = item;
            last_push = true;
        }
        else{
            top_big--;
            items[top_big] = item;
            last_push = false;
        }
    }
}


void DoubleStack::Print(){
    cout << "1000이하 스택" << endl;
    
    while(top_small >= 0){
        cout << items[top_small] << " ";
        top_small--;
    }
    cout << endl << endl;
    
    cout << "1000초과 스택" << endl;
    while(top_big <= 199){
        cout << items[top_big] << " ";
        top_big++;
    }
    
    cout << endl << endl;
}
