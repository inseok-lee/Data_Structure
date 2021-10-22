#include <iostream>
#include "StackType.h"

using namespace std;

int main()
{
    StackType stack1;
    StackType stack2;
    int item;
    
    for(int i = 0; i < 4; i++){
        stack1.Push(i);
    }
    
    stack2.Copy(stack1);
    
    while(!stack2.IsEmpty()){
        item = stack2.Top();
        stack2.Pop();
        cout << item << " ";
    }
    cout << endl;
    
    return 0;
}
