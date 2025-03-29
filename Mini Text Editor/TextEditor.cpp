#include"TextEditor.h"

int TextEditor::count = 0;
map<int, string> TextEditor::lines;
stack<map<int, string>> TextEditor::history;

void TextEditor::saveState() {
	history.push(lines);
}
void TextEditor::addLine() {
	saveState();
	string text;
	cin.ignore();
	cout << "Enter your text:";
	getline(cin, text);
	if (text.empty())
	{
		cout << "\nPlease Enter the text:\n";
	}
	lines.emplace(++count, text);
}
void TextEditor::insertLine() {
	saveState();
	map<int, string>newmap;
	int lineNumber;
	string text;
	cout << "Enter The Number of Line:";
	cin >> lineNumber;
	if (lineNumber > lines.size())
	{
		cout << "\nThere isn't this Line Number\n";
		return;
	}
	cout << "Enter your text:";
	cin.ignore();
	getline(cin, text);
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
	cout << "Enter The Number of Line:";
	cin >> lineNumber;
	if (lineNumber > lines.size())
		return "\nThere isn't this Line Number\n";
	return '\n'+lines[lineNumber] + '\n';
}
void TextEditor::deleteLine() {
	saveState();
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
	saveState();
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
void TextEditor::findAll() {
	saveState();
	map<int, string>result;
	string search;
	cout << "Enter your text:";
	cin.ignore();
	getline(cin, search);
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
	cout << "Enter old text:";
	cin.ignore();
	getline(cin, oldString);
	cout << "Enter new text:";
	getline(cin, newString);
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
	cout << "Enter start number:";
	cin >> startNumber;
	if (startNumber > lines.size())
	{
		cout << "\nThere isn't this Line Number\n";
		return;
	}
	cout << "Enter end number:";
	cin >> endNumber;
	if (endNumber > lines.size())
	{
		cout << "\nThere isn't this Line Number\n";
		return;
	}
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
	else {
		cout << "No previous state to undo.\n";
	}
}
string TextEditor::LowerCase(string & text) {
	string newtext = "";
	for (auto it : text)
		newtext += tolower(it);
	return newtext;
}