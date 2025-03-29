#include<bits/stdc++.h>
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
	cout << "\t\t\t\t\t\t     6-Find line\n";
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
	{
	
	}
	else if(processNumber == 3)
	{
	
	}
	else if (processNumber == 4)
	{
		
	}
	else if (processNumber == 5)
	{
		
	}
	else if (processNumber == 6)
	{
		
	}
	else if (processNumber == 7)
	{
		
	}
	else if (processNumber == 8)
	{
	
	}
	else if (processNumber == 9)
	{
		
	}
	else if (processNumber == 10)
		editor.show();
	else 
		cout << "\n Pleacse Enter valid process Number";

}
int main() {
	int processNumber;
	displayProgram();
	while (true)
	{
		cout << "\nEnter the Number of Process: ";
		cin >> processNumber;
		Processing(processNumber);
	}
}
