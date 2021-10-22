#pragma once
#include "Student.h"

void Swap(Student*& item1, Student*& item2) {

	Student* tempStudent = item1;

	item1 = item2;
	item2 = tempStudent;
}