# Phonebook Application

## Overview
This is a simple CLI-based Phonebook application implemented in C++.  
It allows users to:

- Add new contacts
- View all contacts
- Update existing contacts
- Delete contacts
- Search for contacts

## Instructions to Run

```bash
g++ main.cpp Phonebook.cpp -o phonebook.exe
.\main.exe
```

## Key Design Decisions & Assumptions

- Language Choice: C++ was chosen for performance and demonstrating backend engineering practices like modular code and separation of interface/implementation.
- CLI Interface: The program is command line only, no GUI or web interface.
- Unique IDs: Each contact has a unique ID generated automatically.
- Error Handling: Basic validation checks are performed (e.g., empty name or phone not allowed).
- Modular Structure: Separate .h and .cpp files for Phonebook and Contact classes.
- No External Libraries: Uses only standard C++ libraries (<iostream>, <fstream>, <sstream>, <vector>).


## Data Storage

- The application uses file-based storage in contacts.csv.
- Each line represents a contact in CSV format: ID,Name,Phone,Email
- On startup, the program loads existing contacts from contacts.csv.
- Any changes (add, update, delete) are immediately saved back to the file to maintain persistence.
- This ensures that data remains even after the program exits.
- Assumption: The CSV file is simple and manually editable. No advanced database is used.