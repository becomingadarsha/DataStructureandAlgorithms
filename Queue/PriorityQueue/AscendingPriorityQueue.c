#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define SIZE 100

struct pQueue{
    int front;
    int rear;
    int item[SIZE];
};

typedef struct pQueue pQueue;

void createEmptyQueue(pQueue *pq){
    pq ->  front = 0; 
    pq -> rear = -1;
}


bool isEmpty(pQueue *pq){
    
    if (pq -> front > pq-> rear) {
        return true;
    }
    
    else
    {
        return false;
    }
    
}



bool isFull(pQueue *pq){
     if (pq -> rear == SIZE -1) {
        return true;
    }
    
    else
    {
        return false;
    }
}


void Enqueue(pQueue *pq, int data){
    if(isFull(pq))
    {
        printf("\nQueue is full.\n");
    }

    else{
        pq-> rear ++;
        pq->item[ pq-> rear ] = data;
    }
}

void Dequeue(pQueue *pq)
{
    int i,temp=0,x;

    x = pq->item[pq->front];
    
    if (isEmpty(pq)) {
       printf("\nQueue is Empty.\n");
    }

    
    else{
        
        for( i = pq->front+1; i < pq->rear; i++)
        {
            if(x > pq->item[i]){
                temp =i;
                x = pq->item[i];
            }
        }

        
        for( i = temp; i < pq->rear; i++)
        {
           pq->item[i] = pq->item[i+1];
        }
         pq->rear-- ;

         printf("Deleted item is %d\n",x);
    }
    
    
}

void Display(pQueue *pq){
    int i;
    
    if (isEmpty(pq)) {
        printf("\nQueue is EMpty.\n");
    }

    else{
        printf("\nElements of queue are :\n");
        
        for( i = pq->front; i <= pq->rear; i++)
        {
            printf("%d\t",pq->item[i]);
        }
        printf("\n");
        
    }
    
}


int main(int argc, char const *argv[])
{
    int ch,data;
    pQueue pq;

    createEmptyQueue(&pq);

    printf("Menu for the program :\n");

    printf("\n1. Enqueue : ");
    printf("\n2. Dequeue : ");
    printf("\n3. Display : ");
    printf("\n4. Terminate : \n");

    
    while(1){
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            printf("Enter element to be inserted : ");
            scanf("%d",&data);
                Enqueue(&pq, data);
            break;

            case 2:
                 Dequeue(&pq);

           
            break;

            case 3:
                Display(&pq);
            break;

            case 4:
                exit(1);
            break;

            default:
                printf("Wrong entry !:\n");
                break;


        }

        
        }
    
    return 0;
}
