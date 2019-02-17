#include <stdio.h>

void insertionSort(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
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

    printf("\n\nBefore Insertion sort : \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("\n\nAfter Insertion sort : \n");
    printArray(arr, n);
    return 0;
}
