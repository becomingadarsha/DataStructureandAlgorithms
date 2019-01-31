#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node NodeType;

/* Structure 
    (head)[Prev |  | next] <-> [Prev | info | next] <-> [Prev | info | next] <-> [Prev | info | next](last) -> head

*/

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
 * Insert element at beginning of linked lists
 */

void insertatBegin(int item)
{
    NodeType *newnode, *temp;

    newnode = getNode();  //creates the new node
    newnode->info = item; //info section of new node

	if (head == NULL)
	{
		newnode->next = newnode->prev = newnode;
		head = newnode;
	}

    else
    {
            
    temp = head->prev; // Pointer points to last Node

    // setting up previous and next of new node
    newnode->next = head;
    newnode->prev = temp;

    // Update next and previous pointers of start
    // and last
    temp->next = head->prev = newnode;

    // Update start pointer
    head = newnode;
    }

}

/*
 * Insert element at end of linked lists
 */
void insertatEnd(int item)
{
    NodeType *newnode, *temp;

    newnode = getNode(); //creates the new node

    newnode->info = item; //info section of new node

    if (head == NULL) // If the list is empty, create a single node
    // circular and doubly list
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    }

    //if not empty
    else
    {
        /* Find last node */
        temp = head->prev;
        newnode->next = head; // head is going to be next of new_node
        head->prev = newnode; // Make new node previous of head
        newnode->prev = temp; //Make last preivous of new node
        temp->next = newnode; // Make new node next of old last
    }
}

/*
 * delete first node of linked list
 */
void deleteFirst()
{
    NodeType *first, *last, *temp;

    if (head == NULL)
    {
        printf("Void deletion\n");
        return;
    }

    else
    {
        first = head; //first node
        last = head->prev; //last node
        temp = head -> next; //second node
        printf("Deleted item  = %d", head->info);
       
       last -> next = temp;
        temp -> prev = last;
     
        free(first);
        head = temp;
    }
}

/*
 * delete last node of linked list
 */
void deleteLast()
{
       NodeType *first, *last, *temp;

    if (head == NULL)
    {
        printf("Void deletion\n");
        return;
    }

    else
    {   
        first = head; //first node
        last = head->prev; //last node
        temp = last -> prev; //secondlast node
        printf("Deleted item  = %d", last->info);
        temp -> next = head;
        head -> prev = temp;
        free(last);
    }
}

/*
 * display all element in a non-empty list
 */
void displayElements()
{

    NodeType *temp;
    if (head->next == NULL)
    {
        printf("\n Linked list is empty.\n");
        return;
    }

    else
    {
        temp = head;
        printf("\n[ ");
        while (temp->next != head)
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("%d ", temp->info);

        printf("]\n");
    }
}

int main(int argc, char const *argv[])
{
    int item, ch;

    NodeType *head = NULL;

    printf("\n---------------------------------\n");
    printf("\nOperations on circular doubly linked list\n");
    printf("\n---------------------------------\n");
    printf("\n1.Insert node at first");
    printf("\n2.Insert node at last");
    printf("\n3.Delete first Node");
    printf("\n4.Delete last node");
    printf("\n5.Display List ");
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