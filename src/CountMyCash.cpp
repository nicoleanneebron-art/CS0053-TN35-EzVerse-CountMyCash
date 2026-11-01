#include "ExpenseInputModule.h"
#include "ExpenseManagementModule.h"
#include "ExpenseModificationModule.h"
#include "ExpenseSummaryModule.h"
#include "FileStorageModule.h"

#include <iostream>
#include <limits>
#include <vector>

namespace {
bool readMenuOption(int &selectedOption) {
  if (std::cin >> selectedOption) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return true;
  }

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return false;
}

bool reloadExpenses(std::vector<Expense> &expenses) {
  if (!loadExpenses(expenses)) {
    std::cout << "Error: Could not load expense records.\n";
    return false;
  }

  return true;
}

void displayMainMenu() {
  std::cout << "\n";
  std::cout << "+--------------------------------------------------+\n";
  std::cout << "|                  COUNT MY CASH                  |\n";
  std::cout << "|             Personal Expense Tracker            |\n";
  std::cout << "+--------------------------------------------------+\n";
  std::cout << "\n";
  std::cout << "MAIN MENU\n\n";
  std::cout << "[1] Add Expense\n";
  std::cout << "[2] View Expenses\n";
  std::cout << "[3] Search Expenses\n";
  std::cout << "[4] Update Expense\n";
  std::cout << "[5] Delete Expense\n";
  std::cout << "[6] Generate Summary\n";
  std::cout << "[0] Exit\n\n";
  std::cout << "Select an option: ";
}
} // namespace

int main() {
  if (!initializeStorage()) {
    std::cout << "Error: Could not initialize storage.\n";
    return 1;
  }

  std::vector<Expense> expenses;

  if (!reloadExpenses(expenses)) {
    return 1;
  }

  int selectedOption = -1;

  while (selectedOption != 0) {
    displayMainMenu();

    if (!readMenuOption(selectedOption)) {
      std::cout << "Invalid menu selection.\n";
      continue;
    }

    switch (selectedOption) {
    case 1:
      addExpense();
      reloadExpenses(expenses);
      break;

    case 2:
      if (reloadExpenses(expenses)) {
        viewExpenses(expenses);
      }
      break;

    case 3:
      if (reloadExpenses(expenses)) {
        searchExpenses(expenses);
      }
      break;

    case 4:
      updateExpense();
      reloadExpenses(expenses);
      break;

    case 5:
      deleteExpense();
      reloadExpenses(expenses);
      break;

    case 6:
      if (reloadExpenses(expenses)) {
        const ExpenseSummary summary = generateSummary(expenses);

        displaySummary(summary);
      }
      break;

    case 0:
      std::cout << "Exiting Count My Cash...\n";
      break;

    default:
      std::cout << "Invalid menu selection.\n";
      break;
    }
  }

  return 0;
}