//CSE 130 Lab 6
//Phonebook Application
//Jesus Ruiz Ramos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Entry {
    char firstName[20];
    char lastName[20];
    int number;
};

// Adds an entry
void addEntry(struct Entry phonebook[], int *count) {
    if (*count < MAX_CONTACTS) {
        printf("Enter first name: ");
        scanf("%s", phonebook[*count].firstName);
        printf("Enter last name: ");
        scanf("%s", phonebook[*count].lastName);
        printf("Enter phone number: ");
        scanf("%d", &phonebook[*count].number);
        (*count)++;
        printf("Entry added successfully.\n");
    } else {
        printf("Cannot add more entries. Contact list full.\n");
    }
}

// Removes an entry
void removeEntry(struct Entry phonebook[], int *count) {
    if (*count > 0) {
        int index;
        printf("Enter the index of the entry to remove (1 to %d): ", *count);
        scanf("%d", &index);
        if ((index-1) >= 0 && (index-1) < *count) {
            for (int i = (index-1); i < *count - 1; i++) {
                phonebook[i] = phonebook[i + 1];
            }
            (*count)--;
            printf("Entry removed successfully.\n");
        } else {
            printf("Invalid index.\n");
        }
    } else {
        printf("No entries to remove.\n");
    }
}

// Displays all etries
void displayEntries(struct Entry phonebook[], int count) {
    if (count > 0) {
        printf("\n| Entry List |\n");
        for (int i = 0; i < count; i++) {
            printf("Entry %d: %s\t %s\t %d\n", i + 1, phonebook[i].firstName, phonebook[i].lastName, phonebook[i].number);
        }
    } else {
        printf("No entries to display.\n");
    }
}

int main() {
    struct Entry phonebook[MAX_CONTACTS];
    int count = 0;
    int choice = 4;

    do {
        printf("\n| Phonebook Menu |\n");
        printf("1. Add Entry\n");
        printf("2. Remove Entry\n");
        printf("3. Display Entries\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(phonebook, &count);
                break;
            case 2:
                removeEntry(phonebook, &count);
                break;
            case 3:
                displayEntries(phonebook, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again...\n");
        }
    } while (choice != 4);

    return 0;
}