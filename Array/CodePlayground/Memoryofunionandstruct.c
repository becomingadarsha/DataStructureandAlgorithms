#include<stdio.h>

struct Student{
    char name[20];
    int roll_no;
};

union Employee{
    char name[20];
    int roll_no;
};

int main()
{   
    struct Student stu; 
    union Employee emp;
    printf("Size of Union is %d\n",sizeof(emp));
    printf("Size of Structure is %d",sizeof(stu));
}