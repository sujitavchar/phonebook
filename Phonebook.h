#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <vector>
#include <string>
#include "Contact.h"
using namespace std;

class Phonebook {
private:
    vector<Contact> contacts;
    string filename;
    int nextId;

    void loadFromFile();
    void saveToFile();
    int generateNextId();

public:
    Phonebook(string file);

    void addContact(string name,string phone,string email);
    void updateContact(int id, string name,string phone, string email);
    void deleteContact(int id);
    void viewAll();
    void search(string keyword);
};

#endif
