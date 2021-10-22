#include <iostream>
#include "TextEditor.h"

using namespace std;

int main() {
	TextEditor box;
	box.InsertItem("Hello");
	box.InsertItem("Bye");
	box.InsertItem("Thanks");

	string text;
	box.ResetList();
	for (int i = 0; i < box.GetLength(); i++)
	{
		box.GetNextItem(text);
		cout << text << endl;
	}

	return 0;
}