Library Management System

This is a simple **Library Management System** written in C. It demonstrates basic operations such as adding, displaying, searching, and deleting books using a linked list.

##  Features

- Add a new book to the list
- Display all available books
- Search for a book by title
- Delete a book by title
- Uses a **singly linked list** for dynamic storage



##  Data Structure Used

struct Book {
    int id;
    char title[100];
    char author[50];
    int copies;
    struct Book *next;
};

main.c: Main program with all logic for book operations

compile:
gcc main.c -o library


run:
./library

Menu Options:
1. Display all Books
2. Add a book
3. Search a book
4. Delete a book
5. Exit

Sample Books:
Don Quixote - Miguel de Cervantes
Alice's Adventures in Wonderland - Lewis Carroll
Harry Potter - J.K Rowling
Wings of Fire - A. P. J. Abdul Kalam

Author
Diya Bajaj

GitHub:github.com/diyabajaj11
