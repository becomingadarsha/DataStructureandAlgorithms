 #include<stdio.h>
 #include<stdlib.h>


int main()
{
 int a[10],b[10],c[20];
 int i,j=0,n1,n2;

 printf("How many elements of first array: \n ");
 scanf("%d",&n1);

 printf("Enter Array 1: \n");
 for(i=0;i<n1;i++)
 {
    scanf("%d",&a[i]);
 }


 printf("How many elements of second array: \n");
 scanf("%d",&n2);

 printf("Enter Array 2: \n");
 for(i=0;i<n2;i++)
 {
    scanf("%d",&b[i]);
 }


 for(i=0;i<n1;i++)
 {
       c[i] =a[i];

 }


  for(i=n1;i<=(n1+n2);i++)
  {
    c[i]=b[j];
    j++;
  }

    printf("\n\nMERGET SORT IS : \n\n");
    for(i=0;i<(n1+n2);i++)
    {
        printf("%d\n",c[i]);

    }

    return 0;
}
