#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int info;
    struct Node *next;
};

typedef struct Node NodeType;

// Two glboal variables to store address of first and last nodes.
NodeType *first;
NodeType *last;

/*
 *initialise the new node 
 */
NodeType *getNode()
{
    NodeType *ptr;
    ptr = (NodeType *)malloc(sizeof(NodeType));
    return ptr;
}

/*
 * create Empty Linked Lists
 */
void createEmptyList()
{
    first = NULL; //if first address is null then list will be empty
    last = NULL;
}

/*
 * Insert element at beginning of linked lists
 */
void insertatBegin(int item)
{
    NodeType *newnode;

    newnode = getNode(); //creates the new node

    newnode->info = item; //info section of new node

    //filling next(address) section of new node
    if (first == NULL)
    { //if the linked list is empty i.e. first address is null
        newnode->next = newnode;
        first = last = newnode; //there is only one node so first and last is same node
    }

    else
    { //if not empty
        newnode->next = first;
        first = newnode;
        last->next = newnode;
    }
}

/*
 * Insert element at end of linked lists
 */
void insertatEnd(int item)
{
    NodeType *newnode;
    newnode = getNode();

    newnode->info = item; //insert item in newnode[info]

    if (first == NULL)
    {                    // if list is empty
        first = newnode; //first and last will be new node adress
        last = newnode;
        newnode->next = newnode;
    }

    else //not empty
    {
        last->next = newnode; //put address of newNode at [address] on last of previous node
        last = newnode; //last will be now adress of new node
        newnode->next = first;
    }
}

/*
 * delete first node of linked list
 */
void deleteFirst()
{
    NodeType *temp;
    temp = first;
    if (first == NULL)
    {
        printf("Void deletion\n");
        return;
    }

    else if(first == last){
        printf("Deleted item  = %d", temp->info);
        first = NULL;
        last = NULL;
        free(temp);
    }

    else
    {    
        printf("Deleted item  = %d", temp->info);
        first = first->next;

        last-> next = first;

        free(temp);
    }
}

/*
 * delete last node of linked list
 */
void deleteLast()
{
    NodeType *temp, *hold;

    if (first == NULL)
    {
        printf("Void deletion\n");
        return;
    }

   
    else if(first == last){
        temp = first;
        printf("Deleted item  = %d", temp->info);
        first = NULL;
        last = NULL;
        free(temp);
    }

    else
    {
        temp = first;

        while (temp->next != last)
        {
            temp = temp->next;
        }
       
        printf("Deleted item  = %d", last->info);
        hold = temp -> next;
        temp -> next = last -> next;
        last = temp;
        free(hold);
    }
}

/*
 * display all element in a non-empty list
 */
void displayElements()
{
    NodeType *temp;
    //store address of first(head) node of list

    if (first == NULL)
    { //if adress of head is 0
        printf("\n Linked list is empty.\n");
        return;
    }

    else
    {
        temp = first;
        printf("\n[ ");
        while(temp != last){
            printf("%d\t", temp -> info);
            temp = temp -> next;
        }
        printf("%d\t",last -> info);
        printf("]\n");
    }
}

int main(int argc, char const *argv[])
{
    int item, ch;

    createEmptyList();

    printf("\n---------------------------------\n");
    printf("\nOperations on circular linked list\n");
    printf("\n---------------------------------\n");
    printf("\n1.Insert node at first");
    printf("\n2.Insert node at last");
    printf("\n3.Delete first Node");
    printf("\n4.Delete last node");
    printf("\n5.Display List from Beginning to end");
    printf("\n6.Exit\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    while (1)
    {

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            insertatBegin(item);
            break;

        case 2:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            insertatEnd(item);
            break;

        case 3:
            deleteFirst();
            break;

        case 4:
            deleteLast();
            break;

        case 5:
            displayElements();
            break;

        case 6:
            exit(1);

        default:
            printf("\nEnter Correct Choice.\n");
            break;
        }
    }

    return 0;
}
