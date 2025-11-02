# 🧠 Code Snippet Organizer (C++ Console Project)

A console-based **Code Snippet Organizer** built in **C++** for managing and organizing programming snippets efficiently.  
Developed as part of the **Software Development I** course project.

---

## 📘 Project Overview

The **Code Snippet Organizer** is a lightweight, console-based application that allows programmers to **store, view, search, edit, delete, and filter code snippets** easily.  
All snippets are stored persistently in a **binary file**, making it a simple yet powerful offline code management tool — built entirely using **C++** standard libraries.

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
| 🔍 **Search Snippet** | Search snippets by title, tags, or language. |
| ✏️ **Edit Snippet** | Update snippet details directly through the console. |
| ❌ **Delete Snippet** | Remove a specific snippet by ID. |
| ⚙️ **Sort Snippets** | Sort snippets by title, language, or date using standard sorting algorithms. |
| 🧩 **Filter by Language** | Display snippets from a specific programming language only. |
| 📤 **Export Snippet** | Export a specific snippet to a text file (`.txt`). |
| 📅 **Date Tracking** | Automatically stores the date when a snippet was created. |
| ℹ️ **About Section** | Displays project and team information. |

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
CodeSnippetManager/
│
├── main.cpp              # Entry point (main menu + core logic)
├── snippetManager.cpp    # All CRUD operations and utility functions
├── snippetManager.h      # Function prototypes and struct definitions
├── snippets.dat          # Binary data file (auto-created)
├── README.md             # Project documentation
└── sample_exports/       # Folder for exported snippet text files
```

### 📄 File Descriptions

- **`main.cpp`**: Contains the main menu loop and user interaction logic
- **`snippetManager.h`**: Defines the `Snippet` structure and declares all function prototypes
- **`snippetManager.cpp`**: Implements all CRUD operations (Create, Read, Update, Delete) and utility functions
- **`snippets.dat`**: Binary file that stores all snippet data persistently
- **`sample_exports/`**: Directory where exported snippets are saved as `.txt` files

---

## 🧭 Installation & Setup

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/yourusername/CodeSnippetManager.git
cd CodeSnippetManager
```

### 2️⃣ Compile the Project

#### Using GCC/MinGW (Command Line)
```bash
g++ main.cpp snippetManager.cpp -o CodeSnippetManager
```

#### Using Code::Blocks
1. Open Code::Blocks
2. Create a new **Console Application** project
3. Add `main.cpp`, `snippetManager.cpp`, and `snippetManager.h` to the project
4. Build and run (F9)

#### Using Visual Studio Code
1. Open the project folder in VS Code
2. Install the **C/C++ extension** by Microsoft
3. Use the integrated terminal to compile:
   ```bash
   g++ main.cpp snippetManager.cpp -o CodeSnippetManager
   ```

### 3️⃣ Run the Application
```bash
./CodeSnippetManager          # Linux/Mac
CodeSnippetManager.exe        # Windows
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
6. Sort Snippets
7. Filter by Language
8. Export Snippet to File
9. About
0. Exit
========================================
```

### Sample Workflow

#### Adding a Snippet
```
Enter snippet title: Binary Search Implementation
Enter programming language: C++
Enter tags (comma-separated): algorithm, search, arrays
Enter code snippet:
[Paste or type your code here]
```

#### Searching for Snippets
- Search by **title**: Enter full or partial title
- Search by **language**: Filter by programming language
- Search by **tags**: Find snippets with specific keywords

#### Exporting a Snippet
- Enter the snippet ID to export
- File is saved to `sample_exports/` directory with format: `snippet_[ID]_[title].txt`

---

## 🔧 Code Structure

### Snippet Structure (from `snippetManager.h`)

```cpp
struct Snippet {
    int id;
    char title[100];
    char language[50];
    char tags[200];
    char code[2000];
    char date[20];  // Format: YYYY-MM-DD
};
```

### Key Functions (in `snippetManager.cpp`)

| Function | Purpose |
|----------|---------|
| `addSnippet()` | Creates and saves a new snippet |
| `viewAllSnippets()` | Displays all stored snippets |
| `searchSnippet()` | Searches by title/tags/language |
| `editSnippet()` | Modifies existing snippet data |
| `deleteSnippet()` | Removes snippet by ID |
| `sortSnippets()` | Sorts snippets using comparison algorithms |
| `filterByLanguage()` | Filters snippets by programming language |
| `exportSnippet()` | Exports snippet to text file |
| `getCurrentDate()` | Returns current date in YYYY-MM-DD format |

---

## 📊 Data Persistence

- All snippets are stored in **`snippets.dat`** using **binary file I/O**
- Data is automatically saved after each operation
- File is created automatically on first run if it doesn't exist
- Uses `fstream` for reading/writing binary data

### Binary File Operations
```cpp
// Writing to file
ofstream outFile("snippets.dat", ios::binary | ios::app);
outFile.write(reinterpret_cast<char*>(&snippet), sizeof(Snippet));

// Reading from file
ifstream inFile("snippets.dat", ios::binary);
inFile.read(reinterpret_cast<char*>(&snippet), sizeof(Snippet));
```

---

## 🎓 Learning Outcomes

This project demonstrates:

✅ **File Handling**: Binary file I/O operations with `fstream`  
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
- Binary file format is not human-readable
- No encryption or password protection for sensitive code
- Console-based interface only (no GUI)
- Limited error handling for file operations

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
**Semester:** [Add your semester]  
**Institution:** [Add your university name]

**Team Members:**
- [Your Name] - [Roll/ID]
- [Team Member 2] - [Roll/ID] *(if applicable)*

---

## 📝 License

This project is developed for educational purposes as part of the Software Development I course.  
Feel free to use and modify for learning purposes.

---

## 🙏 Acknowledgments

- Course Instructor: [Instructor Name]
- C++ Reference Documentation
- Stack Overflow Community
- Fellow classmates for testing and feedback

---

## 📞 Contact

For questions or feedback:
- **Email:** [your.email@example.com]
- **GitHub:** [@yourusername](https://github.com/yourusername)

---

<div align="center">

**⭐ If you found this project helpful, consider giving it a star!**

Made with ❤️ using C++

</div>
