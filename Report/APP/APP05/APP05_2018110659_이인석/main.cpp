#include <iostream>
#include "QueType.h"

using namespace std;

void discardoddnum(QueType& myqueue){
    while(true){
        int num;
        // discard first card
        myqueue.Dequeue(num);
        cout << num << " ";

        if(myqueue.IsEmpty()){
            break;
        }

        // move second card to the bottom
        myqueue.Dequeue(num);
        myqueue.Enqueue(num);
    
    }
    cout << endl;
}


int main()
{
    int N;
    cout << "enter number of card" << endl;
    cin >> N;

    QueType myqueue(N);
    for(int i = 0; i < N; i++){
        myqueue.Enqueue(i + 1);
    }

    discardoddnum(myqueue);

    return 0;
}
