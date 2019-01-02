// WAP to print the fibonacci series


#include<stdio.h>

int Fibonacci(int n)
{
    if(n ==1 || n==2)
    {
        return 1;
    }
    
    else
    {
        return(Fibonacci(n-1) + Fibonacci(n-2));
    }
    
}


int main(void)
{
    int n,i;

    printf("How many number ? ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("%d\t",Fibonacci(i));
        printf("\n");
    }

    return 0;
}