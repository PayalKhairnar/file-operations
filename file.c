#include <stdio.h>

void addBook() {
    FILE *fp = fopen("library.txt", "a");  // Open file in append mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char book[256];

    printf("Enter the name of the book you have taken: ");
    scanf(" %255[^\n]", book);  // Skip leftover newlines

    fprintf(fp, "%s\n", book);
    fclose(fp);

    printf("Book added to your list.\n");
}

void viewBooks() {
    FILE *fp = fopen("library.txt", "r");  // Open file in read mode
    if (fp == NULL) {
        printf("No tasks found. File does not exist yet.\n");
        return;
    }

    char book[256];

    printf("\n--- LIST OF BOOKS ---\n");

    // Read lines using fscanf, stop when fscanf fails
    while (fscanf(fp, " %255[^\n]", book) == 1) {
        printf("- %s\n", book);
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== LIBRARY MANAGEMENT (LIST OF BOOKS) =====\n");
        printf("1. Add book.\n");
        printf("2. View books.\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

