
#include<stdio.h>
int main()
    {
        int a[10],b[10],c[20];
        int n1,n2;
        int i,j,k;

        printf("Enter size of array 1: \n");
        scanf("%d",&n1);

        printf("Enter elements of array 1: \n");
        for(i=0;i<n1;i++)
            scanf("%d",&a[i]);


        printf("Enter size of array 2:\n ");
            scanf("%d",&n2);


        printf("Enter elements of array 2: \n");
        for(j=0;j<n2;j++)
            scanf("%d",&b[j]);

        i=0;
        j=0;
        k=0;

        while(i<n1 && j<n2)
        {
            if(a[i]<b[j])
            {
                c[k]= a[i];
                i++;
                k++; 
            }
            
            else
            {
                c[k]=b[j];
                j++;
                k++;
            }

        }


        while(i<n1)
        {
            c[k] = a[i];
            i++;
            k++;
        }

        while(j<n2)
        {
            c[k] = b[j];
            j++;
            k++;
        }




        printf("\nMerged array after operations is :\n");
        for(i=0;i<(n1+n2);i++)
        {
            printf("%d\n",c[i]);
        }

        return 0;


    }


/* Comment 

Normal lauda O(nlogn) <- Time complexity

Maile lagakop algo lagauda chai O(n)
 Time complexity

*/