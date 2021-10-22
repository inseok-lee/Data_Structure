#include <iostream>
#include "SortedType.h"

using namespace std;

int main()
{
    SortedType<int> Sortedlist;
    Sortedlist.ResetList();

    Sortedlist.InsertItem(1);
    Sortedlist.InsertItem(2);
    Sortedlist.InsertItem(3);
    Sortedlist.InsertItem(1);
    Sortedlist.InsertItem(2);
    Sortedlist.InsertItem(3);

    Sortedlist.DeleteItem(2);

    for(int i = 0; i < Sortedlist.LengthIs(); i++){
        int num;
        Sortedlist.GetNextItem(num);
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
