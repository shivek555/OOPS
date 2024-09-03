#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

// Constants
#define MAX_ENTRIES 100
#define DATE_SIZE 11
#define DESC_SIZE 26

// Entry structure to store transaction details
struct Entry {
    char date[DATE_SIZE];
    char description[DESC_SIZE];
    double amount;
};

// Journal class to manage a collection of entries
class Journal {
private:
    Entry entries[MAX_ENTRIES];
    int count;
public:
    Journal() : count(0) {}

    void addEntry(const char* date, const char* description, double amount) {
        if (count < MAX_ENTRIES) {
            strcpy(entries[count].date, date);
            strcpy(entries[count].description, description);
            entries[count].amount = amount;
            count++;
        }
    }

    int getCount() const {
        return count;
    }

    const Entry* getEntries() const {
        return entries;
    }
};

// Ledger class to manage a collection of entries and display them
class Ledger {
private:
    Entry entries[MAX_ENTRIES];
    int count;
public:
    Ledger() : count(0) {}

    void addEntry(const char* date, const char* description, double amount) {
        if (count < MAX_ENTRIES) {
            strcpy(entries[count].date, date);
            strcpy(entries[count].description, description);
            entries[count].amount = amount;
            count++;
        }
    }

    void display() const {
        cout << "Ledger Entries:\n";
        printf("%-15s %-25s %-15s\n", "Date", "Description", "Amount");
        for (int i = 0; i < count; ++i) {
            printf("%-15s %-25s %-15.2f\n", entries[i].date, entries[i].description, entries[i].amount);
        }
    }
};

// CashBook class to manage a collection of entries and display them with a cash balance
class CashBook {
private:
    Entry entries[MAX_ENTRIES];
    int count;
    double cashBalance;

public:
    CashBook() : count(0), cashBalance(0.0) {}

    void addEntry(const char* date, const char* description, double amount) {
        if (count < MAX_ENTRIES) {
            strcpy(entries[count].date, date);
            strcpy(entries[count].description, description);
            entries[count].amount = amount;
            cashBalance += amount;
            count++;
        }
    }

    void display() const {
        cout << "Cash Book Entries:\n";
        printf("%-15s %-25s %-15s\n", "Date", "Description", "Amount");
        for (int i = 0; i < count; ++i) {
            printf("%-15s %-25s %-15.2f\n", entries[i].date, entries[i].description, entries[i].amount);
        }
        printf("Cash Balance: %.2f\n", cashBalance);
    }
};

int main() {
    Journal journal;
    Ledger ledger;
    CashBook cashBook;

    // Adding entries to the journal
    journal.addEntry("2023-06-01", "Sales", 1500.0);
    journal.addEntry("2023-06-02", "Purchase", -500.0);

    // Transferring entries from journal to ledger and cash book
    for (int i = 0; i < journal.getCount(); ++i) {
        const Entry* entry = journal.getEntries();
        ledger.addEntry(entry[i].date, entry[i].description, entry[i].amount);
        cashBook.addEntry(entry[i].date, entry[i].description, entry[i].amount);
    }

    // Display ledger and cash book entries
    ledger.display();
    cashBook.display();

    getch(); // Wait for a key press before closing the console window
    return 0;
}
