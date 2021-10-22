#include "QueType.h"
#include <iostream>
using namespace std;

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  minimum_pos = 0;
  Length = 0;
  items = new ItemType[maxQue];
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  minimum_pos = 0;
  Length = 0;
  items = new ItemType[maxQue];
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
  Length = 0;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
	  rear = (rear + 1) % maxQue;
	  items[rear] = newItem;
	  Length++;
  }
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
	Length--;
  }
}


void QueType::MinDequeue(ItemType& item) {
	int result;
	for (int i = 0; i < Length; i++) {
		if (items[i] != -1) {
			result = items[i];
			break;
		}
	}


	if (IsEmpty()) {
		throw EmptyQueue();
	}
		
	else
	{
		for (int i = 1; i < Length; i++) {
			if (items[i] < result && (items[i] != -1)) {
				result = items[i];
				minimum_pos = i;
			}


		}
		item = result;
		items[minimum_pos] = -1;
	}


}




void QueType::MinEnqueue(ItemType& item) {
	for (int i = 0; i < Length; i++) {
		if (items[i] == -1) {
			items[i] = item;
		}
	}
}