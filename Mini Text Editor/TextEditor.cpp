#include"TextEditor.h"
void TextEditor::addLine(string& text) {
	lines.emplace(count++, text);
}
void TextEditor::insertLine(int lineNumber, string& text) {

}
string TextEditor::getLine(int lineNumber) {
	return "";
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

}
void TextEditor::deleteRange(int startNumber,int endNumber) {

}
void TextEditor::undo() {

}