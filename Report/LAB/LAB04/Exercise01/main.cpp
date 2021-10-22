#include <iostream>
#include "MaxItem.h"
#include "StackTType.h"

using namespace std;

int main(){
    StackType<int> stack;
    for(int i = 0; i < 6; i++){
        stack.Push(i + 1);
    }
    
    while(!stack.IsEmpty()){
        int result = stack.Top();
        stack.Pop();
        cout << result << endl;
    }
    cout << endl;
    
    return 0;
}

