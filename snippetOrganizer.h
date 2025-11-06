#ifndef SNIPPETORGANIZER_H
#define SNIPPETORGANIZER_H

#include <iostream>
#include <string>
#include <ctime>
#include<vector>
using namespace std;

// Structure to store snippet details
struct Snippet {
    int id;
    string title;
    string language;
    string tags;
    string code;
    string dateCreated;
};

// ===== Function Prototypes =====
void addSnippet();
void viewSnippets();
void searchSnippet();
void editSnippet();
void deleteSnippet();
void exportSnippet();
void sortSnippets();
void displayMenu();
string getCurrentDate();

#endif
