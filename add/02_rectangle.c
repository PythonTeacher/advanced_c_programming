#include <stdio.h>

int main (void)
{
	int i, j;
	int num;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &num);  // 7

	for(i=1; i<=num; i++)
    {
        for(j=1; j<=num; j++)
        {
            if(i >= j)
                printf("%d", j);
            else
                printf("*");
        }
        printf("\n");
	}

	return 0;
}
