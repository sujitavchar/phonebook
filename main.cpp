#include <iostream>
#include "Phonebook.h"
using namespace std;

int main() {
    Phonebook phonebook("contacts.csv");
    int choice;

    while (true) {
        cout << "\n1.Add 2.View 3.Update 4.Delete 5.Search 6.Exit\nChoose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, phone, email;
            cout<< "Name: "; 
            getline(cin,name);
            cout<< "Phone: "; 
            getline(cin,phone);
            cout<< "Email: "; 
            getline(cin,email);
            phonebook.addContact(name, phone, email);
        }
        else if (choice == 2) phonebook.viewAll();
        else if (choice == 3) {
            int id; string name, phone, email;
            cout<< "ID: "; 
            cin >> id; 
            cin.ignore();
            cout<< "New Name: "; 
            getline(cin, name);
            cout<< "New Phone: "; 
            getline(cin, phone);
            cout<< "New Email: ";
            getline(cin, email);
            phonebook.updateContact(id, name, phone, email);
        }
        else if (choice == 4) {
            int id; cout << "ID: "; cin >> id; cin.ignore();
            phonebook.deleteContact(id);
        }
        else if (choice == 5) {
            string keyword; cout << "Keyword: "; getline(cin, keyword);
            phonebook.search(keyword);
        }
        else if (choice == 6) break;
        else cout << "Invalid\n";
    }
    return 0;
}
