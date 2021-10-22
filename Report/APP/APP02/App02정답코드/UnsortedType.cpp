// Implementation file for sorted.h

#include "UnsortedType.h"
#include <iostream>

UnsortedType::UnsortedType()
{
    length = 0;
}

bool UnsortedType::IsFull() const
{
    return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{
    return length;
}

// void UnsortedType::RetrieveItem(ItemType& item, bool& found)
// {
//     int midPoint;
//     int first = 0;
//     int last = length - 1;

//     bool moreToSearch = first <= last;
//     found = false;
//     while (moreToSearch && !found)
//     {
//         midPoint = (first + last) / 2;
//         switch (item.ComparedTo(info[midPoint]))
//         {
//         case LESS: last = midPoint - 1;
//             moreToSearch = first <= last;
//             break;
//         case GREATER: first = midPoint + 1;
//             moreToSearch = first <= last;
//             break;
//         case EQUAL: found = true;
//             item = info[midPoint];
//             break;
//         }
//     }
// }

// void UnsortedType::DeleteItem(ItemType item)
// {
//     int location = 0;

//     while (item.ComparedTo(info[location]) != EQUAL)
//         location++;
//     for (int index = location + 1; index < length; index++)
//         info[index - 1] = info[index];
//     length--;
// }

void UnsortedType::InsertItem(ItemType item)
{
    info[length] = item;
    length++;
}

void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
    currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item)
// Post: item is current item.
//       Current position has been updated.
{
    currentPos++;
    item = info[currentPos];
}
