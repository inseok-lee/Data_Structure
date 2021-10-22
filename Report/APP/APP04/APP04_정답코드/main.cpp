#include "StackType.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string symbol;
    StackType stack;
    bool balanced = true;

    cin >> symbol;

    for (int i = 0; i < (signed int)symbol.length(); i++)
    {
        if (symbol[i] == '(')
            stack.Push(symbol[i]);

        else if (symbol[i] == ')')
        {
            if (stack.IsEmpty())
                balanced = false;
            else
                stack.Pop();
        }

        if (balanced == false)
            break;
    }

    if (!stack.IsEmpty() && balanced == true)
        balanced = false;

    if (balanced)
        cout << "O" << endl;
    else
        cout << "X" << endl;

    return 0;
}
   