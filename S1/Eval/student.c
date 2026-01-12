// A program that manages student records

#include <stdio.h>
#include <stdlib.h>
#define MAX 10 // 10 students max

// Defining the student struct

struct student
{
    char name[30];
    int age;
    char section;
    float grade;
};

// Declaring the helper functions
void printMenu(void);
void addStudent(int studentCount);
// void removeStudent(void);
int loadStudent(void);
void display(void);

int main()
{
    int choice;
    int studentCount = loadStudent();
    printf("Loaded %d students\n", studentCount);

    while (1)
    {
        printMenu();
        printf("Enter from the given choices 1 / 2 / 3 / 4 \n");
        // Input validation
        while (1)
        {
            scanf("%d", &choice);
            getchar(); // clear buffer
            if ((choice >= 0) && (choice <= 4))
            {
                break;
            }
            else
                printf("Invalid Input Enter correct input again 1 / 2 / 3 / 4 \n");
        }

        switch (choice)
        {
        case 1:
            // Display Current Student Record
            display();
            break;
        case 2:
            // Add a student record
            if (studentCount < MAX)
            {
                // Add function
                addStudent(studentCount);
                studentCount++;
            }
            else
                printf("MAX STUDENT LIMIT CANNOT ADD MORE STUDENTS\n");
            break;
        case 3:
            // Remove a student record
            // removeStudent();
            studentCount--;

            break;
        case 4:
            // Exit using stlib exit function with error code 0
            exit(0);
        default:
            break;
        }
    }
}
void addStudent(int studentCount)
{
    struct student Std;
    // Name input
    printf("ENter Name\n");
    scanf("%29[^\n]", Std.name);
    getchar(); // clear buffer

    // Age input

    printf("ENter age\n");
    scanf("%d", &Std.age);
    getchar(); // clear buffer
    // input Section
    printf("ENter section in the form of a single Character\n");
    scanf("%c", &Std.section);
    getchar(); // clear buffer
    // Input grade

    printf("ENter grade\n");
    scanf("%f", &Std.grade);
    getchar(); // clear buffer
    FILE *fptr;
    // If no students initially then count must be zero
    if (studentCount == 0)
    {
        fptr = fopen("data.txt", "w");
    }
    else
        fptr = fopen("data.txt", "a"); // if students exists initially

    if (fptr == NULL)
    {
        printf("Error in creating or accessing file ! \n");
        return;
    }
    else
    {
        // If file pointer is not null then append normally

        // printing to the file in CSV(Comma separated value) format

        fprintf(fptr, "%s,%d,%c,%f\n", Std.name, Std.age, Std.section, Std.grade);
        printf("Student added successfully returning to main menu...\n");
        fclose(fptr);
        return;
    }
}
int loadStudent(void)
{
    printf("Loading...\n");
    char ch;
    int count = 0;
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    if (fptr == NULL)
    {
        printf("no file existed so count is 0");
        return count;
    }
    else
    {

        while ((ch = fgetc(fptr)) != EOF)
        {
            if (ch == '\n')
            {
                count++;
            }
        }
        printf("Opend file and loaded %d studends in the system\n", count);
        fclose(fptr);
        return count;
    }
}
void printMenu(void)
{
    printf("\n===== STUDENT MENU =====\n");
    printf("1. Display students\n");
    printf("2. Add student\n");
    printf("3. Remove student\n");
    printf("4. Exit\n");
}
void display(void)
{
    printf("Displaying List...\n");
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening file...\n");
        return;
    }
    else
    {
        struct student Std;
        while ((fscanf(fptr, "%[^,],%d,%c,%f\n", Std.name, &Std.age, &Std.section, &Std.grade)) == 4)
        {

            printf("Name : %s\nAge : %d\nSection : %c\nGrade : %.2f\n", Std.name, Std.age, Std.section, Std.grade);
            printf("\n\n");
        }
        fclose(fptr);
        return;
    }
}
