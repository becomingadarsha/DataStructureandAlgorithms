#include<stdio.h>
#include<string.h>

void displayResult(stu)
{
    printf("Name is %s and roll no is %d",stu.name, stu.roll_no);
}
struct Student {
    int roll_no;
    char name[20];

};




int main()
{
  struct Student stu;

    printf("Type your name.. ");
    scanf("%s",&stu.name);
    
    printf("Type your roll no.. ");
    scanf("%d",&stu.roll_no);

    displayResult(stu);

}
