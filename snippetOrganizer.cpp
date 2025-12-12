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

// Load all snippets into a vector
vector<Snippet> loadSnippets() {
    vector<Snippet> snippets;
    ifstream file(DATA_FILE);
    if (!file) return snippets;

    string line;
    Snippet snip;
    bool readingCode = false;

    while (getline(file, line)) {
        if (line.find("ID:") == 0) {
            snip = Snippet();
            snip.id = stoi(line.substr(3));
        }
        else if (line.find("TITLE:") == 0) {
            snip.title = line.substr(6);
        }
        else if (line.find("LANG:") == 0) {
            snip.language = line.substr(5);
        }
        else if (line.find("TAGS:") == 0) {
            snip.tags = line.substr(5);
        }
        else if (line == "CODE:") {
            readingCode = true;
        }
        else if (line == "END_CODE") {
            readingCode = false;
        }
        else if (readingCode) {
            snip.code += line + "\n";
        }
        else if (line.find("DATE:") == 0) {
            snip.dateCreated = line.substr(5);
        }
        else if (line == "---") {
            snippets.push_back(snip);
        }
    }

    return snippets;
}

// Rewrite all snippets to file
void saveSnippets(const vector<Snippet>& snippets) {
    ofstream file(DATA_FILE, ios::trunc);

    for (auto& snip : snippets) {
        file << "ID:" << snip.id << "\n"
             << "TITLE:" << snip.title << "\n"
             << "LANG:" << snip.language << "\n"
             << "TAGS:" << snip.tags << "\n"
             << "CODE:\n" << snip.code
             << "END_CODE\n"
             << "DATE:" << snip.dateCreated << "\n"
             << "---\n";
    }
}

// Search Snippet
void searchSnippet() {
    cin.ignore();
    string keyword;
    cout << "\nEnter keyword (Title / Language / Tag): ";
    getline(cin, keyword);

    vector<Snippet> snippets = loadSnippets();
    bool found = false;

    for (auto& snip : snippets) {
        if (snip.title.find(keyword) != string::npos ||
            snip.language.find(keyword) != string::npos ||
            snip.tags.find(keyword) != string::npos) {

            cout << "\n[Match Found]\n";
            cout << "ID: " << snip.id << "\n";
            cout << "Title: " << snip.title << "\n";
            cout << "Language: " << snip.language << "\n";
            cout << "Tags: " << snip.tags << "\n";
            cout << "Code:\n" << snip.code;
            cout << "Date: " << snip.dateCreated << "\n";
            cout << "-----------------------\n";

            found = true;
        }
    }

    if (!found) cout << "\n❌ No matching snippet found.\n";
}

// Edit snippet
void editSnippet() {
    int id;
    cout << "\nEnter ID to edit: ";
    cin >> id;

    vector<Snippet> snippets = loadSnippets();
    bool updated = false;

    for (auto& snip : snippets) {
        if (snip.id == id) {
            cin.ignore();
            cout << "New Title: ";
            getline(cin, snip.title);

            cout << "New Language: ";
            getline(cin, snip.language);

            cout << "New Tags: ";
            getline(cin, snip.tags);

            cout << "Enter new Code (END to finish):\n";
            snip.code = "";
            string line;
            while (getline(cin, line) && line != "END") {
                snip.code += line + "\n";
            }
            updated = true;
            break;
        }
    }

    if (updated) {
        saveSnippets(snippets);
        cout << "\n Snippet updated successfully!\n";
    } else {
        cout << "\n ID not found.\n";
    }
}

// Delete snippet
void deleteSnippet() {
    int id;
    cout << "\nEnter ID to delete: ";
    cin >> id;

    vector<Snippet> snippets = loadSnippets();
    int before = snippets.size();

    snippets.erase(remove_if(snippets.begin(), snippets.end(),
                             [&](Snippet& snip){ return snip.id == id; }),
                   snippets.end());

    if (snippets.size() < before) {
        saveSnippets(snippets);
        cout << "\nSnippet deleted successfully!\n";
    } else {
        cout << "\n ID not found.\n";
    }
}

void sortSnippets() {
    ifstream file(DATA_FILE);
    if (!file) {
        cout << "\n[!] No snippets found.\n";
        return;
    }

    struct Snip {
        int id;
        string title, language, tags, code, date;
    };

    vector<Snip> list;
    string line;

    while (getline(file, line)) {
        if (line.find("ID:") == 0) {
            Snip s;
            s.id = stoi(line.substr(3));

            getline(file, line); s.title = line.substr(6);
            getline(file, line); s.language = line.substr(5);
            getline(file, line); s.tags = line.substr(5);

            getline(file, line); // CODE:
            s.code = "";
            while (getline(file, line) && line != "END_CODE") {
                s.code += line + "\n";
            }

            getline(file, line); s.date = line.substr(5);
            getline(file, line); // ---
            list.push_back(s);
        }
    }

    cout << "\nSort by:\n";
    cout << "1. ID\n2. Title\n3. Language\n4. Date\n";
    cout << "Choose: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            sort(list.begin(), list.end(), [](auto &a, auto &b) {
                return a.id < b.id;
            });
            break;

        case 2:
            sort(list.begin(), list.end(), [](auto &a, auto &b) {
                return a.title < b.title;
            });
            break;

        case 3:
            sort(list.begin(), list.end(), [](auto &a, auto &b) {
                return a.language < b.language;
            });
            break;

        case 4:
            sort(list.begin(), list.end(), [](auto &a, auto &b) {
                return a.date < b.date;
            });
            break;

        default:
            cout << "\n[!] Invalid choice.\n";
            return;
    }

    cout << "\n====== Sorted Snippets ======\n\n";
    for (auto &s : list) {
        cout << "ID:" << s.id << "\n";
        cout << "TITLE:" << s.title << "\n";
        cout << "LANG:" << s.language << "\n";
        cout << "TAGS:" << s.tags << "\n";
        cout << "CODE:\n" << s.code;
        cout << "END_CODE\n";
        cout << "DATE:" << s.date << "\n";
        cout << "---\n\n";
    }
    cout << "=============================\n";
}

// Export snippet to file
void exportSnippet() {
    int id;
    cout << "\nEnter snippet ID to export: ";
    cin >> id;

    ifstream file(DATA_FILE);
    if (!file) {
        cout << "\n[!] No snippets found.\n";
        return;
    }

    string line, title, language, code;
    bool found = false;

    while (getline(file, line)) {
        if (line == "ID:" + to_string(id)) {
            found = true;
            getline(file, title);
            getline(file, language);
            getline(file, line); // TAGS skip
            
            // Read CODE:
            getline(file, line); // "CODE:"
            string temp;
            while (getline(file, temp) && temp != "END_CODE") {
                code += temp + "\n";
            }
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "\n[!] Snippet not found.\n";
        return;
    }

    // Extract actual values from TITLE:xxx and LANG:xxx
    title = title.substr(6);
    language = language.substr(5);

    // Convert language to lowercase to check extensions
    string langLower = language;
    transform(langLower.begin(), langLower.end(), langLower.begin(), ::tolower);

    // Determine extension
    string extension = ".txt"; // default

    if (langLower == "cpp" || langLower == "c++") extension = ".cpp";
    else if (langLower == "c") extension = ".c";
    else if (langLower == "python" || langLower == "py") extension = ".py";
    else if (langLower == "java") extension = ".java";
    else if (langLower == "javascript" || langLower == "js") extension = ".js";
    else if (langLower == "html") extension = ".html";
    else if (langLower == "css") extension = ".css";
    else if (langLower == "c#" || langLower == "csharp" || langLower == "c-sharp")
        extension = ".cs";   // ✅ Added for C#

    // Prepare filename
    string safeTitle = title;
    replace(safeTitle.begin(), safeTitle.end(), ' ', '_');

    string filename = safeTitle + extension;

    // Write code to file
    ofstream outFile(filename);
    outFile << code;
    outFile.close();

    cout << "\n✅ Snippet exported successfully as: " << filename << "\n";
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