#include <stdio.h>
#include <stdlib.h>

// Definition of Node
struct node
{
    int data;
    struct node *next;
};

// Global pointer for Head of Node
struct node *HEAD = NULL;

// Defining Add at Head function
void insertAtHead(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = HEAD;
    HEAD = newNode;
}

// Defining display list function (FIXED)
void dsplayList()
{
    struct node *temp = HEAD;
    printf("\n++++LINKED LIST++++\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        // FIX APPLIED HERE: Must assign the pointer (temp->next) to the pointer variable (temp)
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at end function
void insertAtEnd(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    // Empty list check
    if (HEAD == NULL)
    {
        HEAD = newNode;
        return;
    }

    // Non empty list
    struct node *temp = HEAD;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at any Position Function
void insertAtAnyPosition(int data, int position)
{
    // 1 based index i.e HEAD = 1
    if (position < 1)
    {
        printf("Position must be 1 or greater!\n");
        return;
    }
    if (position == 1)
    {
        insertAtHead(data);
        return;
    }

    // Insert after head
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    struct node *currNode = HEAD;
    int i;

    // Loop to stop at the node at position (N-1)
    for (i = 1; i < position - 1 && currNode != NULL; i++)
    {
        currNode = currNode->next;
    }

    if (currNode == NULL)
    {
        printf("Position out of range! (List is too short)\n");
        free(newNode);
        return;
    }

    // Link the new node
    newNode->next = currNode->next;
    currNode->next = newNode;
}

// Delete by Value function
void deleteByValue(int data)
{
    if (HEAD == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // 1. Delete at head
    if (HEAD->data == data)
    {
        struct node *temp;
        temp = HEAD;
        HEAD = HEAD->next;
        free(temp);
        printf("Value %d deleted from head.\n", data);
        return;
    }

    // 2. Delete in the list after head
    struct node *currNode = HEAD;

    // Search loop stops when the next node is the target, or the end is reached
    while (currNode->next != NULL && currNode->next->data != data)
    {
        currNode = currNode->next;
    }

    if (currNode->next == NULL)
    {
        // Traversal reached the end and didn't find the value
        printf("Value %d not found\n", data);
    }
    else // (currNode->next->data == data) is true
    {
        // Found the node, perform bridge and deletion
        struct node *temp;
        temp = currNode->next;
        currNode->next = temp->next; // Bridge the gap
        free(temp);
        printf("Value %d deleted.\n", data);
    }
}

int main()
{
    int choice, value, pos;
    while (1)
    {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
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
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtHead(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtAnyPosition(value, pos);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(value);
            break;
        case 5:
            dsplayList();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}