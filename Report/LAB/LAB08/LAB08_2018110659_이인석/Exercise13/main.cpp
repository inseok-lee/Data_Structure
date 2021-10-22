#include <iostream>

using namespace std;

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);

int main()
{
    cout << Fibonacci_recursive(10) << endl;
    cout << Fibonacci_non_recursive(10) << endl;

    return 0;
}


int Fibonacci_recursive(int n){
    if(n == 0 || n == 1)
        return n;
    else{
        return Fibonacci_recursive(n - 2) + Fibonacci_recursive(n - 1);
    }
}

int Fibonacci_non_recursive(int n){
    int before = 0, cur = 1, temp = 0;
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else{
        for(int i = 1; i < n; i++){
            temp = cur;
            cur = before + cur;
            before = temp;
        }
        return cur;
    }
}