// Header file for Unsorted List ADT.


template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<"
// and "==" are defined—either an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class UnsortedType
{
public:
  UnsortedType();     // Class constructor
  ~UnsortedType();    // Class destructor

  bool IsFull() const;

  int  LengthIs() const;


  void MakeEmpty();

  void RetrieveItem(ItemType& item, bool& found);
  
  void InsertItem(ItemType item);

  void DeleteItem(ItemType item);

  void ResetList();

  void GetNextItem(ItemType& item);
    
    
    
private:
  NodeType<ItemType>* listData;
  int length;
  NodeType<ItemType>* currentPos;
};

template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}


template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
// Class destructor
{
  MakeEmpty();
}


template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType
//  on the free store; false otherwise.
{
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}


template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}


template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}


template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item,
    bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged.
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}


template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}

// 기존의 DeleteItem
//template <class ItemType>
//void UnsortedType<ItemType>::DeleteItem(ItemType item)
//// Pre:  item's key has been initialized.
////       An element in the list has a key that matches item's.
//// Post: No element in the list has a key that matches item's.
//{
//    NodeType<ItemType>* location = listData;
//    NodeType<ItemType>* tempLocation;
//
//    // Locate node to be deleted.
//    if (item == listData->info)
//    {
//        tempLocation = location;
//        listData = listData->next;        // Delete first node.
//    }
//    else
//    {
//        while (!(item==(location->next)->info))
//            location = location->next;
//
//        // Delete node at location->next
//        tempLocation = location->next;
//        location->next = (location->next)->next;
//    }
//    delete tempLocation;
//    length--;
//}


// 첫번째 개선된 DeleteItem (해결됐지만 모범답안이 깔끔)
//template <class ItemType>
//void UnsortedType<ItemType>::DeleteItem(ItemType item)
//// Pre:  item's key has been initialized.
////       An element in the list has a key that matches item's.
//// Post: No element in the list has a key that matches item's.
//{
//    NodeType<ItemType>* preLoc = NULL;
//    NodeType<ItemType>* location;
//    NodeType<ItemType>* tempLoc;
//
//    bool moreToSearch;
//    moreToSearch = (location != NULL);
//
//    while(item == listData->info){
//        tempLoc = listData;
//        listData = listData->next;
//        location = listData;
//        delete tempLoc;
//        length--;
//    }
//
//    if(listData == NULL){
//        std::cout << "Empty" << std::endl;
//        exit(100);
//    }
//    else{
//        location = listData->next;
//        preLoc = listData;
//    }
//
//    while(moreToSearch){
//        if(item == location->info){
//            tempLoc = location;
//            location = location->next;
//            preLoc->next = location;
//            delete tempLoc;
//            length--;
//        }
//        else{
//            preLoc = location;
//            location = location->next;
//        }
//
//        moreToSearch = (location != NULL);
//    }
//}


// 두번째 개선된 DeleteItem (해결됌, 깔끔)
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType<ItemType>* preLoc = NULL;
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLoc;

    bool moretosearch = true;

    while(moretosearch){
        if(item == location->info){
            if(preLoc == NULL){
                tempLoc = listData;
                listData = listData->next;
                location = listData;
                delete tempLoc;
                length--;
            }
            else{
                tempLoc = location;
                location = location->next;
                preLoc->next = location;
                delete tempLoc;
                length--;
            }
        }
        else{
            preLoc = location;
            location = location->next;
        }
        moretosearch = (location != NULL);
    }
}


// 세번째 개선된 DeleteItem (모범답안)
//template <class ItemType>
//void UnsortedType<ItemType>::DeleteItem(ItemType item)
//{
//    NodeType<ItemType>* location = listData;
//    NodeType<ItemType>* preLoc = NULL;
//    NodeType<ItemType>* tempLocation;
//
//    bool more2Search = (location!=NULL);
//
//    while (more2Search) {
//        if (item == listData->info) // Delete first node.
//        {
//            tempLocation = location;
//            listData = listData->next;
//            location = listData;
//
//            delete tempLocation;
//            length--;
//        }
//        else if (location->info == item) {
//            tempLocation = location;
//            preLoc->next = location->next;
//            location = location->next;
//
//            delete tempLocation;
//            length--;
//        }
//        else {
//            preLoc = location;
//            location = location->next;
//        }
//        more2Search = (location != NULL);
//    }
//}




template <class ItemType>
void UnsortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is current item.
{
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info;
}

