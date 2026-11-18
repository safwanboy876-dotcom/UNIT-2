#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50
#define STR_LEN 50

// Function Prototypes
int addBook(int ids[], char names[][STR_LEN], char authors[][STR_LEN], char categories[][STR_LEN], float prices[], int avail[], int count);
void displayBooks(int ids[], char names[][STR_LEN], char authors[][STR_LEN], char categories[][STR_LEN], float prices[], int avail[], int count);
void searchById(int ids[], char names[][STR_LEN], char authors[][STR_LEN], char categories[][STR_LEN], float prices[], int avail[], int count);
void searchByName(int ids[], char names[][STR_LEN], char authors[][STR_LEN], char categories[][STR_LEN], float prices[], int avail[], int count);
void issueBook(int ids[], int avail[], int count);
void returnBook(int ids[], int avail[], int count);
void updateBook(int ids[], char names[][STR_LEN], char authors[][STR_LEN], char categories[][STR_LEN], float prices[], int count);
void displayAvailable(int ids[], char names[][STR_LEN], char authors[][STR_LEN], float prices[], int avail[], int count);

// Helper to safely read full lines with spaces
void readLine(char buffer[], int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
}

int main() {
    int ids[MAX_BOOKS];
    char names[MAX_BOOKS][STR_LEN];
    char authors[MAX_BOOKS][STR_LEN];
    char categories[MAX_BOOKS][STR_LEN];
    float prices[MAX_BOOKS];
    int avail[MAX_BOOKS]; // 1 = available, 0 = issued
    
    int count = 0, choice;

    while (1) {
        printf("\n========== LIBRARY MANAGEMENT SYSTEM ==========\n");
        printf("1. Add New Book\n2. Display All Books\n3. Search Book by ID\n");
        printf("4. Search Book by Name\n5. Issue Book\n6. Return Book\n");
        printf("7. Update Book Details\n8. Count Total Books\n9. Display Available Books\n");
        printf("10. Exit\nEnter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1: count = addBook(ids, names, authors, categories, prices, avail, count); break;
            case 2: displayBooks(ids, names, authors, categories, prices, avail, count); break;
            case 3: searchById(ids, names, authors, categories, prices, avail, count); break;
            case 4: searchByName(ids, names, authors, categories, prices, avail, count); break;
            case 5: issueBook(ids, avail, count); break;
            case 6: returnBook(ids, avail, count); break;
            case 7: updateBook(ids, names, authors, categories, prices, count); break;
            case 8: printf("Total books stored: %d\n", count); break;
            case 9: displayAvailable(ids, names, authors, prices, avail, count); break;
            case 10: printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

int addBook(int ids[], char names[][STR_LEN], char authors[][STR_LEN], char categories[][STR_LEN], float prices[], int avail[], int count) {
    if (count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return count;
    }

    int newId;
    printf("Enter Book ID: ");
    scanf("%d", &newId);
    getchar();

    for (int i = 0; i < count; i++) {
        if (ids[i] == newId) {
            printf("Error: Book ID %d already exists!\n", newId);
            return count;
        }
    }

    ids[count] = newId;
    printf("Enter Book Name: ");
    readLine(names[count], STR_LEN);
    printf("Enter Author Name: ");
    readLine(authors[count], STR_LEN);
    printf("Enter Category: ");
    readLine(categories[count], STR_LEN);
    printf("Enter Price: ");
    scanf("%f", &prices[count]);
    avail[count] = 1; // Available by default

    printf("Book added successfully!\n");
    return count + 1;
}

void displayBooks(int ids[], char names