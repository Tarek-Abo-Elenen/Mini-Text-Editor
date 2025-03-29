#pragma once
#include<bits/stdc++.h>
using namespace std;
class  TextEditor
{
private:
    static map<int, string> lines;
    static int count;
    static stack<map<int, string>>history;
    string LowerCase(string& text);
    void saveState();
public:	
    void addLine();
    void insertLine();
    string getLine();
    void deleteLine();
    void deleteRange();
    void updateLine();
    void findAll();
    void findAndReplaceAll();
    void show();
    void undo();

};

