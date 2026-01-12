#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
struct student { int rollNo;char name[30];struct student *next;};

// Global head
struct student *HEAD = NULL;
int takeInput(int rollNo, char name[]);
void insertAtHead(int rollNo, char name[]);
void insertAtEnd(int rollNo, char name[]);
void insertAtPosition(int position, int rollNo, char name[]);
void deleteValue(int rollNo);
void displayList(void);

int main()
{
    int choice, rollNo, position;
    char name[30];
    while (1)
    {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Roll Number\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
        { // Added error handling for scanf
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ; // Clear buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            rollNo = takeInput(rollNo, name);
            insertAtHead(rollNo, name);
            break;
        case 2:
            rollNo = takeInput(rollNo, name);
            insertAtEnd(rollNo, name);
            break;
        case 3:
            rollNo = takeInput(rollNo, name);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(position, rollNo, name);
            break;
        case 4:
            printf("Enter Roll Number to delete: ");
            scanf("%d", &rollNo);
            deleteValue(rollNo);
            break;
        case 5:
            displayList();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}

int takeInput(int rollNum, char name[])
{
    printf("Enter Roll number : ");
    scanf("%d", &rollNum);
    printf("Enter Name:\n");
    scanf("%s", name);
    return rollNum;
}
void insertAtHead(int rollNum, char name[])
{
    struct student *newStudent = malloc(sizeof(struct student));
    newStudent->rollNo = rollNum;
    strcpy(newStudent->name, name);
    newStudent->next = HEAD;
    HEAD = newStudent;
}
void insertAtEnd(int rollNum, char name[])
{
    // Empty list
    if (HEAD == NULL)
    {
        insertAtHead(rollNum, name);
        return;
    }
    struct student *newStudent = malloc(sizeof(struct student));
    newStudent->rollNo = rollNum;
    strcpy(newStudent->name, name);
    newStudent->next = NULL;
    struct student *temp = HEAD;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newStudent;
}
void insertAtPosition(int position, int rollNum, char name[])
{
    // STARTING INDEX IS 1 i.e head is 1 indexex
    if (position == 1)
    {
        insertAtHead(rollNum, name);
        return;
    }

    struct student *newStudent = malloc(sizeof(struct student));
    newStudent->rollNo = rollNum;
    strcpy(newStudent->name, name);
    struct student *currStudent = HEAD;
    int i;
    for (int i = 1; i < position - 1 && currStudent != NULL; i++)
    {
        currStudent = currStudent->next;
    }
    if (currStudent == NULL)
    {

        printf("End of list, position out of bound\n");
        return;
    }

    newStudent->next = currStudent->next;
    currStudent->next = newStudent;
}
void displayList()
{
    struct student *currStudent = HEAD;
    while (currStudent != NULL)
    {
        printf("Name : %s\n", (*currStudent).name);
        printf("Roll Number : %d\n", (*currStudent).rollNo);
        currStudent = currStudent->next;
        printf("=======>>>>>=======\n");
    }
    printf("NULL\n");
}
void deleteValue(int rollNo)
{
    if (HEAD == NULL)
    {
        printf("List Empty\n");
        return;
    }
    // delete at head
    if (HEAD->rollNo == rollNo)
    {
        struct student *temp = HEAD;
        HEAD = HEAD->next;
        free(temp);
        return;
    }
    // delete after first node

    struct student *currStudent = HEAD;
    while (currStudent->next != NULL && currStudent->next->rollNo != rollNo)
    {
        currStudent = currStudent->next;
    }
    if (currStudent->next != NULL)
    {
        printf("Value Not found\n");
        return;
    }
    struct student *temp = currStudent->next;
    currStudent->next = currStudent->next->next;
    free(temp);
}