#include <iostream>
#include "Student.h"
#include "MergeSort.h"

using namespace std;

int main() {

	Student stu[100];
	stu[0].InitValue(2003200111, (char*) "ÀÌ¿õÀç", 3.0);
	stu[1].InitValue(2004200121, (char*) "±Ç¿ÀÁØ", 3.2);
	stu[2].InitValue(2005200132, (char*) "±èÁøÀÏ", 2.7);
	stu[3].InitValue(2006200132, (char*) "¹Ú±Ô¹Î", 4.0);
	stu[4].InitValue(2006200133, (char*) "¹Ú¹Î", 4.0);
	stu[5].InitValue(2006200139, (char*) "¹Ú¼ö", 4.0);

	MergeSort(stu, 0, 5);
	Print(cout, stu, 6);
	

	return 0;

}