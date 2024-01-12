#include <stdio.h>

int main()
{
	int i, j, num;

	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	// 상단 삼각형 출력
	for(i=1; i<=num; i++)
    {
        for(j=1; j<=i; j++)
            printf("*");
        printf("\n");
    }

    // 하단 삼각형 출력
    for(i=1; i<=num; i++)
    {
        // Space 출력
        for(j=1; j<=num; j++)
            printf(" ");
        // 삼각형 출력
        for(j=1; j<i; j++)
            printf(" ");
        for(j=1; j<=num-i+1; j++)
            printf("*");
        printf("\n");
    }

	return 0;
}
