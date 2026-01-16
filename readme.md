# 🧠 Code Snippet Organizer (C++ Console Project)

A console-based **Code Snippet Organizer** built in **C++** for managing and organizing programming snippets efficiently.  
Developed as part of the **Software Development I** course project.

---

## 📘 Project Overview

The **Code Snippet Organizer** is a lightweight, console-based application that allows programmers to **store, view, search, edit, delete, and filter code snippets** easily.  
All snippets are stored persistently in a **file**, making it a simple yet powerful offline code management tool — built entirely using **C++** standard libraries.

---

## 🎯 Objective

To design and implement a **medium-scale console project** in C++ that demonstrates:
- Proficiency in **file handling** (`ifstream`, `ofstream`, `fstream`)
- Application of **classes and structs**
- Modular, function-driven program design
- Data persistence using **binary storage**
- Real-world simulation of organizing and managing developer code snippets

---

## 🚀 Features

| Feature | Description |
|----------|-------------|
| ➕ **Add Snippet** | Add a new code snippet with title, language, tags, and code. Automatically assigns unique ID and creation date. |
| 📂 **View All Snippets** | Display all stored snippets in an easy-to-read console format. |
| 🔍 **Search Snippet** | Search snippets by title, tags, or language (Case sensitive). |
| ✏️ **Edit Snippet** | Update snippet details directly through the console. |
| ❌ **Delete Snippet** | Remove a specific snippet by ID. |
| ⚙️ **Sort Snippets** | Sort snippets by title, language, or date using standard sorting algorithms. |
| 📤 **Export Snippet** | Export a specific snippet to a text file (`.txt`). |
| 📅 **Date Tracking** | Automatically stores the date when a snippet was created. |

---

## 🛠️ Tools & Technologies

- **Language:** C++  
- **IDE:** Code::Blocks / Visual Studio Code / Dev-C++  
- **Compiler:** GCC / MinGW  
- **Environment:** Console Application (No GUI)  
- **File Handling:** Binary I/O (`fstream`)  
- **Storage:** Binary file (`snippets.dat`)  
- **Standard Library:** `<iostream>`, `<fstream>`, `<iomanip>`, `<ctime>`, `<string>`, `<vector>`

---

## 🧱 Project Structure

```
CodesnippetOrganizer/
│
├── main.cpp              # Entry point (main menu + core logic)
├── snippetOrganizer.cpp    # All CRUD operations and utility functions
├── snippetOrganizer.h      # Function prototypes and struct definitions
├── snippets.dat          # Data file (auto-created)
├── snippetOrganizer.exe   # Executable program file (Application)
├── README.md             # Project documentation

```

---

## 🧭 Installation & Setup

### Requirements

- **MinGW Compiler**
- Command prompt/ Terminal

### Clone the Repository
```bash
git clone https://github.com/kawsaruddinpatoary/code-snippet-organizer
```

### Compile the program (MinGW Compiiler)
- Move to the working directory where this project is saved.
- Run this command:

```bash
g++ main.cpp snippetOrganizer.cpp -o snippetOrganizer       
```
### Run the Application
- Use this command to run the program:

```bash
snippetOrganizer.exe        # Windows
./snippetOrganizer          # Linux/Mac
```

---

## 📖 Usage Guide

### Main Menu Options

```
========================================
    CODE SNIPPET ORGANIZER
========================================
1. Add New Snippet
2. View All Snippets
3. Search Snippet
4. Edit Snippet
5. Delete Snippet
6. Export Snippet
7. Sort Snippets
8. Exit
========================================
```

### Sample Workflow

#### Adding a Snippet
```
Enter title: Binary Search Implementation
Enter language (C/C++/Python/etc): C++
Enter tags (comma separated): algorithm, search, arrays
Enter your code (type END on a single line to finish):
[Paste or type your code here]
END

Snippet added successfully!
```

#### Searching for Snippets
- Search by **title**: Enter full or partial title
- Search by **language**: Filter by programming language
- Search by **tags**: Find snippets with specific keywords

#### Exporting a Snippet
- Enter the snippet ID to export
- File is saved to working directory with format: `[title].cpp`
- Extension is based on programming language `(c, cpp, py, cs, js, java)`
- For all other cases, default extension is `.txt`

---

## 🔧 Code Structure

### Snippet Structure (from `snippetOrganizer.h`)

```c
struct Snippet {
    int id;
    string title[100];
    string language[50];
    string tags[200];
    string code[2000];
    string date[20];  // Format: YYYY-MM-DD
};
```

### Key Functions (in `snippetOrganizer.cpp`)

| Function | Purpose |
|----------|---------|
| `addSnippet()` | Creates and saves a new snippet |
| `viewSnippets()` | Displays all stored snippets |
| `searchSnippet()` | Searches by title/tags/language (Case sensitive) |
| `editSnippet()` | Modifies existing snippet data |
| `deleteSnippet()` | Removes snippet by ID |
| `sortSnippets()` | Sorts snippets using comparison algorithms |
| `exportSnippet()` | Exports snippet to text file |
| `getCurrentDate()` | Returns current date in YYYY-MM-DD format |

---

## 📊 Data Persistence

- All snippets are stored in **`snippets.dat`** using **file I/O**
- Data is automatically saved after each operation
- File is created automatically on first run if it doesn't exist
- Uses `fstream` for reading/writing data
---

## 🎓 Learning Outcomes

This project demonstrates:

✅ **File Handling**: File I/O operations with `fstream`  
✅ **Data Structures**: Using structs to organize complex data  
✅ **Modular Programming**: Separation of concerns across multiple files  
✅ **CRUD Operations**: Complete Create, Read, Update, Delete functionality  
✅ **Algorithm Implementation**: Sorting and searching algorithms  
✅ **Memory Management**: Proper handling of file streams and data buffers  
✅ **User Interface Design**: Console-based menu-driven application  
✅ **Data Persistence**: Saving and loading data across program sessions

---

## 🐛 Known Limitations

- Fixed-size character arrays limit snippet length (2000 characters)
- No encryption or password protection for sensitive code
- Console-based interface only (no GUI)

---

## 🚀 Future Enhancements

- 🔐 Add password protection for secure snippets
- 🏷️ Implement tag-based categorization system
- 📁 Support for multiple snippet libraries
- 🔄 Import/Export snippets in JSON or XML format
- 🎨 Syntax highlighting for code display
- 🔗 Integration with GitHub Gists
- 📱 Cross-platform GUI using Qt or wxWidgets

---

## 👥 Team Information

**Course:** Software Development I  
**Project Type:** Console Application (C++)  
**Semester:** Fall-2025  
**Institution:** Northern University Bangladesh

**Team Members:**
- **Kawsar Uddin Patoary - 41240202315**
- **Md Iajuddin Ahmed - 41240202288**

---

## 📝 License

This project is developed for educational purposes as part of the Software Development-I course.  
Feel free to use and modify for learning purposes.

---

## 🙏 Acknowledgments

- Course Instructor: **Mst. Asiya Akter** (Lecturer, CSE)
- C++ Reference Documentation
- Stack Overflow Community
- Fellow classmates for testing and feedback

---

## 📞 Contact

For questions or feedback:
- **Email:** kawsaruddin450@gmail.com
- **GitHub:** [@kawsaruddinpatoary](https://github.com/kawsaruddinpatoary)

---

<div align="center">

**⭐ If you found this project helpful, consider giving it a star!**

Made with ❤️ using C++

</div>
