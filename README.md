# Police Database Management System

## Overview

This project is a **Police Database Management System** built using **C++** and **SQLite**. The program allows users to manage a database of police officers, including adding, updating, displaying, and removing officers based on their badge numbers.

### Features:
- Add a new police officer.
- Display all officers in the database.
- Find a police officer by badge number.
- Update officer information (name, district, or rank).
- Remove an officer by badge number.
- Automatically increments badge numbers when adding officers.
- Deletes the database if needed.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Build Instructions](#build-instructions)
- [Program Functionality](#program-functionality)
- [Project Structure](#project-structure)
- [License](#license)

## Installation

### Prerequisites:
- **C++ Compiler** (e.g., g++, clang++, or MSVC).
- **SQLite3** library installed on your system.
- **CMake** (if you prefer building with CMake).

### For Unix-based Systems (Linux/MacOS):
1. Install SQLite if it’s not already installed:
   ```bash
   sudo apt-get install sqlite3 libsqlite3-dev   # For Debian/Ubuntu
   brew install sqlite                           # For MacOS
