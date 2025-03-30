#pragma once
#include<bits/stdc++.h>
#include<regex>
using namespace std;
class  TextEditor
{
private:
    static map<int, string> lines;
    static int count;
    static stack<map<int, string>>history;
    string LowerCase(string& text);
    void saveState();
    string readAndValidString(string message);

public:	
    void addLine();
    void insertLine();
    string getLine();
    int numberExists(string message);
    int writeValidNumber(string message);
    void deleteLine();
    void deleteRange();
    void updateLine();
    void findAll();
    void findAndReplaceAll();
    void show();
    void undo();
    void openFile();
    void closeFile();
};

