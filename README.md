# MiniBank Application
## Overview
This is a console-based Bank Management System written in C++, utilizing Object-Oriented Programming (OOP) principles. The system allows users to create and manage Savings and Current accounts, perform transactions, and display or delete account information.
It demonstrates core C++ concepts like inheritance, polymorphism, virtual functions, and file-free runtime data handling using vectors.
## Features
### Account Management
- Create Savings and Current accounts with auto-generated unique 6-digit account numbers
- View all existing accounts
- Delete specific accounts by number and type
### Financial Transactions
- Deposit money into an account
- Withdraw money (with overdraft logic for current accounts)
- All operations update balance in real time
### Search & Display
- Search for any account using account number
- Display account details including:
  - Account Number
  - Holder Name
  - Account Type
  - Balance
  - Interest Rate (Savings)
  - Overdraft Limit (Current)
## Technical Details
- Written in C++ (tested with g++)
- Object-Oriented Design using base and derived classes
- Uses vector to store account objects at runtime
- Account identification via randomly generated 6-digit numbers
- Polymorphic behavior with pure virtual withdraw() function
- Secure input logic for deposits/withdrawals with validations
- In-memory system only (no file storage)
## How to Run
1. Compile the program using a C++ compiler (tested with g++)
2. Run the executable
3. Use the menu to navigate through different banking operations
4. Follow on-screen instructions for each operation
## Requirements
- C++ compiler (g++, clang++, MSVC)
- Standard Template Library (STL)
- Runs on Windows, Linux, or MacOS (No platform-specific dependencies)
## Future Enhancements
- Add file I/O for data persistence (accounts.txt)
- Track transaction history for each account
- Add more account types (e.g., Fixed Deposit)
## Notes
- Account numbers are randomly generated and checked for uniqueness.
- The system is in-memory only – once the program exits, data is lost.
