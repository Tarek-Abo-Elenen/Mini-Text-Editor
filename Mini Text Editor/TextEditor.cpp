#include"TextEditor.h"

int TextEditor::count = 0;
map<int, string> TextEditor::lines;

void TextEditor::addLine() {
	string text;
	cin.ignore();
	cout << "Enter your text:";
	getline(cin, text);
	lines.emplace(++count, text);
}
void TextEditor::insertLine(int lineNumber, string& text) {

}
string TextEditor::getLine() {
	int lineNumber;
	cout << "Enter The Number of Line:";
	cin >> lineNumber;
	if (lineNumber > lines.size())
		return "\nThere isn't this Line Number\n";
	return '\n'+lines[lineNumber] + '\n';
}
void TextEditor::deleteLine() {
	int lineNumber;
	cout << "Enter The Number of Line:";
	cin >> lineNumber;
	if (lineNumber > lines.size())
	{
		cout << "\nThere isn't this Line Number\n";
		return;
	}
	count--;
	lines.erase(lineNumber);
	map<int, string>newmap;
	int counter = 0;
	for (auto i : lines)
		newmap.emplace(++counter, i.second);
	lines = newmap;
	newmap.clear();
}
void TextEditor::updateLine() {
	int lineNumber;
	string text;
	cout << "Enter The Number of Line:";
	cin >> lineNumber;
	if (lineNumber > lines.size())
	{
		cout << "\nThere isn't this Line Number\n";
		return;
	}
	cout << "Enter The new text:";
	cin.ignore();
	getline(cin, text);
	lines[lineNumber] = text;
}
map<int, string> TextEditor::findAll(string& search) {
	return lines;
}
void TextEditor::findAndReplaceAll(string& oldString, string& newString) {

}
void TextEditor::show() {
	cout << endl;
	if (lines.size() == 0)
	{
		cout << "There aren't text\n";
		return;
	}
	for (int i = 1; i <= count; i++)
		cout << i << '-' << lines[i] << endl;
	cout << endl;
}
void TextEditor::deleteRange(int startNumber,int endNumber) {

}
void TextEditor::undo() {

}