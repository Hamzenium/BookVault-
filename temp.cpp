#include "temp.h"

MemoryPool<temp> temp::pool;

void temp::addBook() {
    cout << "\nEnter Book ID :: ";
    getline(cin, id);
    cout << "Enter Book Name :: ";
    getline(cin, name);
    cout << "Enter Book's Author name :: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    file << id << "*" << name << "*" << author << endl;
    file.close();
}

void temp::showAll() {
    file.open("bookData.txt", ios::in);
    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    cout << "\n\n";
    cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" << endl;
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author)) {
        cout << "\t\t " << id << " \t\t\t\t " << name << " \t\t\t " << author << endl;
    }

    file.close();
}

void temp::extractBook() {
    showAll();
    cout << "Enter Book Id :: ";
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    bool found = false;
    cout << "\n\n";
    cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" << endl;
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author)) {
        if (search == id) {
            cout << "\t\t " << id << " \t\t\t " << name << " \t\t\t " << author << endl;
            cout << "Book Extracted Successfully...!\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }

    file.close();
}
