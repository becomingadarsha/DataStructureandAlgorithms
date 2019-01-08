#include<stdio.h>
#include<stdlib.h>
void insert(int,int,int,int a[]);

int main(){
    int a[10], len, i,pos,num;

    printf("Enter the size of array: ");
    scanf("%d",&len);

    printf("Enter numbers one by one :\n");

    for(i=0;i<len;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter position to be inserted: ");
    scanf("%d",&pos);

    printf("Enter value to be inserted: ");
    scanf("%d",&num);

    insert(num,pos,len,a);

          printf("Array after insertion\n");
    for(i=0;i<len;i++)
        printf("a[%d] = %d\n ",i,a[i]);

}



    void insert(int num, int pos, int len, int a[]){
 int i;
    if(pos>len){
    printf("\n\nPosition is more than length of array\n\n");
    }

    else
    {

        for(i=len;i>=pos;i--)
            {
                a[i+1]=a[i];
            }
                a[pos]=num;

    }
    len++;
    }
