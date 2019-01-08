#include<stdio.h>

int main()
{
int a[100], pos, i;

printf(“Enter no of elements to be inserted”);
scanf(“%d”, &n);
printf(“Enter %d elements”, n);
for(i=0;i<n;i++)
{
scanf(“%d”, &a[i]);
}
printf(“Enter position at which you want to delete an element”);
scanf(“%d”, &pos);
for(i=pos; i<n; i++)
{
a[i] = a[i+1];
}
n--;
printf(”New array is:\n”);
for(i=0; i<n; i++)
{
printf(“%d\t”, a[i]);
}
}