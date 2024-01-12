#include <stdio.h>

int main (void)
{
	int i, j;
	int num;

	printf("정수를 입력하세요 : ");
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
