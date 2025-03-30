#include<bits/stdc++.h>
#include<regex>
#include"TextEditor.h"
using namespace std;
void displayProgram() {
	cout << "\n*************** The menu of program ***************";
	cout << "\n\n\tHello in our Text Editor\n";
	cout << "Enter the number of process do you want\n\n";
	cout << "\t 1-Add line\n";
	cout << "\t 2-Insert line\n";
	cout << "\t 3-Update line\n";
	cout << "\t 4-Delete line\n";
	cout << "\t 5-Delete Range\n";
	cout << "\t 6-Find All\n";
	cout << "\t 7-Find and Replace All lines\n";
	cout << "\t 8-Get Line\n";
	cout << "\t 9-Undo\n";
	cout << "\t 10-Show\n\n";
	cout << "***************************************************\n";
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
	editor.closeFile();
}
int main() {
	TextEditor e;
	e.openFile();
	char exit;
	while (true)
	{
		displayProgram();
		Processing(e.writeValidNumber("\nEnter the Number of Process: "));
		cout << "\nDo you want to make another process y/n:";
		cin >> exit;
		if (exit == 'n')
			break;
	}
}
