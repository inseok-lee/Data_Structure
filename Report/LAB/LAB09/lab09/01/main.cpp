#include <iostream>
#include <fstream>
#include "TreeType.h"
using namespace std;

int main()
{
	TreeType tree;
	/*tree.InsertItem('d');
	tree.InsertItem('a');
	tree.InsertItem('e');
	tree.InsertItem('b');*/

	tree.InsertItem('i');
	tree.InsertItem('b');
	tree.InsertItem('c');
	tree.InsertItem('f');
	tree.InsertItem('a');
	tree.InsertItem('t');
	tree.InsertItem('z');


	tree.Check();

	ofstream outfile;
	outfile.open("test");

	tree.Print(outfile);




}