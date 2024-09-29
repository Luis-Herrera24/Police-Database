# Police Database Management System

## Overview
This project is a C++ program for managing police officer data, such as their names, badge numbers, districts, and ranks. Initially, the project was implemented using a `std::map` to store officer data in memory, where the badge number acted as the key and a `Police` object containing officer details as the value. However, the program was later updated to use SQLite to provide persistent storage, ensuring that officer data could be saved and retrieved between program executions.

The program includes features for adding, updating, removing, and displaying officers, as well as for searching by badge number and exporting the officer data to a text file.

## Features
- **Add Officer**: Add a new police officer with their name, badge number, district, and rank.
- **Display All Officers**: Display all currently stored officers in the database.
- **Find Officer by Badge Number**: Search for a specific officer using their badge number.
- **Update Officer Information**: Update an officer's name, district, or rank by badge number.
- **Remove Officer**: Remove a police officer from the database using their badge number.
- **Export Data**: Export officer data to a text file.
- **Persistent Storage**: Store officer data in an SQLite database, allowing data to persist between executions.

## Setup and Requirements

### Prerequisites
- C++ Compiler (e.g., g++, clang++)
- SQLite3 installed on your system

### Project Structure
The main components of this project are:

- **`departmentHeader.hpp`**: This header file contains the class definitions for `Police` and `PoliceDepartment`.
- **`main.cpp`**: The main entry point of the application where the user interacts with the menu to perform operations on the police database.
- **SQLite Database**: The program uses SQLite to store and retrieve officer data from a database file named `PoliceDatabase.db`.

### Compilation Instructions
1. Make sure you have SQLite3 installed.
2. Compile the program using a command similar to:

   ```bash
   g++ -std=c++11 main.cpp -o policeDatabase -lsqlite3
