#include <stdio.h>

int main()
{
    int num, i;

    printf("��� �Է� : ");
    scanf("%d", &num);

    for(i=1; i<=num; i++)
    {
        printf("*");
        if(i % 5 == 0) printf("\n");
    }
}
