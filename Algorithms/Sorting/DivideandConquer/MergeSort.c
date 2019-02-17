#include <stdio.h>
#define size 100

void merge(int *arr, int beg, int mid, int end)
{
    int i = beg, j = mid + 1, index = beg, temp[size], k;
    while ((i <= mid) && (j <= end))
    {

        if (arr[i] < arr[j])
        {

            temp[index] = arr[i];

            i = i + 1;
        }
        else
        {

            temp[index] = arr[j];

            j = j + 1;
        }

        index = index + 1;
    }
    if (i > mid)
    {
        while (j <= end)
        {
            temp[index] = arr[j];

            j = j + 1;

            index = index + 1;
        }
    }
    else
    {
        while (i <= mid)
        {

            temp[index] = arr[i];

            i = i + 1;

            index = index + 1;
        }
    }
    for (k = beg; k < index; k++)
        arr[k] = temp[k];
}

void mergeSort(int *arr, int beg, int end)
{
    int mid;
    if (beg < end)
    {

        mid = (beg + end) / 2;

        mergeSort(arr, beg, mid);

        mergeSort(arr, mid + 1, end);

        merge(arr, beg, mid, end);
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

    printf("\n\nBefore Merge sort : \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\n\nAfter Merge sort : \n");
    printArray(arr, n);
    return 0;
}
