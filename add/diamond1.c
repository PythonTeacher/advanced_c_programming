#include <stdio.h>

int main()
{
	int row, col, limit;	 /* �� ��ȣ, �� ��ȣ, �ִ� ��� ��ġ */

	printf("���ڸ� �Է����ּ��� : ");
	scanf("%d", &limit);

	/* ����� �ﰢ�� ��� */
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
	/* �ϴ��� ���ﰢ�� ��� */
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
