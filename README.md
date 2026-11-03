# CS0053-TN35-EzVerse-CoutMyCash
Final Project for Programming Tools and Techniques...

Count My Cash is a C++17 console-based personal expense tracker. It allows users to add, view, search, update, delete, and summarize expense records.

## Features

- Add expenses
- View all expenses
- Search by category, date, or record ID
- Update expense records
- Delete expense records
- Generate spending summaries
- Save and load records using a local CSV file
- Validate user input, dates, amounts, and record IDs

## Project Structure

```text
CountMyCash/
|
|-- include/              Header files
|-- src/                  Source files
|-- data/                 Local expense records
|-- tests/                Test files
|-- build.bat             Windows build script
|-- build.sh              Git Bash build script
|-- README.md             Project documentation
```

## Modules

- `CountMyCash.cpp`  
  Main menu and application flow.

- `ExpenseInputModule.cpp`  
  Adds and validates new expense records.

- `ExpenseManagementModule.cpp`  
  Displays and searches expense records.

- `ExpenseModificationModule.cpp`  
  Updates and deletes existing records.

- `ExpenseSummaryModule.cpp`  
  Calculates and displays expense summaries.

- `FileStorageModule.cpp`  
  Loads and saves records using `data/expenses.csv`.


## Data Storage

Expense records are stored locally in:

```text
data/expenses.csv
```

The CSV format is:

```text
expenseId,description,categoryId,amount,date
```

Example:

```text
1,"Groceries",1,850.00,"2026-10-20"
```

The data file is created automatically when the application starts.

## Requirements

- C++17-compatible compiler
- GCC or MinGW-w64
- Git Bash or Windows Terminal

Check the compiler installation with:

```bash
g++ --version
```

## Build and Run

### Git Bash

```bash
bash build.sh
./build/CountMyCash
```

### Windows Terminal

```bat
.\build.bat
.\build\CountMyCash.exe
```
