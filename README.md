# CS0053-TN35-EzVerse-CountMyCash

## Project Overview

Count My Cash is a C++17 console-based personal expense tracker developed for the Programming Tools and Techniques course. The application allows users to record, view, search, update, delete, and summarize personal expense records. Expense data is stored locally in a CSV file so that records can be retained between program runs.

## Features

- Add new expense records
- View all recorded expenses
- Search expenses by category, date, or record ID
- Update existing expense records
- Delete expense records with confirmation
- Generate total and category-based spending summaries
- Save and load expense records using a local CSV file
- Validate menu selections, categories, dates, amounts, and record IDs
- Handle invalid and malformed user input

## Project Structure

```text
CountMyCash/
│
├── src/
│   ├── CountMyCash.cpp
│   ├── ExpenseInputModule.cpp
│   ├── ExpenseManagementModule.cpp
│   ├── ExpenseModificationModule.cpp
│   ├── ExpenseSummaryModule.cpp
│   └── FileStorageModule.cpp
│
├── include/
│   ├── Expense.h
│   ├── Category.h
│   ├── ExpenseSummary.h
│   ├── ExpenseInputModule.h
│   ├── ExpenseManagementModule.h
│   ├── ExpenseModificationModule.h
│   ├── ExpenseSummaryModule.h
│   └── FileStorageModule.h
│
├── tests/
│   ├── testDeleteExpense.cpp
│   ├── testEmptyExpenses.cpp
│   ├── testExpenseModification.cpp
│   ├── testExpenseSummary.cpp
│   └── testUpdateExpense.cpp
│
├── data/
│   └── expenses.csv
│
├── .clang-format
├── .gitignore
├── build.bat
├── build.sh
└── README.md
```

## Modules

- `CountMyCash.cpp`  
  Contains the main menu, application flow, module integration, and program exit handling.

- `ExpenseInputModule.cpp`  
  Handles the creation of new expense records and validates descriptions, categories, amounts, and dates.

- `ExpenseManagementModule.cpp`  
  Displays all expense records and supports searching by category, date, and record ID.

- `ExpenseModificationModule.cpp`  
  Handles updating and deleting existing expense records.

- `ExpenseSummaryModule.cpp`  
  Calculates and displays the total number of expenses, total amount spent, and spending totals by category.

- `FileStorageModule.cpp`  
  Handles the creation, loading, and saving of expense records using a local CSV file.

## Data Storage

Expense records are stored locally in:

```text
data/expenses.csv
```

The CSV file uses the following format:

```text
expenseId,description,categoryId,amount,date
```

Example record:

```text
1,"Groceries",1,850.00,"2026-10-20"
```

Category IDs are assigned as follows:

```text
1 - Food
2 - Transportation
3 - Utilities
```

The `data/expenses.csv` file and its containing directory are created automatically when the application starts.

## Requirements

The following software is required to build and run the application:

- A C++17-compatible compiler
- GCC or MinGW-w64
- Git Bash or Windows Terminal

To verify that G++ is installed and available in the system path, run:

```bash
g++ --version
```

## Build and Run

Run the commands from the project root directory.

### Git Bash

Build the application:

```bash
bash build.sh
```

Run the application:

```bash
./build/CountMyCash
```

### Windows Terminal

Build the application:

```bat
.\build.bat
```

Run the application:

```bat
.\build\CountMyCash.exe
```

The build scripts compile all C++ source files using the C++17 standard and place the compiled application inside the `build` directory.

## Sample Input and Output

The following example demonstrates adding an expense and generating a spending summary.

### Sample Input

```text
1
Groceries
1
850.00
2026-10-20
6
0
```

### Sample Output

```text
+--------------------------------------------------+
|                  COUNT MY CASH                   |
|             Personal Expense Tracker             |
+--------------------------------------------------+

MAIN MENU

[1] Add Expense
[2] View Expenses
[3] Search Expenses
[4] Update Expense
[5] Delete Expense
[6] Generate Summary
[0] Exit

Select an option: 1

===== ADD EXPENSE =====
Enter expense description: Groceries

Select category:
1. Food
2. Transportation
3. Utilities
Enter category number: 1
Enter amount: 850.00
Enter date (YYYY-MM-DD): 2026-10-20

Expense saved successfully!
Expense ID: 1
Description: Groceries
Category: Food
Amount: 850.00
Date: 2026-10-20

Select an option: 6

===== EXPENSE SUMMARY =====
Number of expenses: 1
Total spent: 850.00

By category:
Food: 850.00
Transportation: 0.00
Utilities: 0.00

Select an option: 0
Exiting Count My Cash...
```
