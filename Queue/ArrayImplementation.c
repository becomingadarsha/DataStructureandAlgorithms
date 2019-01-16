#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 100
struct Queue{
    int top;
    int rear;
    int item[MAXSIZE];
};

typedef struct Queue Queue;

void createEmptyQueue(Queue *qt)
{
    qt -> top = -1;
    qt -> rear =0;
}

bool isFull(Queue *qt)
{
    if(qt-> top ==MAXSIZE -1)
            return true;
    
    
    else
    {
        return false;
    }
    
}

bool isEmpty(Queue *qt)
{
    if(qt-> top < qt->rear)
            return true;
    
    
    else
    {
        return false;
    }
    
}


void ENQUEUE(Queue *qt,int x)
{
    if(isFull(qt))
    {
        printf("Queue is full..\n");
    }

    
    else
    {
        qt -> rear ++;
        qt -> item[qt->rear] =x;
    }
}


int DEQUEUE(Queue *qt)
{
    int x;
    if(isEmpty(qt))
    {
        printf("Queue is empty..\n");
    }

    
    else
    {
        x = qt->item [qt->top];
        qt -> top ++;
        return x;
    }
}

void display(Queue *qt)
{
    int i;
    if(isEmpty(qt))
    {
        printf("Stack is empty.\n");
    }

    
    else
    {
          for(i=0;i <= qt->rear;i++)
    {
        printf("%d",qt->item[i]);
    }
        printf("\n");
    }
    
  
}
int main(int argc, char const *argv[])
{
    int ch,x;
    Queue qt;

    createEmptyQueue(&qt);
    printf("Enter your choice :\n");
    printf("Press 1. for ENQUEUE\n");
    printf("Press 2. for DEQUEUE\n");
    printf("Press 3. for View Elements\n");
    printf("Press 4. for Exit\n\n\n");

    while( false == false) //using meme in real life
    {

        printf("Enter your choice : ");
        scanf("%d",&ch);
        
        
        switch (ch)
        {
            case 1:
                printf("Enter element to be inserted :");
                scanf("%d",&x);
                ENQUEUE(&qt,x);
                break;
            
            case 2:
                x = DEQUEUE(&qt);
                printf("The removed valeu is %d",x);
                break;
            
            case 3:
                display(&qt);
                exit(1);

            case 4:
                exit(1);

            default:
                break;
        }







    }
    return 0;
}
