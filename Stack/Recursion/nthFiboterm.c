//Find nth term of Fibonacci series using recursion

#include<stdio.h>

int Fibo(int n)
{
    if(n==1 || n==2)
    {
        return 1;
    }

    else
    {
        return Fibo(n-1) + Fibo(n-1);
    }
    
}

int main(void)
{
    int n;
    printf("Enter value of n : \n");
    scanf("%d",&n);

    printf("nth term of Fibonacci series : %d\n",Fibo(n));

    return 0;
}