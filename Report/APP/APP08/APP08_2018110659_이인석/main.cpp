#include <iostream>
#include "TreeType.h"

using namespace std;

int main()
{
    TreeType tree;
    int N; // 1 <= N <= 50
    int M;
    int num;

    cout << "트리의 노드의 개수: ";
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;
        tree.InsertItem(num);
    }

    cout << "제거할 노드의 개수: ";
    cin >> M;

    tree.ResetTree(PRE_ORDER);
    tree.ResetTree(IN_ORDER);
    tree.ResetTree(POST_ORDER);

    ItemType item;
    bool finished = false;
    for(int j = 0; j < M; j++){
        tree.GetNextItem(item, IN_ORDER, finished);
        tree.DeleteItem(item);
    }

    return 0;
}