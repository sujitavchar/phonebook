#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using namespace std;

class Contact {
private:
    int id;
    string name;
    string phone;
    string email;

public:
    Contact(int id, string name, string phone, string email);

    int getId() const;
    string getName() const;
    string getPhone() const;
    string getEmail() const;

    void update(string name, string phone, string email);
    string toCSV() const;
};

#endif
