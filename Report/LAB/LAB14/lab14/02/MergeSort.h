#pragma once
#include "Student.h"
#include <crtdbg.h>


void Merge(Student values[], int leftFirst, int leftLast, int rightFirst, int rightLast) {

	//cout << "Left : " << leftFirst << "Right : " << rightLast <<endl;
	int arySize = rightLast - leftFirst + 1;
	Student* tempArray = new Student[arySize];
	int index = 0;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{

		if (strcmp(values[leftFirst].getName(), values[rightFirst].getName()) <= 0){
			tempArray[index] = values[leftFirst];
			leftFirst++;

		}
		else {

			tempArray[index] = values[rightFirst];
			rightFirst++;
		}

		index++;

	}
	
	while (leftFirst <= leftLast) {
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}
	while (rightFirst <= rightLast) {
		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}



	for (index = saveFirst; index <= rightLast; index++)
		values[index] = tempArray[index-saveFirst];

	delete[] tempArray;
	_CrtDumpMemoryLeaks();


}
void MergeSort(Student values[], int first, int last) {
	
	if (first < last)
	{
		int middle = (first + last) / 2;
		MergeSort(values, first, middle);
		MergeSort(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}
}

