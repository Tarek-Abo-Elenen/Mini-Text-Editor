#pragma once
#include<bits/stdc++.h>
using namespace std;
class  TextEditor
{
public:
	
    void addLine();
    void insertLine(int lineNumber, string& text);
    string getLine();
    void deleteLine(int lineNumber);
    void deleteRange(int startNumber, int endNumber);
    void updateLine(int lineNumber, string& text);
    map<int, string> findAll(string& search);
    void findAndReplaceAll(string& oldString, string& newString);
    void show();
    void undo();

private:
    static map<int, string> lines;
    static int count;
};

