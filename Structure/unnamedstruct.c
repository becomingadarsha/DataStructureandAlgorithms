#include<stdio.h>

union Test{
    union
    {
    char name[100];
    int roll_no;
    };
};

typedef union Test test;
extern 
int main()
{
    test var;
    printf("Enter name : ");
    scanf("%s",&var.name);
}