#include <iostream>
#include "Student.h"
#include "HashTable.h"
using namespace std;

int main() {

	Student stu[100];
	// 한글로 하면 깨지는 현상이 있으니 영어로 진행
	stu[0].InitValue(2003200111, (char*) "david", 3.0);
	stu[1].InitValue(2004200121, (char*) "abc", 3.2);
	stu[2].InitValue(2005200132, (char*) "bcd", 2.7);

	Student emptyItem;
	emptyItem.InitValue(0000000000, (char*) "None", 0.0);

	HashTable<Student> hashTable(emptyItem);
	
	for (int i = 0; i < 3; i++)
		hashTable.InsertItem(stu[i]);

	bool found = false;
	hashTable.RetrieveItem(stu[0], found);

	cout << found << endl;
	cout << stu[0].getName() <<endl;

	return 0;
}