#include <iostream>
#include "DoubleStack.h"
#include "MaxItem.h"
#include "StackTType.h"
using namespace std;

int main() {
    DoubleStack stack;
    for(int i = 0; i < 200; i++){
        stack.Push(i*10);
    }
    
    stack.Print();
    
}
