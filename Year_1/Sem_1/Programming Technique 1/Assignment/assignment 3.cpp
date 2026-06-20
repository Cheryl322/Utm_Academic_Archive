#include <iostream>
#include<string>
using namespace std;

const int MAX_BOOKS = 100;

string title[MAX_BOOKS];
string author[MAX_BOOKS];
int year[MAX_BOOKS];

void displayMainMenu();
void addBook(int&);
void displayLibrary(int);
void searchByTitle(int);

int main() {
    int count = 0;
    int choice;

    do {
        displayMainMenu();
        cout << "Enter your choice: "; 
        cin >> choice;
        cout<<"\n\n";

        switch (choice) {
            case 1:
                addBook(count);
                break;
            case 2:
                displayLibrary( count);
                break;
            case 3:
                searchByTitle(count);
                break;
            case 4:
                cout << "Goodbye!\n\n"<<"-------------------------------\n\n"; 
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n\n"; 
        }
    } while (choice != 4);
    system("pause");
    return 0;
}

void displayMainMenu() {
    cout<<"<<<<<Library Management System>>>>>"<<endl; 
    cout<<"=============================================="<<endl;
    cout<<"1. Add a Book\n"; 
    cout<<"2. Display Library\n"; 
    cout<<"3. Search by Title\n"; 
    cout<<"4. Quit\n"; 
}

void addBook(int& count) {
    if (count < MAX_BOOKS) {
        cout << "Enter book title: "; 
        cin.ignore();
        getline(cin,title[count]);

        cout << "Enter author name: "; 
        getline(cin,author[count]);

        cout << "Enter publication year: "; 
        cin >> year[count];

        cout << "\nBook added successfully!\n\n"; 

        count++;
    } else {
        cout << "Library is full. Cannot add more books.\n\n";
    }
}

void displayLibrary(int count) {
    if (count > 0) {
        cout << "Library Contents:\n\n";
        cout<<"====================\n\n";
        for (int i = 0; i < count; i++) {
            cout << "Title: " << title[i] <<endl; 
            cout << "Author: " <<author[i]<<endl; 
            cout << "Year: " <<year[i]<<"\n\n"; 
        }
    } else {
        cout << "No books in the library.\n\n"; 
    }
}

void searchByTitle(int count) {
    if (count > 0) {
        char searchtitle[100];
        cout << "Enter the title to search: "; 
        cin.ignore();
        cin.getline(searchtitle,100);

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (searchtitle == title[i]) {
                cout << "Book Found:\n\n";
                cout<<"=========================="<<endl; 
                cout << "\nTitle: "<<title[i] << "\n"; 
                cout << "Author: "<<author[i] << "\n"; 
                cout << "Year: "<<year[i] << "\n\n"; 
                found = true;
                break;
            }
        }

        if (found== false) {
            cout << "Book not found.\n"; 
        }
    } else {
        cout << "No books in the library.\n\n";
    }
}