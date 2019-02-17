#include<stdio.h>


int Partition(int *arr, int start, int end)
{
    int i = start, j = end, pivot = arr[start];

    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
        {
            j--;
        }
        if (i < j)
        {
            arr[i++] = arr[j];
        }

        while (i < j && arr[i] < pivot)
        {
            i++;
        }
        if (i < j)
        {
            arr[j--] = arr[i];
        }
    }
    arr[i] = pivot;

    return i;
}


void QuickSort(int *arr, int start, int end)
{
    if (start == end)
    {
        return;
    }

    int index = Partition(arr, start, end);
    if (index > start)
    {
        QuickSort(arr, start, index);
    }

    if (index < end)
    {
        QuickSort(arr, index + 1, end);
    }
}




void printArray(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}





int main(int argc, char const *argv[])
{
    int arr[20], n;

    printf("Enter size of array : ");
    scanf("%d", &n);

    printf("Enter elements one by one :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n\nBefore Quick sort : \n");
    printArray(arr, n);

    QuickSort(arr, 0, n-1);

    printf("\n\nAfter Quick sort : \n");
    printArray(arr, n);
    return 0;
}
