#include <stdio.h>
void addStudent();
void displayStudents();
void printMenu();

struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    int choice;
    do {

        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}


void addStudent() {
    FILE *fp = fopen("studentsData.txt", "a"); // append mode
    if (fp == NULL) {
        printf("Error opening file");
        return;
    }

    struct Student s;

    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name); // read full name with spaces
    printf("Enter Student Marks: ");
    scanf("%f", &s.marks);

    // Write to file in formatted form
    fprintf(fp, "%d,%s,%.2f\n", s.id, s.name, s.marks);

    fclose(fp);
    printf("Student added successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("studentsData.txt", "r");
    if (fp == NULL) {
        printf("No records found. Add students first.\n");
        return;
    }

    struct Student s;
    printf("\n----- Student Records -----\n");

    // Read until EOF
    while (fscanf(fp, "%d,%49[^,],%f\n", &s.id, s.name, &s.marks) == 3) {
        printf("ID: %d | Name: %s | Marks: %.2f\n", s.id, s.name, s.marks);
    }

    printf("---------------------------\n");
    fclose(fp);
}

void printMenu(){

        printf("\n====== Student File System ======\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");


}