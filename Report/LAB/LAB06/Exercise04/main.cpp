#include <iostream>
#include "UnsortedType.h"

using namespace std;

int main()
{
    UnsortedType<int> unsortedL;
    unsortedL.ResetList();

    unsortedL.InsertItem(1);
    unsortedL.InsertItem(2);
    unsortedL.InsertItem(3);
    unsortedL.InsertItem(1);
    unsortedL.InsertItem(2);
    unsortedL.InsertItem(3);

    unsortedL.DeleteItem(2);

    for(int i = 0; i < unsortedL.LengthIs(); i++){
        int num;
        unsortedL.GetNextItem(num);
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
