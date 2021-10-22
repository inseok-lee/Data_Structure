#include <iostream>
#include "TreeType.h"
using namespace std;


int main() {

	TreeType tree;

	tree.InsertItem('k');
	tree.InsertItem('f');
	tree.InsertItem('o');
	tree.InsertItem('c');
	tree.InsertItem('g');
	tree.InsertItem('p');
	tree.InsertItem('a');

	cout << tree.Smaller(tree, 'g') << endl;
	

	return 0;
}