#include <stdio.h>


void selectionSort(int *arr, int length) {
	int i;
	int iMin;
	int j;
	int temp;

//  iMin = smallestIndex, i = index, location =j


/* a[0] to a[n-1] is the array to sort */
	for (i = 0; i < length - 1; i++) {
		// step a (find smallest element)

		iMin = i;  /* assume the min is the first element */
		
        for (j = i + 1; j < length; j++) { /* test against elements after j to find the smallest */
			/* if this element is less, then it is the new minimum */
            if (arr[j] < arr[iMin]) {
                  /* found new minimum; remember its index */
				iMin = j;
			}
		}
		// step b (swap elements)
		temp = arr[iMin]; //swap(a[j], a[iMin]);
		arr[iMin] = arr[i];
		arr[i] = temp;
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

    printf("\n\nBefore Selection sort : \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\n\nAfter Selection sort : \n");
    printArray(arr, n);
    return 0;
}
