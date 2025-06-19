#include "temp.h"

int main() {
    temp* obj = new temp();

    char choice;
    cout << "----------------------------------" << endl;
    cout << "1-Show All Books" << endl;
    cout << "2-Extract Book" << endl;
    cout << "3-Add books(ADMIN)" << endl;
    cout << "4-Exit" << endl;
    cout << "----------------------------------" << endl;
    cout << "Enter Your Choice :: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case '1':
            obj->showAll();
            break;
        case '2':
            obj->extractBook();
            break;
        case '3':
            obj->addBook();
            break;
        case '4':
            delete obj;
            return 0;
        default:
            cout << "Invalid Choice...!";
    }

    delete obj;
    return 0;
}
