#include<stdio.h>

struct sample{
    int x;
    float y;
};


int main(void)[]
{
    typedef struct sample var;

    var s={1,2};
    printf("The value of x is : %d %f ", s.x, s.y);
    return 0;
}

