#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int info;
    struct Node *next;
};

typedef struct Node NodeType;
NodeType *top;

void createEmptyStack(){
    top = 0;
}

NodeType * getNode(){
    NodeType *ptr;
    ptr = (NodeType*) malloc(sizeof(NodeType));
    return ptr;
}

void PUSH(int item)
{
    NodeType *newnode;
    newnode = getNode();


    if (top ==0) {
        newnode -> info = item;
        newnode -> next = NULL;
        top = newnode;
    }
    else {
         newnode -> info = item;
         newnode -> next = top;
         top = newnode;
    }
    

}


void POP(){
    NodeType *temp;
    if(top == 0){
       printf("\nStack is empty\n");
        return ;
    }    
    
    else
    {
        temp = top;
        top = top -> next;
        printf("\nDeleted item is %d\n",temp-> info);
        free(temp);
    }
    

}


void displayElements(){
     NodeType *temp;

     
     if (top == 0) {
        printf("\nStack is empty\n");
        return ;
     }

     else {
        temp = top;
        printf("\nElements in stack are :\n");
        while(temp != NULL){
            printf("%d\t",temp->info);
            temp = temp -> next;
        }
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





