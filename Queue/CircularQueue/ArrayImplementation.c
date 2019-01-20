#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 100 

struct cQueue {
    int item[SIZE];
    int front;
    int rear;
};

typedef struct cQueue cQueue;

void createEmptyQueue(cQueue *cq) {
    cq ->front=-1;
    cq ->rear=-1;
}

bool isEmpty(cQueue *cq) {
    if(cq-> front==cq->rear) {
        return true;
    }

    else {
        return false;
    }
}

bool isFull(cQueue *cq) {
    if(cq->front==(cq->rear+1)%SIZE) {
        return true;
    }

    else {
        return false;
    }
}

void ENQUEUE(cQueue *cq, int data) {
    if(isFull(cq)) {
        printf("\nCircular Queue Is Full !\n");
    }

    else {
        cq->rear=(cq->rear+1)%SIZE;
        cq->item[cq->rear]=data;
    }
}


void DEQUEUE(cQueue *cq) {
    int temp;

    if(isEmpty(cq)) {
        printf("\nCircular Queue Is Empty !\n");
    }

    else {
        cq->front=(cq->front +1)%SIZE;
        temp=cq->item[cq->front];
         printf("\nDeleted element is %d\n",temp);
    }
}


void displayQueue(cQueue *cq) {
    int i;
    
    if (isEmpty(cq)) {
       printf("\nCircular Queue Is Empty !\n");
    }
    else{
        printf("Elements in queue are:\n");
        for(i=(cq->front+1)%SIZE;i!=cq->rear ;i=(i+1)%SIZE)
        {
            printf("%d\t",cq->item[i]);
        }
        printf("%d\t",cq->item[cq->rear]);
    }
    
}

int main(int argc, char const *argv[]) {
    int ch,data;
    cQueue cq;

    createEmptyQueue(&cq);

    printf("Menu of the program :\n");
    printf("1.Enqueue Operation\n");
    printf("2.Dequeue Operation\n");
    printf("3.View Elements\n");
    printf("4.Exit\n");


    while(1) {
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);


        switch (ch) {
            case 1:
                printf("Enter element to be inserted: \n");
                scanf("%d", &data);
                ENQUEUE(&cq, data);
            break;

            case 2:
                DEQUEUE(&cq);
               
            break;

            case 3:
                displayQueue(&cq);
            break;

            case 4:
                exit(1);

            default:
                break;
        }

    }



    return 0;
}