#include <iostream>
#include "MaxItem.h"
#include "StackTType.h"

using namespace std;

void CopyStack(StackType<int> stackA){
    
    StackType<int> stackTemp = stackA;
    StackType<int> stackC;
    StackType<int> stackB;
    
    while(!stackTemp.IsEmpty()){
        int num = stackTemp.Top();
        stackTemp.Pop();
        stackC.Push(num);
    }
    
    while(!stackC.IsEmpty()){
        int num = stackC.Top();
        stackC.Pop();
        stackB.Push(num);
    }
    
    while(!stackA.IsEmpty()){
        int num = stackA.Top();
        stackA.Pop();
        cout << num << endl;
    }
    cout << "StackA" << endl << endl;
    
    
    while(!stackB.IsEmpty()){
        int num = stackB.Top();
        stackB.Pop();
        cout << num << endl;
    }
    cout << "StackB" << endl << endl;
}

int main(){
    StackType<int> stack;
    stack.Push(9);
    stack.Push(8);
    stack.Push(4);
    stack.Push(7);
    stack.Push(5);
    stack.Push(3);
    
    CopyStack(stack);
    
    return 0;
}
