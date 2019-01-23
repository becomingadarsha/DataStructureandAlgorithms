#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Node{
    int info;
    struct Node *next;
};

typedef struct Node NodeType;
NodeType *front, *rear;

void createEmptyQueue(){
    front =0;
    rear =0;
}


NodeType * getNode(){
    NodeType *ptr;
    ptr = (NodeType*) malloc(sizeof(NodeType));
    return ptr;
}

void ENQUEUE(int item){

    NodeType *newnode;
    newnode =getNode();

    
    if (rear == 0) {
        newnode -> info = item;
        newnode -> next = NULL;
        rear = front = newnode;
    }
    else {
       newnode -> info = item;
       newnode -> next = NULL;
       rear -> next = newnode;
       rear = newnode;
    }
    
}

void DEQUEUE(){
    NodeType *temp;

    
    if (rear == NULL) {
        printf("\nQueue is Empty.\n");
        return;
    }

    
    else if(front -> next == NULL)
    {
        temp = front;
        front = front -> next;    
        printf("\nDeleted item is %d", temp-> info);
        free(temp);
    }
    
    else {
        temp = front;
        front = front -> next;
        printf("\nDeleted item is %d", temp-> info);
        free(temp);
    }
    
}

void displayElements(){
     
     NodeType *temp;
     

     if( rear == NULL){
          printf("\nQueue is Empty.\n");
        return;
     }

     
     else
     {
        temp = front;
         while(temp != NULL){
        printf("%d\t",temp -> info);
        temp = temp -> next;
    }
    printf("\n");
     }
     
    
}


int main(int argc, char const *argv[])
{
    int ch,item;
    createEmptyQueue();
    printf("\nMENU FOR PROGRAM\n");
    printf("Press 1. for ENQUEUE\n");
    printf("Press 2. for DEQUEUE\n");
    printf("Press 3. for View Elements\n");
    printf("Press 4. for Exit\n\n\n");

    while(1) 
    {

        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        
        
        switch (ch)
        {
            case 1:
                printf("Enter element to be inserted :");
                scanf("%d",&item);
                ENQUEUE(item);
                break;
            
            case 2:
               DEQUEUE();
                break;
            
            case 3:
                displayElements();
               break;

            case 4:
                exit(1);

            default:
            printf("\nWrong Entry.\n");
                break;
        }

    }
    return 0;

}

