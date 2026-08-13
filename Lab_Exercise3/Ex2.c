#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100
int main() {
    char *students[MAX_STUDENTS];
    int count = 0;
    char choice;
    do {
        printf("Student Database Menu:\n");
        printf("a. Insert a student name\n");
        printf("b. Delete a student name\n");
        printf("c. Print all student names\n");
        printf("N. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
                if (count < MAX_STUDENTS) {
                    char name[100];
                    printf("Enter student name: ");
                    scanf(" %[^\n]", name);
                    students[count] = (char *)malloc(strlen(name) + 1);
                    if (students[count] == NULL) {
                        printf("Memory allocation failed!\n");
                        break;
                    }
                    strcpy(students[count], name);
                    count++;
                } else {
                    printf("Database is full!\n");
                }
                break;
            case 'b':
                if (count == 0) {
                    printf("Error: No student names in the database to delete.\n");
                } else {
                    printf("Deleted student: %s\n", students[count - 1]);
                    free(students[count - 1]);
                    count--;
                }
                break;
            case 'c':
                if (count == 0) {
                    printf("No students in the database.\n");
                } else {
                    printf("Student List:\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d. %s\n", i + 1, students[i]);
                    }
                }
                break;
            case 'N':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 'N');
    for (int i = 0; i < count; i++) {
        free(students[i]);
    }

 return 0;
}
