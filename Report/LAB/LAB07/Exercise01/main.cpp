#include <iostream>
#include "SortedType.h"

using namespace std;

int main()
{
    SortedType<char> sortedLL;
    sortedLL.ResetList();
    for(char ch = 65; ch < 68; ch++){
        sortedLL.InsertItem(ch);
    }
    
    sortedLL.PrintReverse();
    
    return 0;
}
