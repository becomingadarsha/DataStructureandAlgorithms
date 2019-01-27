#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node NodeType;

// Two glboal variables to store address of first and last nodes.
NodeType *head;

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
    head = NULL; //if first address is null then list will be empty
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
    if (head == NULL)
    { //if the linked list is empty i.e. first address is null
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode; //there is only one node so first and last is same node
    }

    else
    { //if not empty
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
    }
}

/*
 * Insert element at end of linked lists
 */
void insertatEnd(int item)
{
    NodeType *newnode, *temp;
    newnode = getNode();

    newnode->info = item; //insert item in newnode[info]

    if (head == NULL)
    {                         // if list is empty
        newnode->prev = NULL; //first and last will be new node adress
        newnode->next = NULL;
        head = newnode;
    }

    else //not empty
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
        newnode->info = item;
    }
}

/*
 * delete first node of linked list
 */
void deleteFirst()
{
    NodeType *temp;

    if (head == NULL)
    {
        printf("Void deletion\n");
        return;
    }

    else
    {
        temp = head;
        printf("Deleted item  = %d", temp->info);
        head = head->next;

        head->prev = NULL;

        free(temp);
    }
}

/*
 * delete last node of linked list
 */
void deleteLast()
{
    NodeType *temp, *hold;

    if (head == NULL)
    {
        printf("Void deletion\n");
        return;
    }

    else
    {
        temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        hold = temp->next;
        printf("Deleted item  = %d", hold->info);
        temp->next = NULL;
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

    if (head == NULL)
    { //if adress of head is 0
        printf("\n Linked list is empty.\n");
        return;
    }

    else
    {
        temp = head;
        printf("\n[ ");
        while (temp != NULL)
        {
            printf("%d\t", temp->info);
            temp = temp->next;
        }
        printf("]\n");
    }
}
//Prints all elements in linked list in reverse traversal order.
void ReversePrint()
{
    NodeType *temp;

    temp = head;

    if (head == NULL)
    {
        printf("\n Linked list is empty.\n");
        return;
    } // empty list, exit

    // Going to last Node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Traversing backward using prev pointer
    printf("\nReverse: \n");
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->prev;
    }
    printf("\n");
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
    printf("\n6.Display List from End to Beginning");
    printf("\n7.Exit\n");
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
            ReversePrint();
            break;

        case 7:
            exit(1);

        default:
            printf("\nEnter Correct Choice.\n");
            break;
        }
    }

    return 0;
}