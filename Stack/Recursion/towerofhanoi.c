#include<stdio.h>

void TOH(int n, char A, char B, char C)
{
    if(n>0)
    {
        // suppose A -> Source, B-> Temp , C-> Spare

        TOH(n-1, A, C, B);
        /*since one disk is always permanent we take  n-1 disk ,
            move from A to B at first using C as the mediator.
        */

        printf("Move disk %d from %c to %c\n",n,A,B);
        TOH(n-1, C, B, A);
        /* again move from B to C using*/
    }

}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter number of disks : ");
    scanf("%d",&n);

    TOH(n,'O','D','I');

    return 0;
}