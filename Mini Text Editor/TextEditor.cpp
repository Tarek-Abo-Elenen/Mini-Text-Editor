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
	cout << '\n';
	return lines[lineNumber]+'\n';
}
void TextEditor::deleteLine(int lineNumber) {

}
void TextEditor::updateLine(int lineNumber, string& text) {

}
map<int, string> TextEditor::findAll(string& search) {
	return lines;
}
void TextEditor::findAndReplaceAll(string& oldString, string& newString) {

}
void TextEditor::show() {
	cout << endl;
	if (lines.size() == 0)
		cout << "There aren't text\n";
	else
		for (int i = 1; i <= count; i++)
			cout << i << '-' << lines[i] << endl;
	cout << endl;
}
void TextEditor::deleteRange(int startNumber,int endNumber) {

}
void TextEditor::undo() {

}