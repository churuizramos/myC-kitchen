//CSE 130 Lab 7
//Phonebook Application Part 2
//Jesus Ruiz Ramos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

// Secondary function for sortEntries()
void swapEntries(struct Entry *a, struct Entry *b) {
	struct Entry temp = *a;
	*a = *b;
	*b = temp;
}

// Sorts all entries by first name alphabetically
void sortEntries(struct Entry phonebook[], int *count) {
	int i, j;
	
	for (i = 0; i < *count - 1; i++)
	{
		for (j = 0; j < *count - i - 1; j++)
		{
			if (strcmp(phonebook[j].firstName, phonebook[j+1].firstName) > 0)
			{
				swapEntries(&phonebook[j], &phonebook[j+1]);
			}
		}
	}
}

// Searches all entries for an inputted name by first name or last name
void searchName(struct Entry phonebook[], int *count) {
	if (*count > 0){
		char nameIn[20];
		printf("Whose number are you looking for: ");
		scanf("%s", &nameIn);
		
		int i;
		for (i=0; i < *count; i++){
			if (*phonebook[i].firstName == *nameIn) {
				printf("Their number is: %d", phonebook[i].number);
			}
			else if (*phonebook[i].lastName == *nameIn) {
				printf("Their number is: %d", phonebook[i].number);
			}
			else {
				printf("There are no entries with that name...");
			}
		}
	}
	else {
		printf("There are no entries to search...");
	}
}

// Searches and returns a random entry from the array
void randomSearch(struct Entry phonebook[], int count) {
	if (count > 0) {
		srand(time(NULL));
		int randomEntry = rand() % count;
		
		printf("Entry %d: %s\t %s\t %d\n", randomEntry + 1, phonebook[randomEntry].firstName, phonebook[randomEntry].lastName, phonebook[randomEntry].number);
	}
	else {
		printf("There are no entries to search for...\n");
	}
}

// Clears all entries in the phone book
int clearAll(struct Entry phonebook[], int count) {
	if (count > 0){
		for (int i = 0; i < count; i++){
			strcpy(phonebook[i].firstName, "\0");
			strcpy(phonebook[i].lastName, "\0");
			phonebook[i].number = 0;
		}
		printf("All entries have been cleared...\n");
		return count = 0;
	}
	printf("There are no entries to clear...\n");
	return count = count;
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
        printf("4. Sort Entries\n");
        printf("5. Search Name\n");
        printf("6. Random Search\n");
        printf("7. Clear Entries\n");
		printf("8. Exit\n");
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
            	sortEntries(phonebook, &count);
            	break;
            case 5:
            	searchName(phonebook, &count);
            	break;
            case 6:
            	randomSearch(phonebook, count);
            	break;
            case 7:
            	count = clearAll(phonebook, count);
            	break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again...\n");
                break;
        }
    } while (choice != 8);

    return 0;
}