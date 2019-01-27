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
NodeType *TOS;

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
void createEmptyStack()
{
    TOS = NULL;
}



void PUSH(int item)
{
    NodeType *newnode;
    newnode = getNode();

    newnode -> info = item;
    if (TOS ==0) {
       TOS = newnode;
       TOS -> next = TOS;
    }
    else {
         newnode -> next = TOS -> next;
         TOS -> next = newnode;
    }
    

}


void POP(){
    NodeType *temp;
    if(TOS == 0){
       printf("\nStack is empty\n");
        return ;
    }    
    
    else if( TOS -> next == TOS)
    {
        printf("Popped item is %d",TOS -> info);
        TOS = NULL;
    }


    else
    {
        temp = TOS -> next;
        TOS -> next = temp -> next;
        printf("\nPopped item is %d\n",temp-> info);
        free(temp);
    }
    

}


void displayElements(){
     NodeType *temp;

     if (TOS == 0) {
        printf("\nStack is empty\n");
        return ;
     }

     else {
        temp =  TOS;
        printf("\nElements in stack are :\n");

        while(temp->next != TOS )
        {
            printf("%d\t", temp -> info);
            temp = temp -> next;
        }

        printf("%d\t",temp -> info);
        
     printf("\n");
     }
     
     
     

}
     
     

int main(int argc, char const *argv[])
{
    int ch,data;
    createEmptyStack();
   
    printf("\n ---- Menu For Program ----\n");
    printf("\n Enter 1. for Push Operation \n ");
    printf("\n Enter 2. for Pull Operation \n ");
    printf("\n Enter 3. to Display Data \n ");
    printf("\n Enter 4. for Exit \n ");
     printf("\n --------------------------\n");

    while(1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        
        switch (ch)
        {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d",&data);
               PUSH(data);
                break;

            case 2:
                POP();
                break;
            
            case 3:
                displayElements();
                break;

            case 4:
                exit(1);
            
            default:
            printf("Wrong Entry");
                break;
        }

    }
    return 0;
}





