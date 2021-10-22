// File: StackType.cpp

#include "StackType.h"
#include <iostream>
StackType::StackType()
{
  top = -1;
}

bool StackType::IsEmpty() const
{
  return (top == -1);
}

bool StackType::IsFull() const
{
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
{
  if( IsFull() )
    throw FullStack();
  top++;
  items[top] = newItem;
}

void StackType::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}

ItemType StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    


// Exercise04 B¹ø.
void StackType::ReplaceItem(int olditem, int newitem) {
	int item;
	StackType temp;

	while (!this->IsEmpty()) {
		item = this->Top();
		this->Pop();
		if (item == olditem) {
			item = newitem;
		}
		temp.Push(item);
	}

	while (!temp.IsEmpty()) {
		item = temp.Top();
		temp.Pop();
		this->Push(item);
	}


}