#include<stdio.h>

union DOB{
    int year,month,day;
};

union Details{
    int age;
    char *name;
    union DOB birth;
};

int main()
{

    union Details var;
    printf("Enter your name : ");
    scanf("%s",&var.name);

    printf("Enter your age: ");
    scanf("%d",&var.age);

    printf("Enter your year: ");
    scanf("%d %d %d",&var.birth.year,&var.birth.year,&var.birth.year,);
    
    printf("Name: %s",var.name);
    printf("/nAge: %d",var.age);

    printf("/n %d year %d month %d day",var.birth.year,var.birth.month,var.birth.day);

    return 0;
}