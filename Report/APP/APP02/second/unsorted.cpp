// Implementation file for Unsorted.h

#include "unsorted.h"
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
void UnsortedType::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}
void UnsortedType::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}

// 문제1: 재작성한 DeleteItem
void UnsortedType::DeleteItem_a(ItemType item){
    //Function: 아이템을 찾을 때까지 하나씩 체크한 후, 찾으면 삭제를 함
    //Precondition: 아이템이 초기화되어 있어야함
    //Postcondition: 아이템이 리스트에 존재하지 않을 경우에도 리스트는 변화가 없음
    bool deleted = false;
    for(int i = 0; i < length && !deleted; i++){
        if(item.ComparedTo(info[i]) == EQUAL){
            info[i] = info[length - 1];
            deleted = true;
        }
    }
}

// 문제2: 재작성한 DeleteItem
void UnsortedType::DeleteItem_c(ItemType item){
    //Function: 아이템을 찾을 때까지 하나씩 체크한 후, 찾으면 삭제를 함
    //Precondition: 아이템이 초기화되어 있어야함
    //Postcondition: 삭제할 요소가 여러개 있어도 모두 삭제를 함.
    int i = 0;
    while(i < length){
        if(item.ComparedTo(info[i]) == EQUAL){
            info[i] = info[length - 1];
            length--;
        }
        else{
            i++;
        }
    }
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
