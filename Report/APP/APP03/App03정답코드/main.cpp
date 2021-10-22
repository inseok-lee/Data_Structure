#include <iostream>
#include "ItemType.h"
#include "sorted.h"
using namespace std;


int main()
{
    SortedType list1;

	int N;
	cout << "Input N: ";
	cin >> N;

    cout << "Input list Item: ";
    for (int i = 0; i < N; i++)
    {
        int temp_input;
        ItemType temp_item;
        cin >> temp_input;
        temp_item.Initialize(temp_input);
        list1.InsertItem(temp_item);
    }
    cout << endl;

    while(1) {
        int X;
        cout << "Input X: ";
        cin >> X;

        if (X == 0) {
            ItemType temp_item;
            list1.ResetList();
            for (int i = 0; i < N; i++) {
                list1.GetNextItem(temp_item);
                temp_item.Print(cout);
                cout << " ";
            }
            cout << endl;
            break;
        }

        int Y;
        cout << "Input Y: ";
        cin >> Y;

        bool found;
        ItemType temp_item;
        temp_item.Initialize(X);
        list1.RetrieveItem(temp_item, found);
        if (found) {
            list1.DeleteItem(temp_item);
            ItemType temp_item2;
            temp_item2.Initialize(Y);
            list1.InsertItem(temp_item2);
        }
        cout << "Operation completed." << endl << endl;
    }

	return 0;
}
