#include <stdio.h>

int main()
{
    int num, i, j;
    printf("정수 입력 : ");
    scanf("%d", &num);

    for(i=0; i<num; i++)
    {
        for(j=1; j<=i; j++)
            printf("A");
        printf("B\n");
    }
    return 0;
}
