#include<bits/stdc++.h>
#include<regex>
#include"TextEditor.h"
using namespace std;
void displayProgram() {
	cout << "\t";
	for (int i = 0; i < 104; i++)
		cout<<"*";
	cout << "\n\n\t\t\t\t\t\t Hello in our Text Editor\n";
	cout << "\t\t\t\t\t Enter the number of process do you want\n\n";
	cout << "\t\t\t\t\t\t     1-Add line\n";
	cout << "\t\t\t\t\t\t     2-Insert line\n";
	cout << "\t\t\t\t\t\t     3-Update line\n";
	cout << "\t\t\t\t\t\t     4-Delete line\n";
	cout << "\t\t\t\t\t\t     5-Delete Range\n";
	cout << "\t\t\t\t\t\t     6-Find All\n";
	cout << "\t\t\t\t\t\t     7-Find and Replace All lines\n";
	cout << "\t\t\t\t\t\t     8-Get Line\n";
	cout << "\t\t\t\t\t\t     9-Undo\n";
	cout << "\t\t\t\t\t\t     10-Show\n";
	cout << "\n\t";
	for (int i = 0; i < 104; i++)
		cout << "*";
	cout << '\n';
}
void Processing(int processNumber) {
	TextEditor editor;
	if (processNumber == 1)
		editor.addLine();
	else if (processNumber == 2)
		editor.insertLine();
	else if (processNumber == 3)
		editor.updateLine();
	else if (processNumber == 4)
		editor.deleteLine();
	else if (processNumber == 5)
		editor.deleteRange();
	else if (processNumber == 6)
		editor.findAll();
	else if (processNumber == 7)
		editor.findAndReplaceAll();
	else if (processNumber == 8)
		cout << editor.getLine();
	else if (processNumber == 9)
		editor.undo();
	else if (processNumber == 10)
		editor.show();
	else 
		cout << "\n Pleacse Enter valid process Number";

}
bool isValidNumber(const string& input) {
	regex numberPattern("^[0-9]+$");
	return regex_match(input, numberPattern);
}
int main() {
	string processNumber;
	displayProgram();
	while (true)
	{
		cout << "\nEnter the Number of Process: ";
		cin >> processNumber;
		if (!isValidNumber(processNumber))
		{
			cout << "Pleace Enter only Numbers:";
			continue;
		}
		Processing(stoi(processNumber));
	}
}
