#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int info;
    struct Node *next;
};

typedef struct Node NodeType;

// Two glboal variables to store address of first and last nodes. 
NodeType *first =NULL , *last = NULL;



/*
 *initialise the new node 
 */
NodeType* getNode(){ 
    NodeType *ptr;
    ptr = (NodeType *) malloc(sizeof(NodeType));
    return ptr;
}


/*
 * create Empty Linked Lists
 */
void createEmptyList(){ 
    first =NULL; //if first address is null then list will be empty
    printf("\nList is emptied.\n");
} 


/*
 * Insert element at beginning of linked lists
 */
void insertatBegin(int item){
    NodeType *newnode;
    NodeType *temp;

    temp = first; //hold the address of the first node of list(which is already present)
    
    newnode = getNode(); //creates the new node 

    newnode ->info = item; //info section of new node 

    //filling next(address) section of new node
    if(first ==NULL){ //if the linked list is empty i.e. first address is null
        newnode ->next =NULL;
        first = last = newnode; //there is only one node so first and last is same node
    }

    else{ //if not empty 
        newnode ->next = temp;
        first = newnode;
    }

}



/*
 * Insert element at end of linked lists
 */
void insertatEnd(int item){
    NodeType *newnode;
    newnode =getNode();

    newnode -> info =item; //insert item in newnode[info]
    newnode -> next =NULL; //newnode[next] =NULL so that it will be end of linked list
    
    if (first == NULL) { // if list is empty
        first = newnode; //first and last will be new node adress
        last = newnode; 
    }
    
    else //not empty
    {
        last -> next = newnode; //put address of newNode at [address] on last of previous node
        last = newnode; //last will be now adress of new node
    }

}


/*
 * Insert element at nth position of linked lists
 */
void insertatgivenPosition(int item){ //insert node at nth position
    int pos,i;
    NodeType *newnode, *temp;

    newnode =getNode();
    newnode -> info = item; //filling info section with item

    printf("Enter the position of node where you want to store the element : ");
    scanf("%d",&pos);

    if(first == NULL){
        printf("\nEmpty linked list.\n");

        return;
    }

    
    else
    {
        temp = first; //asssign ptr temp to first node

        for( i = 1; i < pos-1; i++)
        {
            temp = temp ->next; //points next node continously untill it reaches (one less than position = pos-1)
        }

        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
    
       

}
    

/*
 * delete first node of linked list
 */
void delteFirst()
{
    NodeType *temp;
    
    if (first == NULL) {
        printf("Void deletion\n");
        return ;
    }

    else
    {
        temp = first;
         printf("Deleted item  = %d", temp -> info);
        first = first -> next;
       
        free(temp);
    }
}


/*
 * delete last node of linked list
 */
void deleteLast()
{
    NodeType *temp;
    NodeType *hold;
    
    if (first == NULL) {
        printf("Void deletion\n");
        return ;
    }

    else if(first -> next == NULL){
        hold =first;
        first =NULL;
        printf("Deleted item  = %d", hold -> info);
        free(hold);
    }

    else
    {
        temp = first;
 
       while(temp-> next -> next != NULL){
           temp = temp -> next;
       }
       hold = temp -> next;
     printf("Deleted item  = %d", hold -> info);
       temp-> next =NULL;
       free(hold);
    }
}


/*
 * delete nth node of linked list
 */
void delete_nthNode(){
    NodeType *hold, *temp;
     int i,pos;
        if (first == NULL)
       {
            printf("No node to delete\n");
        return;
       }
        
    
    else
    {
        temp = first;
         printf("\nEnter the position of value to be deleted:");
        scanf(" %d", &pos);

        
        for( i = 1; i <pos-1; i++)
        {
            temp = temp -> next;
          
        }
        
        hold = temp ->next;
         printf("Deleted item  = %d", hold -> info);
        temp->next = hold->next;
        free(hold);


    }
    
}

/*
 * sum of all nodes(info) of linked list
 */
void infoSum(){
    NodeType *temp;
    int sum =0;
    temp =first;

    
    while(temp != NULL){
        sum += temp -> info;
        temp = temp -> next;
    }
    printf("\nTotal sum of nodes = %d\n",sum);
    
}

/*
 * count  all nodes(info) of linked list
 */
void countNodes()
{
    int count=0;
    NodeType *temp;
            while(temp != NULL){ //untill it reaches last i.e node[adress] =0 
            count++; // count every node untill temp pointer reaches to last
            temp = temp ->next;
            
        }
    printf("\nTotal nodes = %d\n",count);

}


/*
 * searching an element in a non-empty list
 */
void search()
{
    NodeType *temp;
    int flag = 0, key, pos = 0;
 
    if (first == NULL)
    {
        printf("\nNo nodes in the list\n");
    }
    else
    {
        printf("\nEnter the value to search : ");
        scanf("%d", &key);
        for (temp = first;temp != NULL;temp = temp->next)
        {
            pos = pos + 1;
            if (temp->info == key)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            printf("\nElement %d found at %d position\n", key, pos);
        }
        else
        {
            printf("\nElement %d not found in list\n", key);
        }
    }    
}


/*
 * display all element in a non-empty list
 */
void displayElements(){
    NodeType *temp;
   //store address of first(head) node of list
    
    if (first == NULL) { //if adress of head is 0
        printf("\n Linked list is empty.\n");
        exit(1);
    }
    
    else
    {
   printf("\n[ ");
        for (temp = first;temp != NULL;temp = temp->next)
        {    
            printf("%d\t", temp->info);
        }
        printf(" ]\n");
    }
    
    
}


int main(int argc, char const *argv[])
{
    int  item,ch;
    
        printf("\n---------------------------------\n");
        printf("\nOperations on singly linked list\n");
        printf("\n---------------------------------\n");
        printf("\n0.Make List Empty");
        printf("\n1.Insert node at first");
        printf("\n2.Insert node at last");
        printf("\n3.Insert node at position");
        printf("\n4.Delete first Node");
         printf("\n5.Delete last node");
        printf("\n6.Delete Node from any Position");
        printf("\n7.Sum of all data(info) of nodes");
        printf("\n8.Count no. of nodes");
        printf("\n9.Search Element in the linked list");
        printf("\n10.Display List from Beginning to end");
        printf("\n11.Exit\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    while(1){


        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        
        switch (ch)
        {
            case 0:
                createEmptyList();
                break;


            case 1:
              printf("Enter the item to be inserted : ");
              scanf("%d",&item);
              insertatBegin(item);
                break;


            case 2:
             printf("Enter the item to be inserted : ");
              scanf("%d",&item);
              insertatEnd(item);
                break;
   


            case 3:
             printf("Enter the item to be inserted : ");
                scanf("%d",&item);
                insertatgivenPosition(item);
                break;


            case 4:
              delteFirst();
                break;


            case 5:
              deleteLast();
                break;


            case 6:
              delete_nthNode();
                break;


            case 7:
              infoSum();
                break;


            case 8:
              countNodes();
                break;


            case 9:
              search();
                break;


            case 10:
                displayElements();


                break;

            case 11:
              exit(1);

        
            default:
                break;
        }
    }


    return 0;
}
