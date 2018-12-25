#include<stdio.h>
#include<stdlib.h>

struct DOB{
   int month,year;
   char *day;
};

struct Person{
        char name[20];
        int height;
        struct DOB birth;
};


void displayPerson(struct Person obj)
{
    printf("Enter your name and height: ");
    scanf("%s %d",&obj.name,&obj.height);

    printf("Name : %s\n",obj.name);
    printf("Height : %d\n",obj.height);

    obj.birth.month =2;
    obj.birth.year =1980;
    obj.birth.day="Monday";

    printf("\nDate of birth:\n");
    printf("Year : %d",obj.birth.year);
    printf(" Month : %d",obj.birth.month);
    printf(" Day : %s",obj.birth.day);

}


int main()
{
    struct Person obj;
    displayPerson(obj);
}