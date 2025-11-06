#include "snippetOrganizer.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

const string DATA_FILE = "snippets.dat";

// Utility: Get next available ID
int getNextID() {
    ifstream file(DATA_FILE);
    if (!file) return 1;
    
    int maxID = 0;
    string line;
    
    while (getline(file, line)) {
        if (line.find("ID:") == 0) {
            int id = stoi(line.substr(3));
            maxID = max(maxID, id);
        }
    }
    
    return maxID + 1;
}

// Utility: Get current date
string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    return to_string(ltm->tm_mday) + "-" + 
           to_string(ltm->tm_mon + 1) + "-" + 
           to_string(1900 + ltm->tm_year);
}

// Add new snippet
void addSnippet() {
    cin.ignore();
    
    Snippet snip;
    snip.id = getNextID();
    snip.dateCreated = getCurrentDate();
    
    cout << "\nEnter title: ";
    getline(cin, snip.title);
    
    cout << "Enter language (C/C++/Python/etc): ";
    getline(cin, snip.language);
    
    cout << "Enter tags (comma separated): ";
    getline(cin, snip.tags);
    
    cout << "Enter your code (type END on a single line to finish):\n";
    string line;
    while (getline(cin, line) && line != "END") {
        snip.code += line + "\n";
    }
    
    // Write to file
    ofstream file(DATA_FILE, ios::app);
    file << "ID:" << snip.id << "\n"
         << "TITLE:" << snip.title << "\n"
         << "LANG:" << snip.language << "\n"
         << "TAGS:" << snip.tags << "\n"
         << "CODE:\n" << snip.code
         << "END_CODE\n"
         << "DATE:" << snip.dateCreated << "\n"
         << "---\n";
    
    cout << "\n✅ Snippet added successfully!\n";
}

// View all snippets
void viewSnippets() {
    ifstream file(DATA_FILE);
    
    if (!file) {
        cout << "\n[!] No snippets found.\n";
        return;
    }
    
    cout << "\n====== All Snippets ======\n\n";
    
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
        if (line == "---") cout << "\n";
    }
    
    cout << "==========================\n";
}

// Placeholder functions for future weeks
void searchSnippet() {
    cout << "\n[+] Search feature coming in Week 3...\n";
}

void editSnippet() {
    cout << "\n[+] Edit feature coming in Week 3...\n";
}

void deleteSnippet() {
    cout << "\n[+] Delete feature coming in Week 3...\n";
}

void exportSnippet() {
    cout << "\n[+] Export feature coming in Week 4...\n";
}

void sortSnippets() {
    cout << "\n[+] Sort feature coming in Week 4...\n";
}

// Display menu
void displayMenu() {
    cout << "\n=============================================\n"
         << "           CODE SNIPPET ORGANIZER (C++)       \n"
         << "=============================================\n"
         << "1. Add New Snippet\n"
         << "2. View All Snippets\n"
         << "3. Search Snippet\n"
         << "4. Edit Snippet\n"
         << "5. Delete Snippet\n"
         << "6. Export Snippet\n"
         << "7. Sort Snippets\n"
         << "8. Exit\n"
         << "=============================================\n";
}