
# 📖 Library Management System

A simple C++ project implementing Object-Oriented Programming (OOP) concepts through a Library Management System.  
It allows users to add, remove, borrow, and return books, as well as view borrowing records.

---

## 🎯 Features Implemented

- **OOP Concepts**: Classes, Inheritance, Polymorphism, Encapsulation
- **Data Structures**: Vectors + Smart Pointers (`std::shared_ptr`)
- **Menu Interaction**: Simple text-based menu for user interaction
- **Raw Pointers**: Used in some parts for practice
- **String Manipulation**: For book titles, authors, and dates

---

## 🏗️ System Components

1. **User Class (Abstract)**
   - Base class for Librarian and Member with pure virtual functions

2. **Librarian**
   - Add / Remove books
   - View all books and borrowing records

3. **Member**
   - Borrow / Return books
   - View borrowed books and available books

4. **Book**
   - Attributes: Title, Author, ISBN, isAvailable

5. **BorrowRecord**
   - Links members to their borrowed books with due dates

---

## 🖥️ How to Run

1. Open the project in any C++ IDE (e.g., Visual Studio Code, Code::Blocks).
2. Compile the file `main.cpp`:
   ```bash
   g++ main.cpp -o library
   ./library
   ```
3. Follow the menu instructions:
   - Choose Librarian or Member
   - Perform desired operations from the menu

---

## 🚀 Bonus Features 
***> `IN THE FUTURE`***

- Search for books by title or author
- Track overdue books using simple date strings
