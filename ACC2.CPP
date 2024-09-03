#include <iostream.h>
#include <conio.h>
#include <fstream.h>

// Structure to represent a transaction
struct Transaction {
    int id;
    char date[11];
    char description[50];
    float debit;
    float credit;
    float balance;
};

// Structure to represent a ledger account
struct LedgerAccount {
    char name[50];
    float balance;
    Transaction transactions[100];
    int transactionCount;
};

// Structure to represent a cashbook entry
struct CashbookEntry {
    char date[11];
    char description[50];
    float amount;
    char type; // 'D' for debit, 'C' for credit
};

// Structure to represent a journal entry
struct JournalEntry {
    char date[11];
    char description[50];
    float debit;
    float credit;
};

// Function to display the main menu
void displayMenu() {
    clrscr();
    cout << "Accounting System" << endl;
    cout << "----------------" << endl;
    cout << "1. Ledger" << endl;
    cout << "2. Cashbook" << endl;
    cout << "3. Journal" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to display the ledger menu
void displayLedgerMenu() {
    clrscr();
    cout << "Ledger" << endl;
    cout << "------" << endl;
    cout << "1. Create new account" << endl;
    cout << "2. Display all accounts" << endl;
    cout << "3. Display account details" << endl;
    cout << "4. Add transaction" << endl;
    cout << "5. Back to main menu" << endl;
    cout << "Enter your choice: ";
}

// Function to display the cashbook menu
void displayCashbookMenu() {
    clrscr();
    cout << "Cashbook" << endl;
    cout << "--------" << endl;
    cout << "1. Add new entry" << endl;
    cout << "2. Display all entries" << endl;
    cout << "3. Back to main menu" << endl;
    cout << "Enter your choice: ";
}

// Function to display the journal menu
void displayJournalMenu() {
    clrscr();
    cout << "Journal" << endl;
    cout << "-------" << endl;
    cout << "1. Add new entry" << endl;
    cout << "2. Display all entries" << endl;
    cout << "3. Back to main menu" << endl;
    cout << "Enter your choice: ";
}

// Function to create a new ledger account
void createLedgerAccount(LedgerAccount ledgerAccounts[], int &ledgerAccountCount) {
    clrscr();
    cout << "Create new ledger account" << endl;
    cout << "------------------------" << endl;
    cout << "Enter account name: ";
    cin.getline(ledgerAccounts[ledgerAccountCount].name, 50);
    ledgerAccounts[ledgerAccountCount].balance = 0.0;
    ledgerAccounts[ledgerAccountCount].transactionCount = 0;
    ledgerAccountCount++;
    cout << "Account created successfully!" << endl;
    getch();
}

// Function to display all ledger accounts
void displayLedgerAccounts(LedgerAccount ledgerAccounts[], int ledgerAccountCount) {
    clrscr();
    cout << "Ledger Accounts" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < ledgerAccountCount; i++) {
        cout << "Account Name: " << ledgerAccounts[i].name << endl;
        cout << "Balance: " << ledgerAccounts[i].balance << endl;
        cout << endl;
    }
    getch();
}

// Function to display ledger account details
void displayLedgerAccountDetails(LedgerAccount ledgerAccounts[], int ledgerAccountCount) {
    clrscr();
    cout << "Enter account name: ";
    char accountName[50];
    cin.getline(accountName, 50);
    for (int i = 0; i < ledgerAccountCount; i++) {
        if (strcmp(ledgerAccounts[i].name, accountName) == 0) {
            cout << "Account Name: " << ledgerAccounts[i].name << endl;
            cout << "Balance: " << ledgerAccounts[i].balance << endl;
            cout << "Transactions:" << endl;
            for (int j = 0; j < ledgerAccounts[i].transactionCount; j++) {
                                cout << "Date: " << ledgerAccounts[i].transactions[j].date << endl;
                cout << "Description: " << ledgerAccounts[i].transactions[j].description << endl;
                cout << "Debit: " << ledgerAccounts[i].transactions[j].debit << endl;
                cout << "Credit: " << ledgerAccounts[i].transactions[j].credit << endl;
                cout << "Balance: " << ledgerAccounts[i].transactions[j].balance << endl;
                cout << endl;
            }
            getch();
            return;
        }
    }
    cout << "Account not found!" << endl;
    getch();
}

// Function to add a transaction to a ledger account
void addTransaction(LedgerAccount ledgerAccounts[], int ledgerAccountCount) {
    clrscr();
    cout << "Enter account name: ";
    char accountName[50];
    cin.getline(accountName, 50);
    for (int i = 0; i < ledgerAccountCount; i++) {
        if (strcmp(ledgerAccounts[i].name, accountName) == 0) {
            cout << "Enter transaction date: ";
            cin.getline(ledgerAccounts[i].transactions[ledgerAccounts[i].transactionCount].date, 11);
            cout << "Enter transaction description: ";
            cin.getline(ledgerAccounts[i].transactions[ledgerAccounts[i].transactionCount].description, 50);
            cout << "Enter debit amount: ";
            cin >> ledgerAccounts[i].transactions[ledgerAccounts[i].transactionCount].debit;
            cout << "Enter credit amount: ";
            cin >> ledgerAccounts[i].transactions[ledgerAccounts[i].transactionCount].credit;
            ledgerAccounts[i].transactions[ledgerAccounts[i].transactionCount].balance = ledgerAccounts[i].balance + ledgerAccounts[i].transactions[ledgerAccounts[i].transactionCount].debit - ledgerAccounts[i].transactions[ledgerAccounts[i].transactionCount].credit;
            ledgerAccounts[i].balance = ledgerAccounts[i].transactions[ledgerAccounts[i].transactionCount].balance;
            ledgerAccounts[i].transactionCount++;
            cout << "Transaction added successfully!" << endl;
            getch();
            return;
        }
    }
    cout << "Account not found!" << endl;
    getch();
}

// Function to add a new cashbook entry
void addCashbookEntry(CashbookEntry cashbookEntries[], int &cashbookEntryCount) {
    clrscr();
    cout << "Add new cashbook entry" << endl;
    cout << "---------------------" << endl;
    cout << "Enter date: ";
    cin.getline(cashbookEntries[cashbookEntryCount].date, 11);
    cout << "Enter description: ";
    cin.getline(cashbookEntries[cashbookEntryCount].description, 50);
    cout << "Enter amount: ";
    cin >> cashbookEntries[cashbookEntryCount].amount;
    cout << "Enter type (D/C): ";
    cin >> cashbookEntries[cashbookEntryCount].type;
    cashbookEntryCount++;
    cout << "Entry added successfully!" << endl;
    getch();
}

// Function to display all cashbook entries
void displayCashbookEntries(CashbookEntry cashbookEntries[], int cashbookEntryCount) {
    clrscr();
    cout << "Cashbook Entries" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < cashbookEntryCount; i++) {
        cout << "Date: " << cashbookEntries[i].date << endl;
        cout << "Description: " << cashbookEntries[i].description << endl;
        cout << "Amount: " << cashbookEntries[i].amount << endl;
        cout << "Type: " << cashbookEntries[i].type << endl;
        cout << endl;
    }
    getch();
}

// Function to add a new journal entry
void addJournalEntry(JournalEntry journalEntries[], int &journalEntryCount) {
    clrscr();
    cout << "Add new journal entry" << endl;
    cout << "-------------------" << endl;
    cout << "Enter date: ";
    cin.getline(journalEntries[journalEntryCount].date, 11);
    cout << "Enter description: ";
    cin.getline(journalEntries[journalEntryCount].description, 50);
    cout << "Enter debit amount: ";
    cin >> journalEntries[journalEntryCount].debit;
    cout << "Enter credit amount: ";
    cin >> journalEntries[journalEntryCount].credit;
    journalEntryCount++;
    cout << "Entry added successfully!" << endl;
    getch();
}

// Function to display all journal entries
void displayJournalEntries(JournalEntry journalEntries[], int journalEntryCount) {
    clrscr();
    cout << "Journal Entries" << endl;
    cout << "-------------" << endl;
        for (int i = 0; i < journalEntryCount; i++) {
        cout << "Date: " << journalEntries[i].date << endl;
        cout << "Description: " << journalEntries[i].description << endl;
        cout << "Debit: " << journalEntries[i].debit << endl;
        cout << "Credit: " << journalEntries[i].credit << endl;
        cout << endl;
    }
    getch();
}

int main() {
    LedgerAccount ledgerAccounts[100];
    int ledgerAccountCount = 0;
    CashbookEntry cashbookEntries[100];
    int cashbookEntryCount = 0;
    JournalEntry journalEntries[100];
    int journalEntryCount = 0;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: // Ledger
                while (true) {
                    displayLedgerMenu();
                    int ledgerChoice;
                    cin >> ledgerChoice;
                    switch (ledgerChoice) {
                        case 1: // Create new account
                            createLedgerAccount(ledgerAccounts, ledgerAccountCount);
                            break;
                        case 2: // Display all accounts
                            displayLedgerAccounts(ledgerAccounts, ledgerAccountCount);
                            break;
                        case 3: // Display account details
                            displayLedgerAccountDetails(ledgerAccounts, ledgerAccountCount);
                            break;
                        case 4: // Add transaction
                            addTransaction(ledgerAccounts, ledgerAccountCount);
                            break;
                        case 5: // Back to main menu
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            getch();
                    }
                    if (ledgerChoice == 5) break;
                }
                break;
            case 2: // Cashbook
                while (true) {
                    displayCashbookMenu();
                    int cashbookChoice;
                    cin >> cashbookChoice;
                    switch (cashbookChoice) {
                        case 1: // Add new entry
                            addCashbookEntry(cashbookEntries, cashbookEntryCount);
                            break;
                        case 2: // Display all entries
                            displayCashbookEntries(cashbookEntries, cashbookEntryCount);
                            break;
                        case 3: // Back to main menu
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            getch();
                    }
                    if (cashbookChoice == 3) break;
                }
                break;
            case 3: // Journal
                while (true) {
                    displayJournalMenu();
                    int journalChoice;
                    cin >> journalChoice;
                    switch (journalChoice) {
                        case 1: // Add new entry
                            addJournalEntry(journalEntries, journalEntryCount);
                            break;
                        case 2: // Display all entries
                            displayJournalEntries(journalEntries, journalEntryCount);
                            break;
                        case 3: // Back to main menu
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            getch();
                    }
                    if (journalChoice == 3) break;
                }
                break;
            case 4: // Exit
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                getch();
        }
    }

    return 0;
}