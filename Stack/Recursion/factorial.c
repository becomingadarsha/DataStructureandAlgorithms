#include<stdio.h>

long fact(int n)
{
    if(n==0)
    {
        return 1;
    }

    
    else
    {
        return(n*fact(n-1));
    }
    
}

int main(void)
{
    int n;
    printf("Enter the number :");
    scanf("%d",&n)
    ;

    printf("The factorial of %d is %ld\n",n,fact(n));
    return 0;
}