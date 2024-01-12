#include <stdio.h>

int main()
{
    int a[2][3] = {1,2,3,4,5,6};

    int (*p)[3] = a;
    int i, j;

    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
            printf("%d ", p[i][j]);
        puts("");
    }

    int *p1 = (int *)a;

    for(i=0; i<6; i++)
        printf("%d ",p1[i]);

    return 0;
}
