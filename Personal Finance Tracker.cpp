#include <iostream>
#include <string>
using namespace std;
const int max_transactions = 100;
const int max_categories = 20;
string transactionDates[max_transactions];
double transactionAmounts[max_transactions];
string transactionDescriptions[max_transactions];
string transactionCategories[max_transactions];
int transactionCount = 0;
string categories[max_categories];
double categoryTotals[max_categories] = {0};
int categoryCount = 0;
void addTransaction();
void generateMonthlyReport();
int findCategoryIndex(const string& category);
int main()
{
    int choice;
    do

    {
        cout << "\nPersonal Finance Tracker\n";
        cout << "1. Add Transaction\n";
        cout << "2. Generate Monthly Report\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addTransaction();
            break;
        case 2:
            generateMonthlyReport();
            break;
        case 3:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    while (choice != 3);
    return 0;

}

void addTransaction()
{
    if (transactionCount >= max_transactions)
    {
        cout << "Transaction limit reached. Cannot add more transactions.\n";
        return;
    }
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> transactionDates[transactionCount];
    cout << "Enter amount: ";
    cin >> transactionAmounts[transactionCount];
    cin.ignore();
    cout << "Enter description: ";
    getline(cin, transactionDescriptions[transactionCount]);
    cout << "Enter category: ";
    getline(cin, transactionCategories[transactionCount]);
    int categoryIndex = findCategoryIndex(transactionCategories[transactionCount]);
    if (categoryIndex == -1)
    {
        if (categoryCount >= max_categories)
        {
            cout << "Category limit reached. Cannot add new category.\n";

            return;
        }
        categories[categoryCount] = transactionCategories[transactionCount];
        categoryIndex = categoryCount++;
    }
    categoryTotals[categoryIndex] += transactionAmounts[transactionCount];
    transactionCount++;
    cout << "Transaction added successfully.\n";
}
void generateMonthlyReport()
{
    double totalIncome = 0, totalExpenses = 0;
    for (int i = 0; i < transactionCount; ++i)
    {
        if (transactionAmounts[i] > 0)
        {
            totalIncome += transactionAmounts[i];
        }
        else
        {
            totalExpenses += transactionAmounts[i];
        }
    }
    cout << "\nMonthly Report:\n";

    cout << "Total Income: $" << totalIncome << endl;
    cout << "Total Expenses: $" << -totalExpenses << endl;
    cout << "Savings: $" << (totalIncome + totalExpenses) << endl;
    cout << "\nExpenses by Category:\n";
    for (int i = 0; i < categoryCount; ++i)
    {
        cout << categories[i] << ": $" << categoryTotals[i] << endl;
    }
}
int findCategoryIndex(const string& category)
{
    for (int i = 0; i < categoryCount; ++i)
    {
        if (categories[i] == category)
        {
            return i;
        }
    }
    return -1;
}
