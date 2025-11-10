#include "snippetOrganizer.h"

int main() {
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addSnippet(); break;
            case 2: viewSnippets(); break;
            case 3: searchSnippet(); break;
            case 4: editSnippet(); break;
            case 5: deleteSnippet(); break;
            case 6: exportSnippet(); break;
            case 7: sortSnippets(); break;
            case 8:
                cout << "\nExiting... Thank you for using Code Snippet Organizer!\n";
                break;
            default:
                cout << "\n[!] Invalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
