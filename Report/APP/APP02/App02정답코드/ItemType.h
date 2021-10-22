#pragma once

// The following declarations and definitions go into file 
// ItemType.h. 
#include <iostream>
#include <fstream>
const int MAX_ITEMS = 15;
enum RelationType { LESS, GREATER, EQUAL };

class ItemType
{
public:
    ItemType(); //생성자
    RelationType ComparedTo(ItemType) const; //비교
    void Print(std::ostream&) const; //출력
    void Initialize(double number); //초기화
    int GetValue();
private:
    double value;
};