//Array of the numbers in array

#include<stdio.h>

float Sum(int a[], int n)
{
    int sum=0,i;
    for( i = 0; i < n; i++)
    {
        sum=sum+a[i];
    }

    return sum;
}

float Average(int x, int n)
{
    return(x/n);
}

int main()
{
    int arr[100];
    int n,i;
    float avg,sum;

    printf("Enter number of elements to be inserted: ");
    scanf("%d",&n);

    printf("\nEnter element one by one: \n");
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

     sum= Sum(arr,n);

    
    printf("Sum of array : %f\n\n",sum);


    avg =Average(sum,n);


    printf("Average of array : %f",avg);


}    