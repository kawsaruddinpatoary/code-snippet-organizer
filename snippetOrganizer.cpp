#include "snippetOrganizer.h"
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

// File for storing all snippets
const string DATA_FILE = "snippets.dat";

// ===== Function Definitions =====

// (Week 1 placeholder) Just basic skeletons — will fill later
void addSnippet() {
    cout << "\n[+] Add Snippet feature coming soon...\n";
}

void viewSnippets() {
    cout << "\n[+] View Snippets feature coming soon...\n";
}

void searchSnippet() {
    cout << "\n[+] Search feature coming soon...\n";
}

void editSnippet() {
    cout << "\n[+] Edit feature coming soon...\n";
}

void deleteSnippet() {
    cout << "\n[+] Delete feature coming soon...\n";
}

void exportSnippet() {
    cout << "\n[+] Export feature coming soon...\n";
}

void sortSnippets() {
    cout << "\n[+] Sort feature coming soon...\n";
}

// Utility: Get current date (dd-mm-yyyy)
string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string date = to_string(ltm->tm_mday) + "-" +
                  to_string(1 + ltm->tm_mon) + "-" +
                  to_string(1900 + ltm->tm_year);
    return date;
}

// Display main menu
void displayMenu() {
    cout << "\n=============================================\n";
    cout << "           CODE SNIPPET ORGANIZER (C++)       \n";
    cout << "=============================================\n";
    cout << "1. Add New Snippet\n";
    cout << "2. View All Snippets\n";
    cout << "3. Search Snippet\n";
    cout << "4. Edit Snippet\n";
    cout << "5. Delete Snippet\n";
    cout << "6. Export Snippet\n";
    cout << "7. Sort Snippets\n";
    cout << "8. Exit\n";
    cout << "=============================================\n";
}