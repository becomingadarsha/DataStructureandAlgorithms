#include<stdio.h>


void Bubblesort(int *arr,int size)
{
    int temp;
  // Pass over the list (size - 1) times
  for(int i = 0; i < size-1; i++) {
    // in every pass, compare all adjacent items
    // swap them if in wrong order
    for(int j = 0; j < size - 1; j++) {
      if(arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; ++i){
           printf("%d\t",arr[i]);
    }
     
}


int main(int argc, char const *argv[])
{
    int arr[20], n;

    printf("Enter size of array : ");
    scanf("%d",&n);

    printf("Enter elements one by one :\n");
    for(int i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
    }

    printf("\n\nBefore Bubble sort : \n");
    printArray(arr,n);

    Bubblesort(arr, n);

    printf("\n\nAfter Bubble sort : \n");
    printArray(arr,n);
     return 0;
}

