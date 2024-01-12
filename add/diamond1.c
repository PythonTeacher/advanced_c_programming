#include <stdio.h>

int main()
{
	int row, col, limit;	 /* 줄 번호, 열 번호, 최대 출력 위치 */

	printf("숫자를 입력해주세요 : ");
	scanf("%d", &limit);

	/* 상단의 삼각형 출력 */
	for(row = 1; row <= limit; row++)	{
		for(col = limit - row; col > 0; col--)
			printf(" ");
		for(col = 1; col < row*2; col++)	{
			if(col==1 || col==(row*2)-1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	/* 하단의 역삼각형 출력 */
	for(row = limit - 1; row > 0; row--)
	{
		for(col = limit - row; col > 0; col--)
			printf(" ");
		for(col = 1; col < row*2; col++)
		{
			if(col==1 || col==(row*2)-1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
