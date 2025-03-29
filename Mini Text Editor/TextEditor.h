#pragma once
#include<bits/stdc++.h>
using namespace std;
class  TextEditor
{
private:
    static map<int, string> lines;
    static int count;
    string LowerCase(string& text);

public:	
    void addLine();
    void insertLine();
    string getLine();
    void deleteLine();
    void deleteRange(int startNumber, int endNumber);
    void updateLine();
    void findAll();
    void findAndReplaceAll(string& oldString, string& newString);
    void show();
    void undo();

};

