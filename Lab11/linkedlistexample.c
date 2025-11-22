#include<stdio.h>
#include<stdlib.h>
// Definition of Node
struct Node
{
    int data;
    struct Node *next;
};
//Global pointer for Head of Node
struct Node *HEAD = NULL;

//Defining Add at Head function
void insertAtHead(int data)
{
    struct Node *nodeToBeAdded;
    nodeToBeAdded = malloc(sizeof(struct Node));
    nodeToBeAdded ->data= data;
    nodeToBeAdded ->next= HEAD;
    HEAD = nodeToBeAdded;
}

//Defining display list function
void dsplayList()
{
    struct Node *temp = HEAD;
    printf("\n++++LINKED LIST++++\n");
    while (temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp ->data;
    }
    printf("  Null\n");

}
//Insert at end function
void insertAtEnd(int data)
{
    struct Node *nodeToBeAdded;
    nodeToBeAdded = malloc(sizeof(struct Node));
    nodeToBeAdded->data=data;
    nodeToBeAdded ->next= NULL;
    {
        HEAD = nodeToBeAdded;
    }
    struct Node *temp = HEAD;
    while (temp->next!=NULL)
    {
        temp =temp->next;
    }
    temp->next = nodeToBeAdded;
    
    
}
//Insert at any Position Function
void insertAtAnyPosition(int data, int position)
{
    //Remaining
}
//Delete by Value function
void deleteByValue(int data)
{
    if (HEAD == NULL)
    {
        printf("List is empty\n");
        return;
    }
    //delete at head
    if (HEAD->data == data)
    {
        
    }
    
    
}





int main()
{

}