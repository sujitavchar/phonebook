#include "Phonebook.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

//Contact Implementation 
Contact::Contact(int id, string name, string phone, string email)
    : id(id), name(name), phone(phone), email(email) {}

int Contact::getId() const { return id; }
string Contact::getName() const { return name; }
string Contact::getPhone() const { return phone; }
string Contact::getEmail() const { return email; }

void Contact::update(string name, string phone, string email) {
    this->name = name;
    this->phone = phone;
    this->email = email;
}

string Contact::toCSV() const {
    return to_string(id) + "," + name + "," + phone + "," + email;
}

//Phonebook Implementation
Phonebook::Phonebook(string file) :filename(file) {
    loadFromFile();
    nextId =generateNextId();
}

int Phonebook::generateNextId() {
    int maxId = 0;
    for (auto c : contacts)
        if (c.getId() > maxId)
            maxId = c.getId();
    return maxId+1;
}

void Phonebook::loadFromFile() {
    ifstream fileStream(filename);
    if (!fileStream.is_open()) return;

    string line;
    while (getline(fileStream, line)) {
        stringstream ss(line);
        string idStr, name, phone, email;
        getline(ss,idStr, ',');
        getline(ss,name, ',');
        getline(ss,phone, ',');
        getline(ss,email, ',');
        contacts.push_back(Contact(stoi(idStr),name, phone, email));
    }
}

void Phonebook::saveToFile() {
    ofstream fileStream(filename);
    for (auto c : contacts)
        fileStream << c.toCSV() << "\n";
}

void Phonebook::addContact(string name, string phone, string email) {
    if (name.empty() || phone.empty()) {
        cout<< "Name and phone cannot be empty\n";
        return;
    }
    contacts.push_back(Contact(nextId++, name, phone, email));
    saveToFile();
    cout<< "Contact added successfully\n";
}

void Phonebook::updateContact(int id, string name, string phone, string email) {
    for (auto &c : contacts) {
        if (c.getId() == id) {
            c.update(name, phone, email);
            saveToFile();
            cout<<"Updated successfully\n";
            return;
        }
    }
    cout << "Contact not found\n";
}

void Phonebook::deleteContact(int id) {
    auto it = remove_if(contacts.begin(), contacts.end(),
                        [id](Contact c){ return c.getId() == id; });
    if (it == contacts.end()) {
        cout << "Contact not found\n";
        return;
    }
    contacts.erase(it, contacts.end());
    saveToFile();
    cout << "Deleted successfully\n";
}

void Phonebook::viewAll() {
    if (contacts.empty()) {
        cout << "No contacts\n";
        return;
    }
    for (auto c : contacts)
        cout << "ID: " << c.getId()<< " | Name: " << c.getName()<< " | Phone: " << c.getPhone() << " | Email: " << c.getEmail()<< "\n";
}

void Phonebook::search(string keyword) {
    bool found = false;
    for (auto c : contacts) {
        if (c.getName().find(keyword) != string::npos ||
            c.getPhone().find(keyword) != string::npos ||
            c.getEmail().find(keyword) != string::npos) {
            cout << "ID: " << c.getId()<< " | Name: " << c.getName()<< " | Phone: " << c.getPhone()<< " | Email: " << c.getEmail() << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matching contacts\n";
}
