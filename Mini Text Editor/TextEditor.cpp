#include"TextEditor.h"

int TextEditor::count = 0;
map<int, string> TextEditor::lines;
stack<map<int, string>> TextEditor::history;

void TextEditor::addLine() {
	saveState();
	cin.ignore();
	string text = readAndValidString("Enter your text:");
	lines.emplace(++count, text);
}
void TextEditor::insertLine() {
	saveState();
	map<int, string>newmap;
	int lineNumber;
	string text;
	lineNumber = numberExists("Enter The Number of Line:");
	cin.ignore();
	text = readAndValidString("Enter your text:");
	auto it = lines.begin();
	for (int  i = 1; i <=count+1; i++)
	{
		if (i == lineNumber)
			newmap[i] = text;
		else
		{
			newmap[i] = it->second;
			it++;
		}
	}
	count++;
	lines = newmap;
	newmap.clear();
}
string TextEditor::getLine() {
	saveState();
	int lineNumber;
	lineNumber = numberExists("Enter The Number of Line:");
	return '\n'+lines[lineNumber] + '\n';
}
void TextEditor::deleteLine() {
	saveState();
	int lineNumber;
	lineNumber = numberExists("Enter The Number of Line:");
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
	saveState();
	int lineNumber;
	string text;
	lineNumber = numberExists("Enter The Number of Line:");
	cin.ignore();
	text = readAndValidString("Enter the New text:");
	lines[lineNumber] = text;
}
void TextEditor::findAll() {
	saveState();
	map<int, string>result;
	string search;
	cin.ignore();
	search = readAndValidString("Enter your text");
	int counter = 0;
	for (auto it : lines)
	{
		
		if (LowerCase(it.second).find(LowerCase(search)) != -1) {
			result[++counter] = it.second;
		}
	}
	if (result.empty())
	{
		cout << "\nthere isn't this word\n";
		return;
	}
	for (auto it : result) {
		cout << it.first << "-" << it.second << '\n';
	}
	result.clear();
}
void TextEditor::findAndReplaceAll() {
	saveState();
	string oldString,newString;
	int index;
	bool flag = false;
	cin.ignore();
	oldString = readAndValidString("Enter the old text:");
	newString = readAndValidString("Enter the new text:");
	auto item = lines.begin();
	for (auto it : lines)
	{
		if (LowerCase(it.second).find(LowerCase(oldString)) != -1) {
			flag = true;
			index = LowerCase(it.second).find(LowerCase(oldString));
			item->second.replace(index, it.second.length(), newString);
		}
		item++;
	}
	if (!flag)
		cout << "\nthere isn't this word\n";
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
void TextEditor::deleteRange() {
	saveState();
	int startNumber, endNumber;
	startNumber = numberExists("Enter start number:");
	endNumber = numberExists("Enter end number:");
	map<int, string>result;
	int counter = 0;
	for (int i = 1; i <= count; i++)
	{
		if (i < startNumber || i > endNumber)
			result[++counter] = lines[i];
	}
	lines = result;
	count -= (endNumber - startNumber + 1);
	result.clear();
}
void TextEditor::undo() {
	if (!history.empty()) {
		lines = history.top();
		history.pop();
		count = lines.size();
	}
	else 
		cout << "\nNo previous state to undo.\n";
}
string TextEditor::LowerCase(string & text) {
	string newtext = "";
	for (auto it : text)
		newtext += tolower(it);
	return newtext;
}
string TextEditor::readAndValidString(string message) {
	string text;
	cout << message;
	getline(cin, text);
	while (text == "") {
		cout << "\nWarning! The text cann't be empty\n";
		cout << message;
		getline(cin, text);
	}
	return text;
}
void TextEditor::saveState() {
	history.push(lines);
}
int TextEditor::writeValidNumber(string message) {
	regex numberPattern("^[0-9]+$");
	string input;
	cout << message;
	cin >> input;
	while (!regex_match(input, numberPattern)) {
		cout << "Warning! Pleace Enter only Numbers\n";
		cout << message;
		cin >> input;
	}
	return stoi(input);
}
int TextEditor::numberExists(string message) {
	int lineNumber = writeValidNumber(message);
	while (lineNumber > lines.size())
	{
		cout << "\nThere isn't this Line Number\n";
		lineNumber = writeValidNumber(message);
	}
	return lineNumber;
}